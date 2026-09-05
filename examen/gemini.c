/*
 * Sistema de registro de ciclismo.
 *
 * Este programa administra hasta 20 ciclistas, genera sus tiempos de
 * entrenamiento, consulta su rendimiento y conserva la información básica
 * en archivos de texto.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Representa una fecha de nacimiento mediante sus componentes numéricos.
 */
typedef struct{
    int dia;
    int mes;
    int year;
} Nacimiento;

/*
 * Agrupa la información personal y deportiva de un ciclista.
 * El récord corresponde al menor tiempo registrado entre sus entrenamientos.
 */
typedef struct{
    char nombre[25];
    Nacimiento fecha;
    char telefono[11];
    int entrenamientos[12];
    int record;
} Ciclista;

/*
 * Calcula la longitud visual de un texto UTF-8 para alinearlo en tablas.
 *
 * Parámetros:
 * - texto: cadena cuya longitud se desea obtener.
 *
 * Resultado:
 * - Número de caracteres visibles en la cadena.
 */
int longitud_texto(const char *texto){
    int longitud = 0;
    
    while (*texto) {
        if ((*texto & 0xC0) != 0x80){
            longitud++;
        }
        texto++;
    }
    return longitud;
}

/*
 * Imprime una cadena centrada dentro de un espacio con ancho definido.
 *
 * Parámetros:
 * - texto: contenido que se mostrará.
 * - ancho: número de caracteres disponibles para la alineación.
 */
void imprimir_centrado(const char *texto, int ancho){
    int espacios = ancho - longitud_texto(texto);
    int izquierda = espacios / 2;
    int derecha = espacios - izquierda;

    if (izquierda < 0){
        izquierda = 0;
    }
    if (derecha < 0){
        derecha = 0;
    }
    printf("%*s%s%*s", izquierda, "", texto, derecha, "");
}

/*
 * Descarta los caracteres pendientes de la entrada estándar.
 * Se utiliza después de lecturas numéricas para permitir capturar texto
 * completo con fgets.
 */
void limpiar_buffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF){}
}

/*
 * Genera los 12 tiempos de entrenamiento de un ciclista y determina su récord.
 *
 * Parámetros:
 * - c: apuntador al ciclista que recibirá los tiempos y el mejor resultado.
 */
void generar_tiempos_y_record(Ciclista *c){
    int min_record = 241;

    for (int i = 0; i < 12; i++){
        c->entrenamientos[i] = 120 + rand() % 121;
        if (c->entrenamientos[i] < min_record){
            min_record = c->entrenamientos[i];
        }
    }
    c->record = min_record;
}

/*
 * Carga los ciclistas almacenados en datos.txt.
 * Por cada registro válido, genera nuevamente sus entrenamientos y récord.
 *
 * Parámetros:
 * - equipo: arreglo que almacenará los ciclistas cargados.
 * - num_ciclistas: apuntador al contador de registros existentes.
 */
void cargar_datos(Ciclista equipo[], int *num_ciclistas){
    FILE *archivo = fopen("datos.txt", "r");
    
    if (archivo != NULL){
        char bufer[60];
        int lectura_correcta;

        while (*num_ciclistas < 20 && fgets(bufer, sizeof(bufer), archivo) != NULL){
            bufer[strcspn(bufer, "\r\n")] = '\0';

            if (strlen(bufer) >= sizeof(equipo[*num_ciclistas].nombre)){
                fgets(bufer, sizeof(bufer), archivo);
                fgets(bufer, sizeof(bufer), archivo);
            }
            else{
                strcpy(equipo[*num_ciclistas].nombre, bufer);

                if (fgets(bufer, sizeof(bufer), archivo) != NULL){
                    lectura_correcta = sscanf(
                        bufer,
                        "%d %d %d",
                        &equipo[*num_ciclistas].fecha.dia,
                        &equipo[*num_ciclistas].fecha.mes,
                        &equipo[*num_ciclistas].fecha.year);
                    if (lectura_correcta == 3){
                        if (fgets(bufer, sizeof(bufer), archivo) != NULL){
                            bufer[strcspn(bufer, "\r\n")] = '\0';

                            if (strlen(bufer) < sizeof(equipo[*num_ciclistas].telefono)){
                                strcpy(equipo[*num_ciclistas].telefono, bufer);
                                generar_tiempos_y_record(&equipo[*num_ciclistas]);
                                (*num_ciclistas)++;
                            }
                        }
                    }
                }
            }
        }
        fclose(archivo);
    }
}

/*
 * Solicita los datos personales de un nuevo ciclista y lo incorpora al equipo.
 * La función evita registrar más de 20 participantes.
 *
 * Parámetros:
 * - equipo: arreglo de ciclistas registrado por el sistema.
 * - num_ciclistas: apuntador al número actual de ciclistas.
 */
void alta_ciclista(Ciclista equipo[], int *num_ciclistas){
    if (*num_ciclistas < 20)
    {
        limpiar_buffer();

        printf("\nIngrese los datos del nuevo ciclista.\n- Nombre (max. 24 caracteres): ");
        fgets(equipo[*num_ciclistas].nombre, sizeof(equipo[*num_ciclistas].nombre), stdin);
        equipo[*num_ciclistas].nombre[strcspn(equipo[*num_ciclistas].nombre, "\r\n")] = '\0';

        printf("- Fecha de nacimiento (<dd mm yyyy>): ");
        scanf(
            "%d %d %d",
            &equipo[*num_ciclistas].fecha.dia,
            &equipo[*num_ciclistas].fecha.mes,
            &equipo[*num_ciclistas].fecha.year);

        limpiar_buffer();

        printf("- Numero telefonico (10 digitos): ");
        fgets(equipo[*num_ciclistas].telefono, sizeof(equipo[*num_ciclistas].telefono), stdin);
        equipo[*num_ciclistas].telefono[strcspn(equipo[*num_ciclistas].telefono, "\r\n")] = '\0';

        generar_tiempos_y_record(&equipo[*num_ciclistas]);
        (*num_ciclistas)++;

        printf("Registro de ciclista exitoso!\n");
    }
    else{
        printf("\nLimite maximo de ciclistas (20) alcanzado.\n");
    }
}

/*
 * Muestra una tabla con los datos personales, récord y entrenamientos
 * de todos los ciclistas registrados.
 *
 * Parámetros:
 * - equipo: arreglo de ciclistas que se desea desplegar.
 * - num_ciclistas: cantidad de elementos válidos del arreglo.
 */
void desplegar_informacion(Ciclista equipo[], int num_ciclistas){
    const char *meses[13] = {
        "",
        "enero",
        "febrero",
        "marzo",
        "abril",
        "mayo",
        "junio",
        "julio",
        "agosto",
        "septiembre",
        "octubre",
        "noviembre",
        "diciembre"};

    char fecha[40];
    char fila_entrenamientos[30];
    char record_str[10];

    printf("\n┌─────────────────────────┬─────────────────────────┬────────────┬────────┬───────────────────┐\n");
    printf("│          Nombre         │       Nacimiento        │  Telefono  │ Record │   Entrenamientos  │\n");
    printf("├─────────────────────────┼─────────────────────────┼────────────┼────────┼───────────────────┤\n");

    for (int i = 0; i < num_ciclistas; i++)
    {
        snprintf(
            fecha,
            sizeof(fecha),
            "%d de %s de %d",
            equipo[i].fecha.dia,
            meses[equipo[i].fecha.mes],
            equipo[i].fecha.year);

        int hrs = equipo[i].record / 60;
        int mins = equipo[i].record % 60;

        snprintf(record_str, sizeof(record_str), "%d:%02d", hrs, mins);

        snprintf(
            fila_entrenamientos,
            sizeof(fila_entrenamientos),
            "%3d %3d %3d %3d",
            equipo[i].entrenamientos[0],
            equipo[i].entrenamientos[1],
            equipo[i].entrenamientos[2],
            equipo[i].entrenamientos[3]);

        printf("│                         │                         │            │        │");
        imprimir_centrado(fila_entrenamientos, 19);
        printf("│\n│");

        imprimir_centrado(equipo[i].nombre, 25);
        printf("│");

        imprimir_centrado(fecha, 25);
        printf("│");

        imprimir_centrado(equipo[i].telefono, 12);
        printf("│");

        imprimir_centrado(record_str, 8);
        printf("│");

        snprintf(
            fila_entrenamientos,
            sizeof(fila_entrenamientos),
            "%3d %3d %3d %3d",
            equipo[i].entrenamientos[4],
            equipo[i].entrenamientos[5],
            equipo[i].entrenamientos[6],
            equipo[i].entrenamientos[7]);

        imprimir_centrado(fila_entrenamientos, 19);
        printf("│\n│                         │                         │            │        │");

        snprintf(
            fila_entrenamientos,
            sizeof(fila_entrenamientos),
            "%3d %3d %3d %3d",
            equipo[i].entrenamientos[8],
            equipo[i].entrenamientos[9],
            equipo[i].entrenamientos[10],
            equipo[i].entrenamientos[11]);

        imprimir_centrado(fila_entrenamientos, 19);
        printf("│\n");

        if (i < num_ciclistas - 1){
            printf("├─────────────────────────┼─────────────────────────┼────────────┼────────┼───────────────────┤\n");
        }
    }

    printf("└─────────────────────────┴─────────────────────────┴────────────┴────────┴───────────────────┘\n");
}

/*
 * Busca un ciclista por número telefónico y muestra su entrenamiento
 * con mayor duración.
 *
 * Parámetros:
 * - equipo: arreglo de ciclistas registrados.
 * - num_ciclistas: cantidad de elementos válidos del arreglo.
 */
void busqueda_peor(Ciclista equipo[], int num_ciclistas){
    char telefono[11];

    limpiar_buffer();

    printf("\nIngrese el numero telefonico del ciclista: ");
    fgets(telefono, sizeof(telefono), stdin);
    telefono[strcspn(telefono, "\r\n")] = '\0';

    int i = 0;
    int encontrado = 0;

    while (i < num_ciclistas && encontrado == 0){
        if (strcmp(equipo[i].telefono, telefono) == 0){
            encontrado = 1;

            int peor_tiempo = -1;
            int peor_sesion = -1;

            for (int j = 0; j < 12; j++){
                if (equipo[i].entrenamientos[j] > peor_tiempo){
                    peor_tiempo = equipo[i].entrenamientos[j];
                    peor_sesion = j + 1;
                }
            }

            printf(
                "\nEl peor tiempo de %s fue de %d minutos en el entrenamiento %d\n",
                equipo[i].nombre,
                peor_tiempo,
                peor_sesion);
        }

        i++;
    }

    if (encontrado == 0){
        printf("\nCiclista no encontrado.\n");
    }
}

/*
 * Determina el menor tiempo registrado entre todos los ciclistas
 * y los doce entrenamientos de cada participante.
 *
 * Parámetros:
 * - equipo: arreglo de ciclistas registrados.
 * - num_ciclistas: cantidad de elementos válidos del arreglo.
 */
void mejor_rendimiento(Ciclista equipo[], int num_ciclistas){
    if (num_ciclistas > 0){
        int mejor_tiempo = 241;
        int mejor_sesion = -1;
        int indice_mejor = -1;

        for (int i = 0; i < num_ciclistas; i++){
            for (int j = 0; j < 12; j++){
                if (equipo[i].entrenamientos[j] < mejor_tiempo){
                    mejor_tiempo = equipo[i].entrenamientos[j];
                    mejor_sesion = j + 1;
                    indice_mejor = i;
                }
            }
        }

        printf(
            "\nEl mejor tiempo global es de %d mins obtenido en el entrenamiento numero %d por %s\n",
            mejor_tiempo,
            mejor_sesion,
            equipo[indice_mejor].nombre);
    }
    else{
        printf("\nNo hay ciclistas registrados.\n");
    }
}

/*
 * Identifica la sesión en la que el equipo obtuvo el menor tiempo acumulado.
 *
 * Parámetros:
 * - equipo: arreglo de ciclistas registrados.
 * - num_ciclistas: cantidad de elementos válidos del arreglo.
 */
void mejor_sesion(Ciclista equipo[], int num_ciclistas){
    if (num_ciclistas > 0){
        int mejor_sesion_colectiva = -1;
        int menor_suma = 0;

        for (int j = 0; j < 12; j++){
            int suma_actual = 0;

            for (int i = 0; i < num_ciclistas; i++){
                suma_actual += equipo[i].entrenamientos[j];
            }

            if (mejor_sesion_colectiva == -1 || suma_actual < menor_suma){
                menor_suma = suma_actual;
                mejor_sesion_colectiva = j + 1;
            }
        }

        printf(
            "\nEl mejor entrenamiento colectivo fue el %d con un tiempo acumulado de %d mins\n",
            mejor_sesion_colectiva,
            menor_suma);
    }
    else{
        printf("\nNo hay ciclistas registrados.\n");
    }
}

/*
 * Genera salida.txt con el récord de cada ciclista y el tiempo récord
 * acumulado del equipo.
 *
 * Parámetros:
 * - equipo: arreglo de ciclistas registrados.
 * - num_ciclistas: cantidad de elementos válidos del arreglo.
 */
void generar_salida(Ciclista equipo[], int num_ciclistas){
    FILE *archivo = fopen("salida.txt", "w");

    if (archivo != NULL){
        int suma_records_mins = 0;

        for (int i = 0; i < num_ciclistas; i++){
            int hrs = equipo[i].record / 60;
            int mins = equipo[i].record % 60;

            fprintf( archivo,"%s %d:%02d\n", equipo[i].nombre, hrs, mins);

            suma_records_mins += equipo[i].record;
        }

        int total_hrs = suma_records_mins / 60;
        int total_mins = suma_records_mins % 60;

        fprintf(archivo, "Tiempo record del equipo: %d:%02d\n", total_hrs, total_mins);

        fclose(archivo);

        printf("\nArchivo 'salida.txt' generado exitosamente.\n");
    }
    else{
        printf("\nError al crear el archivo de salida.\n");
    }
}

/*
 * Guarda en datos.txt la información permanente de cada ciclista.
 * Los entrenamientos no se conservan porque se generan al iniciar el programa.
 *
 * Parámetros:
 * - equipo: arreglo de ciclistas registrados.
 * - num_ciclistas: cantidad de elementos válidos del arreglo.
 */
void guardar_datos(Ciclista equipo[], int num_ciclistas){
    FILE *archivo = fopen("datos.txt", "w");

    if (archivo != NULL){
        for (int i = 0; i < num_ciclistas; i++){
            fprintf(
                archivo,
                "%s\n%d %d %d\n%s\n",
                equipo[i].nombre,
                equipo[i].fecha.dia,
                equipo[i].fecha.mes,
                equipo[i].fecha.year,
                equipo[i].telefono);
        }

        fclose(archivo);

        printf("\nDatos guardados correctamente. Saliendo...\n");
    }
    else{
        printf("\nError al guardar los datos.\n");
    }
}

/*
 * Coordina el ciclo principal del programa: inicializa los datos,
 * presenta el menú y dirige cada opción al módulo correspondiente.
 *
 * Resultado:
 * - Devuelve 0 al finalizar correctamente.
 */
int main(){
    Ciclista equipo[20];
    int num_ciclistas = 0;
    int opcion = 0;
    int salir = 0;

    srand((unsigned)time(NULL));

    cargar_datos(equipo, &num_ciclistas);

    while (salir == 0){
        printf("\n ------------------------------ \n");
        printf(" ---| Registro de Ciclismo |--- \n");
        printf(" ------------------------------ \n");

        printf("\n1. Dar de alta un ciclista.\n");
        printf("2. Informacion de los participantes.\n");
        printf("3. Ciclista de menor rendimiento (buscar por telefono).\n");
        printf("4. Ciclista de mejor rendimiento global.\n");
        printf("5. Mejor sesion de entrenamiento grupal.\n");
        printf("6. Registro de records por ciclista (salida.txt).\n");
        printf("7. Salir del programa (guardar datos).\n");
        printf("\nSeleccione una opcion: ");

        if (scanf("%d", &opcion) == 1){
            switch (opcion){
            case 1:
                alta_ciclista(equipo, &num_ciclistas);
                break;
            case 2:
                desplegar_informacion(equipo, num_ciclistas);
                break;
            case 3:
                busqueda_peor(equipo, num_ciclistas);
                break;
            case 4:
                mejor_rendimiento(equipo, num_ciclistas);
                break;
            case 5:
                mejor_sesion(equipo, num_ciclistas);
                break;
            case 6:
                generar_salida(equipo, num_ciclistas);
                break;
            case 7:
                guardar_datos(equipo, num_ciclistas);
                salir = 1;
                break;
            default:
                printf("\nOpcion invalida, intente de nuevo.\n");
                break;
            }
        }
        else{
            limpiar_buffer();
            printf("\nOpcion invalida, intente de nuevo.\n");
        }
    }
    return 0;
}

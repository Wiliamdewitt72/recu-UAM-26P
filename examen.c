/* estructuras de datos para los ciclistas */

#include <stddef.h>
#include <stdio.h>
typedef struct {
  int dia;
  int mes;
  int year;
} Nacimiento;

typedef struct {
  char nombre[25];
  Nacimiento fecha;
  int telefono;
  int marcas[12];
} Ciclista;

int main() {
  int menu;
  do {
    printf("\n ------------------------------ \n ---| Registro de Ciclismo "
           "|--- \n ------------------------------ \n\n- Bienvenido el "
           "programa de registro y consulta de datos acerca de las carreras "
           "efectuadas por el EQUIPO DE CICLISMO 2026.\n \nA continuación se "
           "presentan las operaciones que tienes disponibles:\n \n");
    printf(
        "1. Dar de alta un ciclista.              <1>\n2. Información de los "
        "participantes      <2>\n3. Ciclista de menor rendimiento         "
        "<3>\n4. Ciclista de mejor rendimiento         <4>\n5. Mejor sesión de "
        "entrenamiento grupal  <5>\n6. Registro de records por ciclista      "
        "<6>\n7. Salir del programa (guardar datos)    <7>\n \n");
    switch (menu) {
    case 1:
      continue;
    case 2:
      continue;
    case 3:
      continue;
    case 4:
      continue;
    case 5:
      continue;
    case 6:
      continue;
    case 7:
      continue;
    default:
      continue;
    }
  } while (0);
}

void leer_datos() {}

void alta_ciclista() {
  Ciclista ciclista;

  // Limpieza de bufer
  // Lectura de datos

  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;

  printf("Ingrese los datos del nuevo ciclista.\n- Nombre (max. 50 caracteres): ");
  fgets(ciclista.nombre, 50, stdin);

  printf("- Fecha de nacimiento (<dd mm yyyy>, poner <ESPACE> ' ' entre números):");

  scanf("%d %d %d", &ciclista.fecha.dia, &ciclista.fecha.mes, &ciclista.fecha.year);

  while ((c = getchar()) != '\n' && c != EOF)
    ;

  printf("- Número telefonico (10 digitos): ");

  scanf("%d", &ciclista.telefono);

  // Escritura en base de datos
  FILE *archivo = fopen("datos.text", "a");

  fprintf(archivo, "%s\n%d %d %d\n%d", ciclista.nombre, ciclista.fecha.dia, ciclista.fecha.mes, ciclista.fecha.year, ciclista.telefono);
  fclose(archivo);

  printf("Registro de cilcista exitoso!\n");
  
}

void desplegar_informacion(){
  
}

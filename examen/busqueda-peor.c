#include <stdio.h>
#include <string.h>

void busqueda_peor()
{
    char telefono[11];
    char bufer[60];
    int fin = 0;
    int entrenamientos[12];

    printf("Ingrese el número telefonico del ciclista : ");
    fgets(telefono, 11, stdin);

    FILE *archivo = fopen("db.txt", "r");

    while ((fgets(bufer, 60, archivo) != NULL) && (fin == 0))
    {
        bufer[strcspn(bufer, "\n")] = '\0';
        if (strcmp(bufer, telefono) == 0)
        {
            sscanf(bufer, "%d %d %d %d %d %d %d %d %d %d %d %d",
                   &entrenamientos[0], &entrenamientos[1],
                   &entrenamientos[2], &entrenamientos[3],
                   &entrenamientos[4], &entrenamientos[5],
                   &entrenamientos[6], &entrenamientos[7],
                   &entrenamientos[8], &entrenamientos[9],
                   &entrenamientos[10], &entrenamientos[11]);

            int mayor = entrenamientos[0], posicion_mayor = 0;
            for (int i = 0; i < 12; i++)
            {
                if (entrenamientos[i] > mayor)
                {
                    mayor = entrenamientos[i];
                    posicion_mayor = i;
                }
                printf("Entrenamiento %d: %d minutos\n", i + 1, entrenamientos[i]);
            }
            printf("El ciclista tuvo peor tiempo de entrenamiento en la sesión %d con %d minutos.\n", posicion_mayor + 1, mayor);
            fin = 1;
        }
    }

    fclose(archivo);
}

int main()
{
    busqueda_peor();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *archivo = fopen("db.txt", "r");

  char bufer[60];
  char nombre[25];
  int dia, mes, year, telefono;

  char *meses[13] = {"",        "enero",     "febrero",  "marzo",  "abril",
                     "mayo",    "junio",     "julio",    "agosto", "septiembre",
                     "octubre", "noviembre", "diciembre"};

  int entrenamientos[12];

  while (fgets(bufer, 60, archivo) != NULL) {

    // Buscar salto de linea y reemplazar por fin de linea.
    bufer[strcspn(bufer, "\n")] = '\0';
    strcpy(nombre, bufer);

    if (fgets(bufer, 60, archivo) != NULL) {
      sscanf(bufer, "%d %d %d", &dia, &mes, &year);
    }

    if (fgets(bufer, 60, archivo) != NULL) {
      sscanf(bufer, "%d", &telefono);
    }

    if (fgets(bufer, 60, archivo) != NULL) {
             sscanf(bufer, "%d %d %d %d %d %d %d %d %d %d %d %d", &entrenamientos[0], &entrenamientos[1], &entrenamientos[2], &entrenamientos[3], &entrenamientos[4], &entrenamientos[5], &entrenamientos[6], &entrenamientos[7], &entrenamientos[8], &entrenamientos[9], &entrenamientos[10], &entrenamientos[11]);
    }

    // Imprimir datos
    // printf(" |                               |                              |           |\n");

    printf("| %s | %d de %s de %d | %d |", nombre, dia, meses[mes], year,
           telefono);
    for(int i = 0; i < 12; i++){
      printf("%d, ", entrenamientos[i]);
    }
    printf("|\n");
  }
}

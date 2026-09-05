#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longitud_texto(const char *texto)
{
  int longitud = 0;

  while (*texto)
  {
    if ((*texto & 0xC0) != 0x80)
      longitud++;

    texto++;
  }

  return longitud;
}

void imprimir_centrado(const char *texto, int ancho)
{
  int espacios = ancho - longitud_texto(texto);
  int izquierda = espacios / 2;
  int derecha = espacios - izquierda;

  printf("%*s%s%*s", izquierda, "", texto, derecha, "");
}

int main()
{
  FILE *archivo = fopen("db.txt", "r");

  char bufer[60];
  char nombre[26];
  char telefono[11];
  int dia, mes, year;

  char *meses[13] = {"", "enero", "febrero", "marzo", "abril",
                     "mayo", "junio", "julio", "agosto", "septiembre",
                     "octubre", "noviembre", "diciembre"};

  int entrenamientos[12];

  while (fgets(bufer, 60, archivo) != NULL)
  {
    bufer[strcspn(bufer, "\n")] = '\0';
    strcpy(nombre, bufer);

    if (fgets(bufer, 60, archivo) != NULL)
    {
      sscanf(bufer, "%d %d %d", &dia, &mes, &year);
    }

    if (fgets(bufer, 60, archivo) != NULL)
    {
      sscanf(bufer, "%10s", telefono);
    }

    if (fgets(bufer, 60, archivo) != NULL)
    {
      sscanf(bufer, "%d %d %d %d %d %d %d %d %d %d %d %d",
             &entrenamientos[0], &entrenamientos[1],
             &entrenamientos[2], &entrenamientos[3],
             &entrenamientos[4], &entrenamientos[5],
             &entrenamientos[6], &entrenamientos[7],
             &entrenamientos[8], &entrenamientos[9],
             &entrenamientos[10], &entrenamientos[11]);
    }

    char fecha[40];
    char fila_entrenamientos[20];
    char record[5] = "3:05";

    snprintf(fecha, sizeof(fecha), "%d de %s de %d",
             dia, meses[mes], year);

    printf("┌─────────────────────────┬─────────────────────────┬────────────┬────────┬───────────────────┐\n");
    printf("│          Nombre         │       Nacimiento        │  Teléfono  │ Record │   Entrenamientos  │\n");
    printf("├─────────────────────────┼─────────────────────────┼────────────┼────────┼───────────────────┤\n");

    snprintf(fila_entrenamientos, sizeof(fila_entrenamientos),
             "%3d %3d %3d %3d",
             entrenamientos[0], entrenamientos[1],
             entrenamientos[2], entrenamientos[3]);

    printf("│                         │                         │            │        │");
    imprimir_centrado(fila_entrenamientos, 19);
    printf("│\n");

    printf("│");
    imprimir_centrado(nombre, 25);
    printf("│");
    imprimir_centrado(fecha, 25);
    printf("│");
    imprimir_centrado(telefono, 12);
    printf("│");
    imprimir_centrado(record, 8);
    printf("│");

    snprintf(fila_entrenamientos, sizeof(fila_entrenamientos),
             "%3d %3d %3d %3d",
             entrenamientos[4], entrenamientos[5],
             entrenamientos[6], entrenamientos[7]);

    imprimir_centrado(fila_entrenamientos, 19);
    printf("│\n");

    snprintf(fila_entrenamientos, sizeof(fila_entrenamientos),
             "%3d %3d %3d %3d",
             entrenamientos[8], entrenamientos[9],
             entrenamientos[10], entrenamientos[11]);

    printf("│                         │                         │            │        │");
    imprimir_centrado(fila_entrenamientos, 19);
    printf("│\n");

    printf("└─────────────────────────┴─────────────────────────┴────────────┴────────┴───────────────────┘\n\n");
  }

  fclose(archivo);

  return 0;
}
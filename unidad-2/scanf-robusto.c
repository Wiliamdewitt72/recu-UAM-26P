/*Validación Robusta (scanf): Pide un año de nacimiento. Usa el retorno de scanf
 * dentro de un bucle para verificar si la entrada fue válida. Si falla, limpia
 * el buffer y vuelve a pedirlo. Salida esperada: Si el usuario teclea "Hola",
 * el programa imprime "Error, ingresa solo números:" y no colapsa.*/

#include <stdio.h>

int main() {
  int year, entrada = 0;

  printf("Introduzca el año de nacimiento: ");
  entrada = scanf("%d", &year);

  do {
    printf("Introduzca el año de nacimiento: ");
    entrada = scanf("%d", &year);
    if (entrada == 1) {
      printf("\nRegistro con exito, el año es: %d", year);
    } else if (entrada == 0) {
      printf("DATOS INCORRECTOS.\n");
      continue;
    }
  } while (1);
}

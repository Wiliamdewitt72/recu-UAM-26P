/*
La Conjetura de Collatz: Pide un entero positivo. Si es par, divídelo entre 2;
si es impar, multiplícalo por 3 y suma 1. Usa un while hasta que el número
llegue a 1. Salida esperada: Para 6, imprime "6, 3, 10, 5, 16, 8, 4, 2, 1" y
"Pasos totales: 8".
*/

#include <stdio.h>

int main() {
  unsigned long long numero = 0, mayor = 0;
  int pasos = 0;

  printf("Introduce un entero positivo: ");
  scanf("%llu", &numero);
  mayor = numero;
  do {
    if ((numero % 2) == 0) {
      numero = numero / 2;
    } else {
      numero = (numero * 3) + 1;
    }
    printf("-> %llu \n", numero);

    if (numero > mayor) {
      mayor = numero;
    }

    pasos++;

  } while (numero != 1);

  printf("El número ahora es: %llu\n", numero);
  printf("El máximo número alcanzado es: %llu\n", mayor);
  printf("El número de pasos es: %d", pasos);
  return 0;
}

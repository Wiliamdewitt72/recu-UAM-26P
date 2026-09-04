/*Raíces Cuadráticas: Pide coeficientes float para la ecuación ax^2 + bx + c =
 * 0. Calcula el discriminante. Si es negativo, avisa del error. Si es positivo
 * o cero, muestra las raíces. Salida esperada: Para 1, -3, 2 imprime
 * "Raíces: 2.00 y 1.00"*/

#include <stdio.h>

int main() {
  float a, b, c = 0;
  double raiz1, raiz2 = 0;
  printf(
      "Dame los coeficientes a, b, c de la ecuación cuadratica >> ax^2 + bx + "
      "c = 0 << \nPresiona <ENTER> para introducir el siguiente número\n -> ");
  scanf("%f", &a);
  printf(" -> ");
  scanf("%f", &b);
  printf(" -> ");
  scanf("%f", &c);

  float discriminante = (b * b) - (4 * a * c);
  if (discriminante < 0) {
    printf("\nERROR: No tiene soluciones reales.");
  } else {
    raiz1 = ((-1 * b) + __builtin_sqrt(discriminante)) / (2 * a);
    raiz2 = ((-1 * b) - __builtin_sqrt(discriminante)) / (2 * a);
    printf("\nRaices: \n R1: %0.2f \n R2: %0.2f ", raiz1, raiz2);
  }
}

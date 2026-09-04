/*Convertidor de Tiempo: Una función que reciba un número entero total de
 * segundos y, usando paso por referencia, devuelva al módulo principal cuántas
 * horas, minutos y segundos exactos conforman ese tiempo.*/

#include <stdio.h>

int convertidor(float tiempo, float registro[]) {
  registro[0] = tiempo / 360;      // minutos
  registro[1] = tiempo / 60; // horas
  registro[2] = tiempo;

  return 1;
}

int main() {
   float registro[3], segundos = 0;

   printf("Introduce los segundos: ");
   scanf("%f", &segundos);
   
   convertidor(segundos, registro);

   printf("\n Horas: %.2f, Minutos: %.2f, segundos: %.2f",registro[0], registro[1], registro[2]);
}

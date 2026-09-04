/*Crea void dividir(int dividendo, int divisor, int *cociente, int *residuo). Calcula ambos resultados en la función y modifícalos directamente por referencia en la memoria.*/

#include <stdio.h>

void dividir(int dividendo, int divisor, int *cociente, int *residuo){
  *cociente = dividendo / divisor;
  *residuo = dividendo % divisor;
}

int main(){
  int dividendo, divisor, cociente, residuo; 
  
  printf("Introduce dos números a dividir (diferentes de 0): ");
  scanf("%d %d", &dividendo, &divisor);

  dividir(dividendo, divisor, &cociente, &residuo);

  printf("La división entre %d y %d da como cociente: %d, y como residuo: %d", dividendo, divisor, cociente, residuo);
}


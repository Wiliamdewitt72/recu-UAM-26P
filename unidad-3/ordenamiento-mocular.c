/*Ordenamiento Modular: Diseña una función ordenar_tres(int *x, int *y, int *z) que utilice internamente a la función intercambiar() del Ejercicio 1 para dejar los tres números ordenados de menor a mayor en la RAM. */

#include <stdio.h>

void intercambiar(int *a, int *b){
  int cambio = *a;
  *a = *b;
  *b = cambio;
}

void ordenar_tres(int *x, int *y, int *z){
  int celdas[3] = {*x, *y, *z}, mayor, i = 0;
  while () {
    if((i + 1) > i){
      mayor = celdas[i + 1];
    } else {
      mayor = celdas[i];
    }
  }
}


int main(){
  
}


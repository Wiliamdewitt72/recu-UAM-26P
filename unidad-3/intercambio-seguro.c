/*Diseña el procedimiento void intercambiar(int *a, int *b). En tu main, pide dos variables, envíalas por referencia y demuestra imprimiéndolas que sus valores se invirtieron exitosamente. */
#include <stdio.h>

void intercambiar(int *a, int *b){
  int cambio;
  cambio = *a;
  *a = *b;
  *b = cambio;
}

int main() {
   int a, b;
   printf("Escribe dos números");
   scanf("%d %d", &a, &b);

   intercambiar(&a, &b);

   printf("\n Estos son los números : %d, %d", a, b);
   return 0;
 }



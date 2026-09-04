/*
Validador Lógico de Triángulos: Pide tres números float. Usa operadores
relacionales para verificar si pueden formar un triángulo (la suma de dos lados
cualesquiera siempre debe ser estrictamente mayor que el tercero). Salida
esperada: Para 3, 4, 5 imprime "Triángulo válido". Para 1, 2, 8 imprime
"Inválido".
*/

#include <stdio.h>

int main() {

  float A, B, C = 0;

  printf("Dame tres números (presiona <ENTER> para el siguiente número).\n");
  scanf("%f", &A);
  scanf("%f", &B);
  scanf("%f", &C);

  if (((A + B) > C) && ((B + C) > A) && ((C + A) > B)) {
    printf("Triangulo válido");
  } else {
    printf("Inválido");
  }
  
  return 0;
}

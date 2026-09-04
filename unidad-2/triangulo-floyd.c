/* Triángulo de Floyd: Pide un número de filas. Usa bucles anidados para imprimir números consecutivos. Salida esperada: Para 3, imprime la primera fila "1", la segunda "2 3", la tercera "4 5 6".*/

#include <stdio.h>

int main(){
  int filas, col = 1;
  printf("Escribe un número de filas y un número de columnas (presiona <ENTER> para introducir el número de columnas).\n Filas: ");
  scanf("%d", &filas);
  printf(" Columnas: ");
  scanf("%d", &col);
  int i, j, k = 1;
  for(i = 1; i <= filas; i++){
    for(j = 1; j <= col ;j++){
      printf(" %d ", k);
      k++;
    }
    printf("\n");
  }
  return 0;
}


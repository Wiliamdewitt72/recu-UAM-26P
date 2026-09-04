/*Copia de Seguridad Fiel: Abre original.txt en modo "r" y respaldo.txt en modo "w". Usa un bucle while con fgetc y fputc para copiar carácter por carácter hasta llegar al fin del archivo (EOF). */

#include <stdio.h>

// Basicamente este codigo copia de un lugar a otro todo el texto txt.
void copiar(FILE *original, FILE *copia){
  int c;
  while ((c = fgetc(original)) != EOF) {
    fputc(c, copia);
  }
}

int main(){
  FILE *original = fopen("original.txt", "r");
  FILE *copia = fopen("respaldo.txt", "w");

  copiar(original, copia);
}

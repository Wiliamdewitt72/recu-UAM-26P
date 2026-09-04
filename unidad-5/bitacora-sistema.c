/* Bitácora del Sistema (Append): Diseña void registrar_log(char *mensaje). Debe abrir historial.txt en modo "a", escribir el mensaje, un salto de línea y cerrarlo. Salida: Ejecútalo 3 veces; el archivo debe tener las 3 líneas sin borrar las anteriores.*/
#include <stdio.h>

void registrar_log(char *mensaje){
  // FILE es el tipo de dato. El segundo parametro de fopen() es "a" = append = "añadir al final".
  // Se hace FILE con un puntero porque fopen() devuelve la dirección de memoria donde vive el archivo.
  FILE *archivo = fopen("historial.txt", "a");
  int ok = 0;

  if (archivo == NULL){
    printf("No se pudo abrir el archivo. :(");
  } else {
    // fprintf() escribe toda la cadena dentro del archivo, según el modo en el que se abrió.
    ok = fprintf(archivo, "Una nueva linea\n");
    if (ok > 0){
      printf("Escritura hecha correctamente.");
    }
  }
}

int main(){
  registrar_log("hola");
  return 0;
}




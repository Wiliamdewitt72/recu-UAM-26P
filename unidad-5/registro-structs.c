/*Persistencia de Structs: Crea un arreglo de 3 struct de tipo "Empleado". Pide
 * sus datos por teclado y usa fprintf para guardarlos en plantilla.txt
 * separados por comas. */

#include <stdio.h>
typedef struct {
  int id;
  int number_employed;
  char name[25];
} Empleado;

int main() {
  // Así se declara un array de typedefs definidos.
  Empleado db[3] = {
      {1, 2, "Juan Carlos"},
      {2, 45, "Guillermo"},
      {3, 12, "David G."}}; //;  printf("Este es: %", db[0]);, no hay forma de
                            //imprimir todo el array o un struct a menos que
                            //recorramos campo por campo.

  // ------- Problema

  Empleado trabajo[3];

  printf("Introducir datos del empleado (<ID>, <Número de empleado>, "
         "<Nombre>): \n Introduzca los datos separados por comas.\n");
  for (int i = 0; i < 3; i++) {
    printf("\n ->");
    fscanf(stdin, "%d, %d, %24s", &trabajo[i].id, &trabajo[i].number_employed,
           trabajo[i].name);
  }
  printf("--- Los registros son: ---\n");
  for (int i = 0; i < 3; i++) {
    printf("-> %d, %d, %s \n", trabajo[i].id, trabajo[i].number_employed,
           trabajo[i].name);
  }

  return 0;
}

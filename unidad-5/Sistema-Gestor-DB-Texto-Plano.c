/* */

#include <stdio.h> // Para archivos (FILE, fopen, remove, rename), printf, scanf
#include <stdlib.h> // Para funciones del sistema
#include <string.h> // Para manejar cadenas de texto (strcspn)

// Plantilla de nuestro registro
typedef struct {
  int id;
  char nombre[50];
  float salario;
} Empleado;

void agregar_empleado() {
  Empleado empleado;

  printf("\n--- Añadir Empleado ---\nEscribir datos.\n- ID: ");
  scanf("%d", &empleado.id);

  // Limpieza del stdin
  int clean;
  while (((clean = getchar()) != '\n') && (clean != EOF));
  // Toma cada caracter que quede en el stdin y lo saca, hasta llegar al salto
  // de línea o el fin del documento (EOF)

  printf("- Nombre: ");
  fgets(empleado.nombre, 50, stdin);
  empleado.nombre[strcspn(empleado.nombre, "\n")] = '\0'; // Quitamos el salto de línea que captura fgets
    
  printf("- Salario: ");
  scanf("%f", &empleado.salario);

  // --- Editar archivos
  FILE *archivo = fopen("empleados.txt", "w");

  if (archivo == NULL) {
    printf("Error: No se pudo acceder al disco duro.\n");
    return;
  }

  fprintf(archivo, "%d,%s,%.2f\n", empleado.id, empleado.nombre,
          empleado.salario);

  fclose(archivo);
  printf("¡Empleado guardado exitosamente!\n");
}

int main(){
  agregar_empleado();
}

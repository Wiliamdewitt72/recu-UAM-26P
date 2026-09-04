/*Cajero Automático Restringido: Declara una variable de saldo inicial de 1000.
 * Usa un do while para un menú iterativo: 1) Retirar, 2) Depositar, 3) Salir.
 * Verifica que los retiros no superen el saldo. Salida esperada: Si intentas
 * retirar 1200, el sistema debe denegarlo y mostrar tu saldo actual intacto.*/

#include <stdio.h>

int main() {
  float saldo_inicial = 1000, retiro, deposito = 0;
  int opcion;

  do {
    printf("\n Opciones de transacción: \n 1) Retirar \n 2) Depositar \n 3) "
           "Salir \n -> ");
    scanf("%d", &opcion);
    switch (opcion) {
    case 1:
      printf("Ingrese el monto de retiro: ");
      scanf("%f", &retiro);
      if (retiro <= saldo_inicial) {
        saldo_inicial -= retiro;
        printf("Saldo actual: %0.2f", saldo_inicial);
      } else {
        printf("Monto de retiro mayor a saldo disponible. Intente otra vez.\n \n");
        continue;
      }
      continue;
    case 2:
      printf("Ingrese el monto de deposito: ");
      scanf("%f", &deposito);
      saldo_inicial += deposito;
      printf("Saldo actual: %0.2f", saldo_inicial);
      continue;
    case 3:
      break;
    }
  } while (opcion != 3);
  printf("\n Operación finalizada.");
  return 0;
}

/* Detector de Primos Optimizado: Pide un entero y usa un for para ver si es primo. Usa la sentencia break para romper el bucle inmediatamente si encuentras un divisor. Salida esperada: Para 97 imprime "Es primo". Para 15 imprime "No es primo, divisible por 3".*/

#include <stdio.h>

int main(){
  int numero; 
  printf("Introduce un número: ");
  scanf("%d", &numero);

  for(int i = 2; i <= numero; i++){
    if(numero == i){
      printf("El número es primo!");
      break;
    } else if ((numero % i) == 0){
      printf("El número no es primo!, es divisible por: %d", i);
      break;
    } else {
      continue;
    }
  }
  
}



## Arrays

Cuando se crea un array se reserva en memoria todo el espacio que vamos a necesitar.
Son accesibles a través del nombre del array y su posición. Comenzamos desde la posición 0, luego la 1, 2, 3, ...
Los arrays son fijos. 


Ejemplo

```C

```

## Vector

Todos los datos del vector son del mismo tipo.

```C
// TipoDeDato nombreDeArray[longitud]
int numeros[5];
```
Como asignar valores a un vector.

```C
float vector[] = {1,2,3,4}; // En este caso no se designo el tamaño desde un inicio pero C calcula automaticamente el tamaño. 
```
También se pueden asignar valores a espacios de un vector apuntando directamente a ese espacio, por ejemplo: 
```C
vecto[0] = 3.5 // el valor cambia de 1 -> 3.5
```
Así se modelan las palabras, por ejemplo: 
```C
char palabra[5] = {'H', 'o', 'l', 'a'}; // Al final se asigna automaticamente el fin de linea \0.
```

## Matrices

De dos dimensiones
```C
float ingresos[2][2]; // [fila][columna]
```







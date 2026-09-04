# Introducción a la Programación en C — Manual Exhaustivo para Examen

> **Base del manual**
>
> Este documento está construido tomando como columna vertebral el programa de estudios de **Introducción a la Programación (clave 2151063)** de la UAM Iztapalapa y contrastándolo con los materiales de preparación que has trabajado: conceptos básicos, elementos de un lenguaje, diseño de programas, estructuras de datos básicas y manejo de archivos.
>
> El programa oficial cubre cinco unidades: **1) Conceptos básicos, 2) Elementos de un lenguaje de programación, 3) Diseño de programas, 4) Estructuras de datos básicas y 5) Manejo básico de archivos.**  
> Las ampliaciones de punteros, `typedef`, `struct`, `enum`, cabeceras, `extern`, operaciones bit a bit, punteros a funciones y funciones de biblioteca se incluyen para darte la profundidad práctica que pediste.
>
> **Convención:** cuando aparezca `⚠️`, es una trampa frecuente de examen o una precisión importante.

---

# Índice

1. Cómo pensar un problema de programación
2. Unidad 1 — Conceptos básicos
3. Unidad 2 — Elementos de un lenguaje de programación
4. Unidad 3 — Diseño de programas
5. Unidad 4 — Estructuras de datos básicas
6. Unidad 5 — Manejo básico de archivos
7. Cabeceras, compilación, `extern` y proyectos con varios `.c`
8. Tabla de operadores y símbolos de C
9. Tipos de datos de C, tamaños, rangos y memoria
10. Cadenas de texto
11. Funciones: contratos, parámetros y valores de retorno
12. Punteros en profundidad
13. `struct`, `typedef`, `enum` y `union`
14. Arrays, vectores y matrices en profundidad
15. Entrada por teclado y `scanf`
16. Biblioteca estándar más útil
17. Errores y trampas de examen
18. Patrones de algoritmos
19. 20 problemas tipo examen, con solución completa
20. Checklist final para el examen

---

# 0. Cómo pensar un problema de programación

Antes de pensar en C, separa el problema en:

```text
ENTRADA → PROCESAMIENTO → SALIDA
```

Ejemplo:

> “Lee 10 números y muestra el mayor.”

### Entrada
10 números enteros.

### Estado interno
Un arreglo de 10 elementos o, si no necesitamos conservarlos, una sola variable `max`.

### Procesamiento
Comparar cada número contra el máximo actual.

### Salida
El máximo.

---

## 0.1. Del problema al algoritmo

Nunca empieces con:

```c
#include <stdio.h>
int main() {
    ...
}
```

Empieza preguntándote:

1. ¿Qué datos entran?
2. ¿Qué datos tengo que conservar?
3. ¿Qué transformación se necesita?
4. ¿Qué casos especiales existen?
5. ¿Cuál es la condición de terminación?
6. ¿Qué tiene que salir exactamente?

Después escribe pseudocódigo:

```text
LEER n
max ← primer valor

PARA cada valor restante
    SI valor > max
        max ← valor

MOSTRAR max
```

Y sólo entonces lo conviertes a C.

---

# UNIDAD 1 — CONCEPTOS BÁSICOS

---

## 1.1. Modelo de Von Neumann

La idea fundamental del modelo es el **programa almacenado**: las instrucciones y los datos pueden residir en la memoria principal.

### Componentes conceptuales

| Componente | Función |
|---|---|
| CPU | Ejecuta instrucciones |
| ALU | Operaciones aritméticas y lógicas |
| Unidad de Control | Coordina la ejecución |
| RAM | Almacena temporalmente datos e instrucciones |
| Entrada/Salida | Comunicación con usuario/dispositivos |
| Buses | Transportan datos, direcciones y señales |

### Analogía

Imagina una cocina:

- RAM = la mesa donde están los ingredientes e instrucciones.
- CPU = el cocinero.
- ALU = sus manos/calculadora.
- Unidad de Control = la receta que indica qué hacer.
- Disco = la despensa.
- I/O = puerta por donde entran y salen cosas.

---

## 1.2. RAM contra almacenamiento secundario

La RAM es memoria de trabajo.

Un archivo `.txt` que vive en disco **no es una variable C**.

Cuando un programa abre el archivo, el sistema gestiona una interacción entre el almacenamiento y la memoria.

Una variable como:

```c
int x = 42;
```

representa almacenamiento para el objeto `x` durante su tiempo de vida.

---

## 1.3. Qué es un algoritmo

Un algoritmo es un procedimiento finito, preciso y definido para resolver un problema.

### Propiedades que debes reconocer

- **Finito:** termina.
- **Preciso:** cada paso está claramente especificado.
- **Definido:** ante las mismas entradas válidas, sigue el mismo procedimiento y produce el resultado correspondiente.

### Ejemplo

Problema:

> Saber si un número es par.

Algoritmo:

```text
1. Leer n.
2. Calcular n % 2.
3. Si el resultado es 0, es par.
4. Si no, es impar.
```

---

## 1.4. Pseudocódigo

Sirve para diseñar la solución antes de casarte con la sintaxis de C.

Ejemplo:

```text
INICIO
    LEER n

    SI n > 0 ENTONCES
        MOSTRAR "positivo"
    SINO
        SI n < 0 ENTONCES
            MOSTRAR "negativo"
        SINO
            MOSTRAR "cero"
        FIN SI
    FIN SI
FIN
```

---

## 1.5. Diagramas de flujo

Símbolos clásicos:

| Símbolo conceptual | Uso |
|---|---|
| Óvalo | Inicio / fin |
| Rectángulo | Proceso |
| Rombo | Decisión |
| Paralelogramo | Entrada / salida |
| Flechas | Flujo |

No memorices sólo la figura: entiende la función lógica.

---

## 1.6. Sistema operativo

El sistema operativo administra recursos como:

- memoria;
- CPU;
- dispositivos;
- archivos;
- entrada/salida.

Cuando un programa utiliza entrada/salida, existe una interacción con el sistema operativo y con los dispositivos.

---

## 1.7. Compilador, intérprete y depurador

### Compilador

Traductor que transforma código fuente de C en código objeto y participa en la creación del ejecutable.

Una vista simplificada:

```text
main.c
   ↓
preprocesamiento
   ↓
compilación
   ↓
main.o
   ↓
ligado
   ↓
programa ejecutable
```

### Intérprete

Ejecuta el programa a través de un sistema que interpreta instrucciones en tiempo de ejecución.

⚠️ No conviertas esto en la regla absoluta “Python jamás compila”. Los lenguajes pueden tener varias implementaciones y etapas. Para el nivel de este curso importa reconocer la diferencia conceptual.

### Depurador

Permite:

- breakpoint;
- ejecución paso a paso;
- inspección de variables;
- inspección del flujo;
- localización de errores.

---

# UNIDAD 2 — ELEMENTOS DE UN LENGUAJE DE PROGRAMACIÓN

---

# 2.1. Datos

Un programa opera sobre valores.

Ejemplos:

```c
42
3.14159
'A'
"Hola"
```

No todos significan lo mismo:

- `42` → constante entera;
- `3.14159` → constante de tipo flotante;
- `'A'` → constante de carácter;
- `"Hola"` → literal de cadena.

---

# 2.2. Identificadores

Un identificador es el nombre de una entidad del programa:

```c
int edad;
float precio;
int calcular_total(void);
```

Reglas generales:

- puede contener letras, dígitos y `_`;
- no puede empezar por un dígito;
- distingue mayúsculas/minúsculas;
- no puede coincidir con una palabra reservada.

Ejemplos válidos:

```c
contador
contador2
_total
temperatura_celsius
```

Ejemplos inválidos:

```c
2contador
float
int
mi-variable
```

---

# 2.3. Variables

Sintaxis:

```c
tipo nombre;
```

Inicializada:

```c
tipo nombre = valor;
```

Ejemplos:

```c
int edad = 23;
float temperatura = 36.5f;
char inicial = 'D';
double pi = 3.141592653589793;
```

### Variable ≠ valor

Cuando haces:

```c
int x = 10;
```

tienes:

- un objeto llamado `x`;
- tipo `int`;
- almacenamiento suficiente para representar un `int`;
- valor actual `10`.

---

# 2.4. Mutabilidad y `const`

C permite modificar objetos que no fueron declarados `const`.

```c
int x = 10;
x = 20;
```

Con `const`:

```c
const int MAX = 100;
```

esto impide modificar el objeto a través de ese identificador:

```c
MAX = 200; // error
```

⚠️ `const` no significa “todo lo relacionado jamás puede cambiar”. Significa que **ese objeto no puede modificarse mediante una expresión que viole su constancia**.

---

# 2.5. `#define` y macros

`#define` pertenece al **preprocesador**.

```c
#define MAX_ALUMNOS 30
```

Antes de que el compilador analice la unidad de traducción, el preprocesador realiza sustituciones macro.

### Macro de función

```c
#define CUADRADO(x) ((x) * (x))
```

Uso:

```c
int x = CUADRADO(5);
```

Expansión conceptual:

```c
int x = ((5) * (5));
```

⚠️ Una macro no es una función.

Problema clásico:

```c
#define CUADRADO(x) x * x

int a = CUADRADO(2 + 3);
```

Puede expandirse como:

```c
int a = 2 + 3 * 2 + 3;
```

que no significa `25`.

Forma robusta:

```c
#define CUADRADO(x) ((x) * (x))
```

Aun así, una macro puede evaluar su argumento más de una vez:

```c
CUADRADO(i++)
```

es peligrosa.

---

# 2.6. Constantes literales

### Enteros

```c
10
-20
0
```

### Flotantes

```c
3.14
3.14f
```

La `f` hace que el literal sea de tipo `float`.

### Caracteres

```c
'A'
'\n'
'\0'
'\t'
```

Un carácter usa comillas simples.

### Cadenas

```c
"Hola"
```

Una cadena usa comillas dobles.

---

# 2.7. Operadores

## Aritméticos

| Operador | Significado | Ejemplo |
|---|---|---|
| `+` | suma | `a + b` |
| `-` | resta | `a - b` |
| `*` | multiplicación | `a * b` |
| `/` | división | `a / b` |
| `%` | residuo entero | `a % b` |

⚠️ `%` no significa porcentaje. Es el **operador módulo**.

```c
17 % 5   // 2
```

---

# 2.8. División entera

```c
5 / 2
```

si ambos operandos son enteros:

```text
2
```

No:

```text
2.5
```

Para obtener división real:

```c
5.0 / 2
```

o:

```c
(float)5 / 2
```

---

# 2.9. Operadores relacionales

| Operador | Significado |
|---|---|
| `==` | igual |
| `!=` | diferente |
| `<` | menor |
| `>` | mayor |
| `<=` | menor o igual |
| `>=` | mayor o igual |

⚠️ `=` NO significa “igual lógico”. Es asignación.

```c
x = 10;
```

Comparación:

```c
x == 10
```

### `>=`

El operador:

```c
>=
```

significa:

```text
mayor O igual
```

No son dos operadores separados.

---

# 2.10. Operadores lógicos

| Operador | Significado | Lectura |
|---|---|---|
| `&&` | AND lógico | Y |
| `||` | OR lógico | O |
| `!` | NOT lógico | NO |

### AND

```c
edad >= 18 && tiene_identificacion
```

Verdadero solamente si **ambas** condiciones son verdaderas.

### OR

```c
x == 0 || y == 0
```

Verdadero si al menos una es verdadera.

### NOT

```c
!(x > 10)
```

invierte la verdad lógica de la expresión.

---

# 2.11. Cortocircuito

C evalúa `&&` y `||` con evaluación de cortocircuito.

```c
if (ptr != NULL && *ptr > 10) {
    ...
}
```

Primero evalúa:

```c
ptr != NULL
```

Si es falso, no evalúa:

```c
*ptr > 10
```

Esto permite evitar una desreferenciación inválida.

Con `||`:

```c
if (ptr == NULL || *ptr == 0) {
    ...
}
```

si `ptr == NULL` es verdadero, la segunda parte no se evalúa.

---

# 2.12. Operadores de asignación

| Forma larga | Forma compuesta |
|---|---|
| `x = x + 5` | `x += 5` |
| `x = x - 5` | `x -= 5` |
| `x = x * 5` | `x *= 5` |
| `x = x / 5` | `x /= 5` |
| `x = x % 5` | `x %= 5` |
| `x = x << 1` | `x <<= 1` |
| `x = x >> 1` | `x >>= 1` |
| `x = x & m` | `x &= m` |
| `x = x | m` | `x |= m` |
| `x = x ^ m` | `x ^= m` |

---

# 2.13. Incremento y decremento

```c
i++;
++i;
i--;
--i;
```

Equivalencias simples:

```c
i++;
```

equivale a:

```c
i = i + 1;
```

y:

```c
i--;
```

a:

```c
i = i - 1;
```

Pero `i++` y `++i` **no son intercambiables dentro de toda expresión**.

### Postincremento

```c
int x = i++;
```

Conceptualmente:

1. usa el valor actual de `i`;
2. después incrementa `i`.

### Preincremento

```c
int x = ++i;
```

Conceptualmente:

1. incrementa `i`;
2. usa el nuevo valor.

⚠️ No abuses de expresiones como:

```c
a = i++ + ++i;
```

Son terreno peligroso y no debes construir algoritmos de examen sobre ellas.

---

# 2.14. Operadores bit a bit

Estas operaciones trabajan sobre la representación binaria de valores enteros.

| Operador | Nombre |
|---|---|
| `&` | AND bit a bit |
| `|` | OR bit a bit |
| `^` | XOR |
| `~` | complemento bit a bit |
| `<<` | desplazamiento a la izquierda |
| `>>` | desplazamiento a la derecha |

### Ejemplo

```text
5 = 0101
3 = 0011
```

AND:

```text
0101
0011
----
0001 = 1
```

En C:

```c
5 & 3
```

da:

```text
1
```

### OR

```text
0101
0011
----
0111 = 7
```

### XOR

```text
0101
0011
----
0110 = 6
```

### NOT

```c
~x
```

invierte cada bit del tipo entero correspondiente.

⚠️ Para entender exactamente el resultado con enteros con signo debes considerar la representación utilizada por la implementación. Para razonamiento seguro de examen, suele ser más cómodo trabajar con tipos unsigned.

---

# 2.15. Shift

```c
x << n
```

desplaza los bits a la izquierda.

Para unsigned, desplazar una potencia de dos posiciones a la izquierda es conceptualmente multiplicar por potencias de dos siempre que no se salga del rango:

```c
x << 1
```

≈ `x * 2`.

Desplazamiento a la derecha:

```c
x >> 1
```

≈ división entera entre 2 en muchos usos con unsigned.

---

# 2.16. `&` no siempre significa lo mismo

Este símbolo tiene varios usos.

### Dirección de una variable

```c
int x = 10;
int *p = &x;
```

Aquí `&x` significa:

> dirección de memoria de `x`.

### AND bit a bit

```c
a & b
```

Aquí significa:

> AND de bits.

### La diferencia

```c
int *p = &x;
```

```c
int r = a & b;
```

El contexto determina el significado.

---

# 2.17. Precedencia y paréntesis

No memorices una tabla infinita antes del examen. Cuando una expresión es importante, **pon paréntesis**.

Ejemplo:

```c
a + b * c
```

se interpreta como:

```c
a + (b * c)
```

Pero:

```c
(a + b) * c
```

cambia el resultado.

Para condiciones:

```c
if ((a > 0 && b > 0) || c == 0)
```

es mucho más legible que confiar en precedencia implícita.

---

# 2.18. Conversión de tipos

### Conversión implícita

```c
double x = 10;
```

El `int` puede convertirse a `double`.

### Cast explícito

```c
float promedio = (float)suma / cantidad;
```

Esto es importantísimo:

```c
int suma = 5;
int cantidad = 2;

float p1 = suma / cantidad;        // 2.0
float p2 = (float)suma / cantidad; // 2.5
```

⚠️ El tipo del resultado de la división depende de los operandos, no de la variable de destino.

---

# 2.19. Estructuras de control

---

## `if`

```c
if (condicion) {
    ...
}
```

## `if / else`

```c
if (condicion) {
    ...
} else {
    ...
}
```

## `else if`

```c
if (a > b) {
    ...
} else if (a < b) {
    ...
} else {
    ...
}
```

---

# 2.20. `switch`

Ideal cuando comparas una expresión contra valores concretos.

```c
switch (opcion) {
    case 1:
        printf("Uno\n");
        break;

    case 2:
        printf("Dos\n");
        break;

    default:
        printf("Opcion invalida\n");
        break;
}
```

### `break`

Sin `break`, puede ocurrir **fall-through**:

```c
case 1:
    ...
case 2:
    ...
```

El código del `case 2` puede ejecutarse también.

Esto puede ser intencional, pero en un examen normalmente se espera `break`.

---

# 2.21. Bucles

---

## `while`

Evalúa primero.

```c
while (condicion) {
    ...
}
```

Puede ejecutar:

```text
0 veces
1 vez
muchas veces
```

---

## `do while`

Ejecuta primero.

```c
do {
    ...
} while (condicion);
```

Garantiza:

```text
mínimo 1 iteración
```

⚠️ Hay `;` después de `while (...)`.

---

## `for`

```c
for (inicio; condicion; actualizacion) {
    ...
}
```

Ejemplo:

```c
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

Orden:

```text
inicialización
      ↓
condición
      ↓
cuerpo
      ↓
actualización
      ↓
condición
```

---

# 2.22. Bucles anidados

Patrón típico de matrices:

```c
for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
        ...
    }
}
```

Piensa:

- `i` → fila;
- `j` → columna.

---

# 2.23. `break`

Sale inmediatamente del bucle o `switch` más cercano.

```c
for (int i = 0; i < 100; i++) {
    if (i == 20) {
        break;
    }
}
```

---

# 2.24. `continue`

Salta el resto de la iteración actual.

```c
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
        continue;
    }

    printf("%d\n", i);
}
```

Imprime sólo impares.

⚠️ En un `for`, `continue` no “salta al principio absoluto”; primero ocurre la actualización del `for`, y después se vuelve a comprobar la condición.

---

# 2.25. `goto`

Existe:

```c
goto etiqueta;

etiqueta:
    ...
```

No es necesario para los algoritmos estructurados normales del curso.

---

# UNIDAD 3 — DISEÑO DE PROGRAMAS

---

# 3.1. Refinamiento progresivo

También puedes imaginarlo como **Top-Down**.

Problema:

```text
Sistema de ventas
```

Se divide:

```text
Sistema de ventas
├── mostrar menú
├── registrar venta
├── validar venta
├── calcular descuento
└── mostrar total
```

Después cada módulo puede dividirse nuevamente.

---

# 3.2. Programación ascendente y descendente

### Descendente

Partes del problema completo:

```text
Problema grande
→ subproblemas
→ módulos
→ instrucciones
```

### Ascendente

Construyes componentes pequeños:

```text
funciones pequeñas
→ módulos
→ sistema
```

En un primer curso, el razonamiento Top-Down suele ser especialmente útil para diseñar la solución.

---

# 3.3. Función

Forma general:

```c
tipo nombre(parametros) {
    instrucciones
    return valor;
}
```

Ejemplo:

```c
int sumar(int a, int b) {
    return a + b;
}
```

---

# 3.4. Prototipo

Declaración de una función antes de utilizarla:

```c
int sumar(int a, int b);
```

También puede escribirse:

```c
int sumar(int, int);
```

El nombre de los parámetros no es necesario en un prototipo.

---

# 3.5. Contrato de una función

Para analizar una función, pregunta siempre:

### 1. ¿Qué recibe?
Tipos y cantidades de parámetros.

### 2. ¿Qué devuelve?
Tipo de retorno.

### 3. ¿Qué modifica?
Especialmente si recibe punteros.

### 4. ¿Qué precondiciones tiene?
Por ejemplo:

```text
divisor != 0
```

### 5. ¿Qué garantiza?
Por ejemplo:

```text
retorna el cociente entero
y escribe el residuo en *r
```

Ejemplo:

```c
void dividir(int a, int b, int *cociente, int *residuo);
```

Contrato posible:

```text
Entrada:
    a, b válidos
Precondición:
    b != 0
Salida:
    *cociente = a / b
    *residuo = a % b
Retorno:
    void
```

---

# 3.6. `void`

### Como retorno

```c
void saludar(void) {
    printf("Hola\n");
}
```

No devuelve un valor usable como resultado.

⚠️ Esto:

```c
int x = saludar();
```

es incorrecto si `saludar` es `void`.

### Como lista de parámetros

```c
void saludar(void);
```

significa:

> la función no recibe parámetros.

Esto es más preciso que:

```c
void saludar();
```

En C moderno, `f()` no expresa “ningún parámetro” con la misma precisión; para una función que realmente no recibe argumentos usa `void`.

---

# 3.7. Retornos posibles

Una función puede devolver:

```c
int
float
double
char
struct
enum
puntero
puntero a función
```

Ejemplo:

```c
struct Punto crear_punto(void);
```

Ejemplo con puntero:

```c
int *obtener_elemento(void);
```

Ejemplo con puntero a función:

```c
int (*obtener_operacion(void))(int, int);
```

---

# 3.8. Arrays como retorno

No puedes declarar una función con retorno de “array” como:

```c
int[] funcion(void); // incorrecto
```

Pero sí puedes:

### Devolver puntero al primer elemento

```c
int *crear_algo(void);
```

si el almacenamiento apunta a una región válida con tiempo de vida suficiente.

### Mejor: que el llamador proporcione el array

```c
void llenar(int datos[], int n);
```

Esto suele ser más sencillo y seguro en un curso introductorio.

---

# 3.9. Una función dentro de otra

En C estándar no defines normalmente una función con sintaxis:

```c
void a() {
    void b() { ... } // no es C estándar
}
```

Pero sí puedes:

```c
int suma(int a, int b);

int multiplicar(int base, int veces) {
    int total = 0;

    for (int i = 0; i < veces; i++) {
        total = suma(total, base);
    }

    return total;
}
```

Una función puede llamar a otra definida fuera.

---

# 3.10. Pila de llamadas

Cuando:

```c
main()
    ↓
multiplicar()
    ↓
suma()
```

la implementación mantiene información necesaria para las llamadas activas.

Conceptualmente:

```text
┌──────────────┐
│ suma()       │ ← activa
├──────────────┤
│ multiplicar()│ ← esperando
├──────────────┤
│ main()       │ ← esperando
└──────────────┘
```

Cuando `suma()` termina, su activación desaparece y vuelve a `multiplicar()`.

---

# 3.11. Paso por valor

```c
void cambiar(int x) {
    x = 100;
}
```

Uso:

```c
int n = 5;
cambiar(n);
```

`n` sigue siendo:

```text
5
```

porque `x` es otro objeto/parámetro con una copia del valor.

---

# 3.12. “Paso por referencia” en C

C **no tiene una palabra reservada equivalente al “paso por referencia” de C++**.

Lo que normalmente llamamos “paso por referencia” en cursos introductorios de C significa:

> pasar un puntero por valor.

Ejemplo:

```c
void cambiar(int *p) {
    *p = 100;
}
```

Uso:

```c
int n = 5;
cambiar(&n);
```

Ahora:

```text
n = 100
```

Porque el parámetro `p` contiene la dirección de `n`.

---

# 3.13. Alcance de variables — scope

### Variable local

```c
void f(void) {
    int x = 10;
}
```

`x` sólo es visible dentro de su bloque correspondiente.

### Variable global

```c
int contador = 0;
```

Puede tener duración de almacenamiento estática y alcance de archivo/programa según su declaración y enlace.

⚠️ **Scope**, duración y linkage son conceptos distintos:

- **scope** → dónde puedes nombrar el identificador;
- **storage duration** → durante cuánto existe el objeto;
- **linkage** → si declaraciones en distintos ámbitos/unidades de traducción pueden referirse al mismo identificador.

---

# 3.14. Shadowing

Ejemplo:

```c
int vida = 100;

void daño(void) {
    int vida = 50;
    printf("%d\n", vida);
}
```

Dentro de `daño`, el `vida` local oculta al global del mismo nombre.

Esto es **shadowing**.

---

# 3.15. Headers `.h`

Una cabecera es una interfaz.

Puede contener:

- prototipos;
- `typedef`;
- `struct`;
- `enum`;
- macros;
- declaraciones `extern`;
- constantes y declaraciones necesarias.

Ejemplo:

## `calculos.h`

```c
#ifndef CALCULOS_H
#define CALCULOS_H

int sumar(int a, int b);
float promedio(float suma, int n);

#endif
```

## `calculos.c`

```c
#include "calculos.h"

int sumar(int a, int b) {
    return a + b;
}

float promedio(float suma, int n) {
    return suma / n;
}
```

## `main.c`

```c
#include <stdio.h>
#include "calculos.h"

int main(void) {
    int r = sumar(2, 3);
    printf("%d\n", r);
    return 0;
}
```

---

# 3.16. Guardas de inclusión

Patrón:

```c
#ifndef NOMBRE_H
#define NOMBRE_H

/* contenido */

#endif
```

Ejemplo:

```c
#ifndef GEOMETRIA_H
#define GEOMETRIA_H

float area_circulo(float radio);

#endif
```

La idea:

1. si `GEOMETRIA_H` no está definido → entra;
2. se define;
3. las siguientes inclusiones ya no vuelven a introducir el contenido.

---

# 3.17. `#pragma once`

Alternativa común:

```c
#pragma once
```

Es ampliamente soportada, pero las guardas clásicas:

```c
#ifndef
#define
#endif
```

son fundamentales para comprender el preprocesador y siguen siendo muy comunes en código C.

---

# 3.18. `extern`

Supón:

## `datos.c`

```c
int contador = 100;
```

Aquí existe la **definición**.

## `datos.h`

```c
#ifndef DATOS_H
#define DATOS_H

extern int contador;

#endif
```

Aquí existe una **declaración**.

## `main.c`

```c
#include <stdio.h>
#include "datos.h"

int main(void) {
    printf("%d\n", contador);
    return 0;
}
```

La idea es:

```text
datos.c
  define contador
      ↓
compilador genera datos.o

main.c
  usa extern contador
      ↓
compilador genera main.o

linker
  resuelve el símbolo contador
      ↓
ejecutable
```

---

# 3.19. Definición vs declaración

### Declaración

Le dice al compilador:

> existe una entidad con este nombre y este tipo.

### Definición

Proporciona la definición de la entidad; para un objeto que necesita almacenamiento, establece el objeto.

Ejemplo típico:

```c
extern int x;   // declaración
int x = 10;     // definición
```

⚠️ No memorices “extern = no crea memoria” como regla absoluta sin contexto. Por ejemplo:

```c
extern int x = 10;
```

es una definición.

---

# 3.20. Proceso completo de un proyecto

Supón:

```text
main.c
util.c
util.h
```

### Preprocesamiento

Cada `.c` se procesa por separado.

### Compilación

Cada unidad de traducción produce código objeto.

### Linker

Une los objetos y resuelve referencias externas.

Comando típico con GCC:

```bash
gcc main.c util.c -o programa
```

También puede hacerse por etapas:

```bash
gcc -c main.c -o main.o
gcc -c util.c -o util.o
gcc main.o util.o -o programa
```

---

# UNIDAD 4 — ESTRUCTURAS DE DATOS BÁSICAS

---

# 4.1. Arrays

Un array es un conjunto de elementos del **mismo tipo** almacenados de forma contigua.

```c
int edades[5];
```

Tiene cinco elementos:

```text
edades[0]
edades[1]
edades[2]
edades[3]
edades[4]
```

⚠️ Índices desde `0`.

---

# 4.2. Memoria de un array

Si:

```c
int a[5];
```

y `sizeof(int) == 4`, entonces:

```text
5 × 4 = 20 bytes
```

El array completo ocupa aproximadamente:

```c
sizeof(a)
```

que sería 20 en esa implementación.

---

# 4.3. El array y sus elementos

```c
int a[4] = {10, 20, 30, 40};
```

Conceptualmente:

```text
a
↓
┌────┬────┬────┬────┐
│ 10 │ 20 │ 30 │ 40 │
└────┴────┴────┴────┘
  0    1    2    3
```

No existe una operación estándar tipo:

```c
a.push_back(...)
```

porque C no proporciona arrays dinámicos de esa forma.

---

# 4.4. ¿Se puede cambiar un array?

Sí:

```c
int a[3] = {1, 2, 3};

a[0] = 99;
```

Queda:

```text
99 2 3
```

Por tanto, un array normal es mutable.

---

# 4.5. ¿Se puede añadir?

En un array de tamaño fijo:

```c
int a[3];
```

el número de elementos es tres.

No puedes convertirlo en cuatro escribiendo:

```c
a[3] = 4; // ERROR conceptual: fuera del límite
```

`a[3]` está fuera del array.

⚠️ Eso produce comportamiento indefinido si se accede realmente.

Puedes:

- reservar un array mayor;
- mantener un contador de elementos usados;
- usar memoria dinámica con `malloc/realloc`;
- diseñar un contenedor propio.

---

# 4.6. El operador `sizeof`

```c
int a[10];

sizeof(a)
```

devuelve el tamaño total del array **cuando `a` realmente es un array en ese contexto**.

Número de elementos:

```c
sizeof(a) / sizeof(a[0])
```

Ejemplo:

```c
size_t n = sizeof(a) / sizeof(a[0]);
```

⚠️ Dentro de un parámetro:

```c
void f(int a[]) {
    sizeof(a)
}
```

`a` ya se comporta como parámetro puntero; no obtienes el tamaño total del array original de esa manera.

---

# 4.7. Arrays y punteros: relación

Para muchas expresiones:

```c
a
```

se convierte en un puntero al primer elemento:

```c
&a[0]
```

Por ejemplo:

```c
int *p = a;
```

es equivalente a:

```c
int *p = &a[0];
```

Pero:

```c
sizeof(a)
```

y:

```c
sizeof(p)
```

no significan lo mismo.

Esto es una de las distinciones más importantes de C.

---

# 4.8. Aritmética de punteros sobre arrays

Si:

```c
int a[4] = {10, 20, 30, 40};
int *p = a;
```

entonces:

```c
p
```

apunta a `a[0]`.

```c
p + 1
```

apunta a `a[1]`.

```c
p + 2
```

apunta a `a[2]`.

La suma no avanza “un byte”; avanza una cantidad de elementos del tipo apuntado.

Si `sizeof(int) == 4`:

```text
p + 1
```

avanza 4 bytes.

---

# 4.9. Acceso con corchetes

Sorprendentemente:

```c
a[i]
```

está relacionado con:

```c
*(a + i)
```

Por eso:

```c
i[a]
```

también es una expresión válida en C, aunque es horrible como estilo.

---

# 4.10. Matrices

```c
int m[3][4];
```

Significa:

```text
3 filas
4 columnas
12 enteros
```

Acceso:

```c
m[fila][columna]
```

Ejemplo:

```c
m[1][2]
```

---

# 4.11. Matriz en memoria

Un array bidimensional de C se almacena de manera contigua según su tipo de array.

Para:

```c
int m[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

conceptualmente:

```text
1 2 3 4 5 6
```

en almacenamiento contiguo de elementos.

La notación:

```c
m[i][j]
```

representa acceso anidado.

---

# 4.12. Multiplicación de matrices

Para:

```text
A de m×n
B de n×p
```

el resultado es:

```text
C de m×p
```

Fórmula:

```text
C[i][j] = Σ A[i][k] * B[k][j]
```

En C:

```c
for (int i = 0; i < filasA; i++) {
    for (int j = 0; j < columnasB; j++) {
        c[i][j] = 0;

        for (int k = 0; k < columnasA; k++) {
            c[i][j] += a[i][k] * b[k][j];
        }
    }
}
```

---

# 4.13. `struct`

Un `struct` agrupa diferentes objetos.

```c
struct Persona {
    char nombre[50];
    int edad;
    float altura;
};
```

Crear variable:

```c
struct Persona p;
```

---

# 4.14. `typedef`

`typedef` crea un alias de un tipo.

```c
typedef unsigned long ulong;
```

Ahora:

```c
ulong x = 1000;
```

⚠️ No crea un tipo fundamental completamente nuevo. Es un alias.

---

# 4.15. `typedef struct`

Patrón:

```c
typedef struct {
    char nombre[50];
    int edad;
    float altura;
} Persona;
```

Ahora:

```c
Persona p;
```

sin escribir:

```c
struct Persona
```

---

# 4.16. `struct` con tipos variados

Ejemplo más interesante:

```c
typedef enum {
    SENSOR_OK,
    SENSOR_ERROR,
    SENSOR_MANTENIMIENTO
} EstadoSensor;

typedef struct {
    unsigned int id;
    char nombre[32];
    float temperatura;
    double precision;
    EstadoSensor estado;
    unsigned long flags;
} Sensor;
```

Aquí tienes dentro:

- enteros;
- cadenas;
- `float`;
- `double`;
- `enum`;
- entero usado como bitmask.

---

# 4.17. Acceso con `.`

```c
Sensor s;

s.id = 10;
s.temperatura = 36.7f;
```

---

# 4.18. `struct` por puntero

```c
Sensor *p = &s;
```

Acceso:

```c
(*p).temperatura
```

Forma abreviada:

```c
p->temperatura
```

⚠️ `p->x` es equivalente a:

```c
(*p).x
```

---

# 4.19. Pasar `struct` por valor

```c
float leer_temperatura(Sensor s) {
    return s.temperatura;
}
```

La función recibe una copia del `struct`.

Puede ser válido para estructuras pequeñas.

---

# 4.20. Pasar `struct` por puntero

```c
void calentar(Sensor *s) {
    s->temperatura += 1.0f;
}
```

Uso:

```c
calentar(&sensor);
```

Modifica el original.

---

# 4.21. Inicializadores designados

C moderno permite:

```c
Sensor s = {
    .id = 10,
    .temperatura = 36.5f,
    .estado = SENSOR_OK
};
```

Es excelente para claridad.

---

# 4.22. “Romper” un `struct`

Ejemplo:

```c
typedef struct {
    char nombre[20];
    int edad;
} Persona;
```

No puedes hacer:

```c
Persona p;
p = 10;
```

porque `p` necesita un valor del tipo `Persona`.

Pero sí:

```c
Persona a = {.edad = 20};
Persona b;

b = a;
```

La asignación de estructuras completas está permitida.

---

# 4.23. `enum`

Ejemplo:

```c
enum Dia {
    LUNES = 1,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO
};
```

Entonces:

```text
LUNES = 1
MARTES = 2
...
DOMINGO = 7
```

### Con `typedef`

```c
typedef enum {
    FRIO,
    TEMPLADO,
    CALUROSO
} Nivel;
```

Uso:

```c
Nivel n = FRIO;
```

⚠️ Los identificadores del `enum` están integrados en el espacio de nombres correspondiente de enumeradores y deben manejarse con cuidado para no tener colisiones de nombres.

---

# 4.24. `enum` no es un “string”

Esto:

```c
FRIO
```

no guarda el texto `"FRIO"`.

Es un valor entero de enumeración.

Si quieres imprimirlo como palabra, debes mapearlo:

```c
switch (nivel) {
    case FRIO:
        printf("FRIO\n");
        break;
    ...
}
```

---

# 4.25. `union`

Aunque no es una estructura central del programa, conviene reconocerla.

```c
union Valor {
    int i;
    float f;
    char c;
};
```

Los miembros comparten el mismo almacenamiento.

Eso es muy diferente de `struct`, donde cada miembro tiene su propio almacenamiento dentro del objeto.

---

# UNIDAD 5 — MANEJO BÁSICO DE ARCHIVOS

---

# 5.1. `FILE *`

La librería:

```c
#include <stdio.h>
```

define el tipo `FILE`.

Un:

```c
FILE *
```

es un puntero asociado a un stream de archivo.

No significa:

> “el archivo entero está dentro del puntero”.

Significa que tienes una referencia a la estructura de estado utilizada por la implementación para gestionar ese stream.

---

# 5.2. Abrir

```c
FILE *f = fopen("datos.txt", "r");
```

Contrato conceptual:

```text
Entrada:
    nombre del archivo
    modo

Salida:
    FILE*
    o NULL si falla
```

Siempre valida:

```c
if (f == NULL) {
    printf("No se pudo abrir\n");
}
```

---

# 5.3. Modos

| Modo | Significado |
|---|---|
| `"r"` | lectura |
| `"w"` | escritura; crea o trunca |
| `"a"` | agregar al final |
| `"r+"` | lectura/escritura |
| `"w+"` | lectura/escritura, truncando |
| `"a+"` | lectura/escritura agregando |

⚠️ `"w"` puede destruir el contenido existente.

---

# 5.4. Cerrar

```c
fclose(f);
```

Debe cerrar el stream cuando termines.

El valor de retorno puede indicar si hubo un error al vaciar/cerrar.

Patrón:

```c
if (fclose(f) != 0) {
    /* error */
}
```

---

# 5.5. `fgetc`

Lee un carácter de un stream.

```c
int c;

while ((c = fgetc(f)) != EOF) {
    putchar(c);
}
```

⚠️ `fgetc` devuelve `int`, no `char`, porque necesita poder representar todos los caracteres posibles **y además** `EOF`.

---

# 5.6. `fputc`

Escribe un carácter:

```c
fputc(c, f);
```

Copia de archivo:

```c
int c;

while ((c = fgetc(origen)) != EOF) {
    fputc(c, destino);
}
```

---

# 5.7. `fgets`

Lee una línea o parte de ella.

```c
char buffer[100];

if (fgets(buffer, sizeof(buffer), f) != NULL) {
    printf("%s", buffer);
}
```

Puede conservar el `\n` si cabe en el buffer y la línea lo contiene.

---

# 5.8. `fprintf`

Similar a `printf`, pero escribe en un stream:

```c
fprintf(f, "%d %.2f\n", id, precio);
```

---

# 5.9. `fscanf`

Similar a `scanf`, pero leyendo de un archivo:

```c
int id;
float precio;

fscanf(f, "%d,%f", &id, &precio);
```

También devuelve el número de conversiones exitosas.

---

# 5.10. `EOF`

`EOF` significa:

> End Of File.

No es necesariamente un carácter físico dentro del archivo.

Es una condición/sentinel representada por un valor devuelto por ciertas funciones de stdio.

---

# CARGA DE TEXTO — `scanf`, `getchar`, `fgets`

---

# 6.1. Stream de entrada

El teclado se trata mediante un stream como:

```c
stdin
```

Muchas veces el sistema realiza buffering.

Tu programa no necesariamente “recibe una tecla directamente” en la variable.

---

# 6.2. `scanf`

Contrato conceptual:

```c
int scanf(const char *formato, ...);
```

Lee desde `stdin`.

Ejemplo:

```c
int x;

scanf("%d", &x);
```

¿Por qué `&x`?

Porque `scanf` tiene que **escribir** el resultado en `x`.

Necesita la dirección donde debe almacenarlo.

---

# 6.3. Retorno de `scanf`

Si:

```c
int r = scanf("%d", &x);
```

y el usuario escribe:

```text
123
```

normalmente:

```text
r = 1
```

Si escribe:

```text
hola
```

la conversión a entero falla y:

```text
r = 0
```

Si ocurre una condición de fin/error de entrada antes de conseguir una conversión, puede ser:

```text
EOF
```

---

# 6.4. ¿Por qué el bucle de `scanf` se atasca?

Patrón incorrecto:

```c
while (scanf("%d", &x) != 1) {
    printf("Error\n");
}
```

Si el usuario escribe:

```text
hola
```

`scanf` no consume el `h` como entero.

Entonces:

```text
scanf vuelve a ver 'h'
scanf vuelve a fallar
scanf vuelve a ver 'h'
...
```

---

# 6.5. Limpieza del buffer

Una técnica clásica:

```c
int c;

while ((c = getchar()) != '\n' && c != EOF) {
    ;
}
```

O de manera compacta:

```c
while ((c = getchar()) != '\n' && c != EOF);
```

### ¿Qué hace?

Consume:

```text
todo hasta encontrar
'\n' o EOF
```

Esto elimina el resto de la línea actual.

---

# 6.6. El espacio antes de `%c`

Este detalle es clásico de examen.

Supón:

```c
int n;
char c;

scanf("%d", &n);
scanf("%c", &c);
```

El usuario escribe:

```text
10\n
```

Después de leer el entero puede quedar el:

```text
'\n'
```

pendiente.

Entonces:

```c
scanf("%c", &c);
```

puede leer ese salto de línea.

La técnica:

```c
scanf(" %c", &c);
```

El espacio inicial del formato significa:

> consumir espacio en blanco pendiente antes de realizar la conversión `%c`.

---

# 6.7. ¿Qué formatos saltan whitespace?

En términos prácticos, las conversiones normales como:

```c
%d
%f
%s
```

saltan whitespace inicial.

`%c` no lo hace por sí mismo.

El comportamiento de `%[]` debe estudiarse aparte.

---

# 6.8. `%s`

```c
char nombre[50];

scanf("%49s", nombre);
```

⚠️ Sin `&`:

```c
scanf("%49s", nombre);
```

porque `nombre` ya se convierte en puntero al primer elemento del array.

`%s` además detiene la lectura en whitespace.

Por eso no sirve para:

```text
Daniel Garcia
```

como una sola frase.

---

# 6.9. `fgets` para líneas

Para texto con espacios suele ser preferible:

```c
char nombre[100];

fgets(nombre, sizeof(nombre), stdin);
```

Pero recuerda que puede conservar el `\n`.

Patrón común:

```c
nombre[strcspn(nombre, "\n")] = '\0';
```

Esto requiere:

```c
#include <string.h>
```

---

# TIPOS DE DATOS — REFERENCIA COMPLETA

---

# 7.1. Importante: tamaños no universales

En C, **no puedes asumir universalmente**:

```text
int = 4 bytes
long = 8 bytes
double = 8 bytes
```

El estándar define mínimos y relaciones, y la implementación concreta decide los tamaños.

En una computadora moderna de 64 bits, es común ver:

```text
char       1
short      2
int        4
long       8 en muchos sistemas Unix de 64 bits
long long  8
float      4
double     8
long double 10/16/etc., según plataforma
```

Pero debes utilizar:

```c
sizeof(tipo)
```

para saber el tamaño real de tu implementación.

---

# 7.2. `char`

```c
char c = 'A';
```

`sizeof(char)` es siempre:

```text
1
```

en unidades de `char`.

⚠️ Esto no significa que un `char` sea necesariamente 8 bits en todas las implementaciones. `CHAR_BIT` indica cuántos bits contiene un byte de C.

En máquinas comunes:

```text
CHAR_BIT = 8
```

---

# 7.3. `signed char`

Puede representar valores con signo.

En una implementación de complemento a dos típica de 8 bits:

```text
-128 ... 127
```

Pero el rango exacto debe deducirse del estándar/implementación, no sólo de “8 bits”.

---

# 7.4. `unsigned char`

No tiene signo.

Con 8 bits:

```text
0 ... 255
```

Es extremadamente útil para bytes y almacenamiento bruto.

---

# 7.5. `short`

Típicamente:

```text
2 bytes
```

En una implementación común de 16 bits:

```text
-32768 ... 32767
```

unsigned:

```text
0 ... 65535
```

Pero usa `sizeof(short)` y los límites de `<limits.h>` para conocer los valores reales.

---

# 7.6. `int`

En muchas plataformas modernas:

```text
4 bytes = 32 bits
```

En complemento a dos:

```text
-2147483648 ... 2147483647
```

unsigned:

```text
0 ... 4294967295
```

⚠️ Para código portable, utiliza las macros:

```c
INT_MIN
INT_MAX
UINT_MAX
```

de:

```c
#include <limits.h>
```

---

# 7.7. `long`

No asumas que “64 bits porque la computadora es de 64 bits”.

Ejemplos:

- Linux/macOS 64-bit típico: `long` = 64 bits.
- Windows 64-bit típico: `long` = 32 bits.

Por eso:

```c
sizeof(long)
```

es tu amigo.

---

# 7.8. `long long`

Está diseñado para proporcionar al menos 64 bits.

En implementaciones comunes:

```text
64 bits
```

Rango típico signed:

```text
-9223372036854775808
a
 9223372036854775807
```

unsigned:

```text
0
a
18446744073709551615
```

---

# 7.9. `float`

Normalmente:

```text
4 bytes
32 bits
```

Suele seguir una representación IEEE 754 binary32 en plataformas modernas.

Pero:

```text
4 bytes ≠ 4 dígitos exactos
```

Tiene precisión finita.

Por eso:

```c
float x = 0.1f;
```

no representa necesariamente exactamente la fracción matemática `0.1`.

---

# 7.10. `double`

Normalmente:

```text
8 bytes
64 bits
```

Con IEEE 754 binary64, típicamente alrededor de 15–17 dígitos decimales de precisión significativa.

Es el tipo de coma flotante recomendado para muchos cálculos generales.

---

# 7.11. `long double`

Tamaño y representación dependen de la plataforma.

No memorices “siempre 16 bytes”.

Puede ser:

```text
80 bits
128 bits
64 bits
```

entre otras posibilidades de ABI/implementación.

Comprueba:

```c
sizeof(long double)
```

y usa:

```c
LDBL_MANT_DIG
LDBL_MAX
```

de `<float.h>`.

---

# 7.12. `void`

No representa un conjunto de valores almacenables como un objeto normal.

Se utiliza para:

```c
void f(void);
```

y:

```c
void *p;
```

Un `void *` es un puntero a objeto de tipo desconocido/indeterminado que puede convertirse implícitamente desde y hacia punteros a objetos en C.

---

# 7.13. `_Bool`

C también tiene:

```c
_Bool
```

y, mediante:

```c
#include <stdbool.h>
```

puedes usar:

```c
bool
true
false
```

Ejemplo:

```c
bool activo = true;
```

⚠️ `bool` no es una palabra reservada de C sin incluir `stdbool.h` en las versiones tradicionales donde se define mediante esa cabecera.

---

# 7.14. `size_t`

Tipo unsigned utilizado para tamaños.

Ejemplo:

```c
size_t n = sizeof array;
```

Es el tipo correcto para muchos índices/tamaños producidos por `sizeof`.

---

# 7.15. Tipos enteros de ancho exacto

Con:

```c
#include <stdint.h>
```

puedes usar:

```c
int8_t
int16_t
int32_t
int64_t
uint8_t
uint16_t
uint32_t
uint64_t
```

Esto es especialmente útil cuando necesitas anchos exactos.

---

# 7.16. Límites y tamaño en tiempo de ejecución

Programa útil para estudiar tu máquina:

```c
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    printf("char: %zu\n", sizeof(char));
    printf("short: %zu\n", sizeof(short));
    printf("int: %zu\n", sizeof(int));
    printf("long: %zu\n", sizeof(long));
    printf("long long: %zu\n", sizeof(long long));
    printf("float: %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));
    printf("long double: %zu\n", sizeof(long double));

    printf("INT_MIN = %d\n", INT_MIN);
    printf("INT_MAX = %d\n", INT_MAX);

    return 0;
}
```

---

# Cadenas de texto

---

# 8.1. C no tiene un tipo nativo `string`

Una cadena de C es normalmente:

```text
array de char
+
terminador '\0'
```

Ejemplo:

```c
char nombre[] = "Daniel";
```

En memoria:

```text
'D' 'a' 'n' 'i' 'e' 'l' '\0'
```

Son:

```text
6 caracteres + 1 terminador = 7 char
```

---

# 8.2. Longitud vs capacidad

```c
char nombre[20] = "Ana";
```

Capacidad:

```text
20 char
```

Longitud actual:

```text
3
```

La cadena usa:

```text
'A' 'n' 'a' '\0'
```

y deja espacio libre.

---

# 8.3. `strlen`

```c
strlen(nombre)
```

devuelve el número de caracteres antes de `'\0'`.

No cuenta el `'\0'`.

Requiere:

```c
#include <string.h>
```

---

# 8.4. Array mutable

```c
char s[] = "Hola";

s[0] = 'h';
```

válido.

---

# 8.5. Literal de cadena

```c
char *s = "Hola";
```

No debes modificar el literal mediante `s`.

Haz:

```c
const char *s = "Hola";
```

para expresar correctamente que no modificarás el contenido apuntado.

En código:

```c
s[0] = 'h';
```

si `s` es `const char *` no compila.

---

# 8.6. Arrays bidimensionales de `char`

Para varias palabras:

```c
char nombres[3][20] = {
    "Ana",
    "Luis",
    "Maria"
};
```

Tienes:

```text
3 cadenas
cada una con espacio para 20 chars
```

---

# 8.7. Diferencia entre `char`, `char[]`, `char *`

```c
char c = 'A';
```

Un carácter.

```c
char s[] = "A";
```

Array de dos `char`:

```text
'A' '\0'
```

```c
char *p = "A";
```

Puntero al literal.

No confundas estos tres.

---

# PUNTEROS EN PROFUNDIDAD

---

# 9.1. ¿Qué es un puntero?

Un puntero es un objeto cuyo valor puede ser una dirección utilizada para apuntar a otro objeto o función.

Ejemplo:

```c
int x = 42;
int *p = &x;
```

Visualmente:

```text
x
┌────────┐
│   42   │
└────────┘
  0x1000

p
┌────────┐
│ 0x1000 │
└────────┘
```

`p` contiene la dirección.

---

# 9.2. Declaración

```c
int *p;
```

Se lee:

> `p` es puntero a `int`.

```c
float *p;
```

puntero a `float`.

```c
char *p;
```

puntero a `char`.

```c
FILE *f;
```

puntero a `FILE`.

---

# 9.3. `&` — dirección

```c
int x = 10;
int *p = &x;
```

`&x`:

> dirección de `x`.

---

# 9.4. `*` — desreferenciación

Si:

```c
int *p = &x;
```

entonces:

```c
*p
```

significa:

> el objeto al que `p` apunta.

Ejemplo:

```c
*p = 50;
```

cambia `x` a `50`.

---

# 9.5. El mismo `*` aparece en dos papeles

Declaración:

```c
int *p;
```

El `*` forma parte del declarador.

Expresión:

```c
*p
```

El `*` es desreferenciación.

---

# 9.6. Puntero nulo

```c
int *p = NULL;
```

significa:

> p no apunta a ningún objeto válido.

Nunca hagas:

```c
*p = 10;
```

si `p == NULL`.

---

# 9.7. Comprobar NULL

```c
if (p != NULL) {
    printf("%d\n", *p);
}
```

---

# 9.8. Puntero a puntero

```c
int x = 10;
int *p = &x;
int **pp = &p;
```

Relación:

```text
pp → p → x
```

Entonces:

```c
**pp
```

da `10`.

---

# 9.9. Punteros y arrays

```c
int a[3] = {10, 20, 30};
int *p = a;
```

Entonces:

```c
*p       // 10
*(p + 1) // 20
*(p + 2) // 30
```

---

# 9.10. Punteros y funciones

Ejemplo clásico:

```c
void incrementar(int *x) {
    (*x)++;
}
```

Uso:

```c
int n = 5;
incrementar(&n);
```

---

# 9.11. Puntero constante vs puntero a constante

Esto es importantísimo.

### Puntero a datos constantes

```c
const int *p;
```

No puedes modificar el `int` mediante `p`.

Sí puedes cambiar a dónde apunta `p`.

### Puntero constante

```c
int *const p = &x;
```

No puedes hacer que `p` apunte a otra dirección, pero sí puedes modificar `*p`.

### Puntero constante a datos constantes

```c
const int *const p = &x;
```

No cambias ni:

- lo apuntado a través de `p`;
- ni la propia dirección guardada en `p`.

---

# 9.12. Aritmética de punteros

Si:

```c
int *p;
```

entonces:

```c
p + 1
```

avanza un elemento de tipo `int`.

No un byte necesariamente.

También:

```c
p - 1
p++
p--
```

pueden usarse cuando el puntero se encuentra dentro del mismo array o una posición past-the-end permitida por las reglas del lenguaje.

---

# 9.13. Comparar punteros

En general, la aritmética y comparación relacional entre punteros tiene reglas específicas.

Lo importante para examen:

```c
p == q
```

pregunta si contienen la misma dirección/valor de puntero.

```c
p == NULL
```

pregunta si no apunta a un objeto.

No compares punteros para saber si dos enteros tienen el mismo valor:

```c
*p == *q
```

---

# 9.14. Puntero one-past-the-end

Si:

```c
int a[5];
```

es válido formar conceptualmente:

```c
a + 5
```

como puntero one-past-the-end.

No es válido desreferenciarlo:

```c
*(a + 5) // incorrecto
```

Sirve para recorrer:

```c
for (int *p = a; p != a + 5; ++p) {
    ...
}
```

---

# 9.15. Funciones que devuelven punteros

Sí se puede:

```c
int *buscar(int *a, int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (a[i] == valor) {
            return &a[i];
        }
    }

    return NULL;
}
```

Uso:

```c
int *p = buscar(a, n, 42);

if (p != NULL) {
    printf("%d\n", *p);
}
```

---

# 9.16. ⚠️ Nunca devuelvas la dirección de una local

Mal:

```c
int *funcion(void) {
    int x = 10;
    return &x;
}
```

`x` deja de existir cuando termina su duración de almacenamiento automática.

El puntero queda inválido.

---

# 9.17. Funciones que reciben arrays

Estas formas se ajustan a parámetros de función de una manera relacionada:

```c
void f(int a[], int n);
```

y:

```c
void f(int *a, int n);
```

En parámetros, `int a[]` se ajusta a un parámetro de tipo puntero a `int`.

Por eso siempre conviene pasar:

```c
array + tamaño
```

Ejemplo:

```c
void imprimir(const int *a, size_t n);
```

El `const` expresa que la función no necesita modificar los elementos mediante ese puntero.

---

# 9.18. Punteros a funciones

Declaración difícil:

```c
int (*fp)(int, int);
```

Se lee:

> `fp` es un puntero a una función que recibe dos `int` y retorna `int`.

Ejemplo:

```c
int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}
```

Asignación:

```c
int (*fp)(int, int) = suma;
```

Llamada:

```c
int r = fp(10, 3);
```

También:

```c
int r = (*fp)(10, 3);
```

---

# 9.19. `typedef` para punteros a función

Mucho más legible:

```c
typedef int (*Operacion)(int, int);
```

Entonces:

```c
Operacion op = suma;
```

Y una función puede devolver ese tipo:

```c
Operacion seleccionar(int opcion) {
    if (opcion == 1)
        return suma;

    return resta;
}
```

---

# 9.20. Punteros + enum + struct + bitwise

Ejemplo integrador:

```c
#include <stdio.h>

typedef enum {
    ESTADO_APAGADO = 0,
    ESTADO_ENCENDIDO = 1
} Estado;

typedef struct {
    unsigned int flags;
    Estado estado;
} Dispositivo;

enum {
    FLAG_ERROR = 1u << 0,
    FLAG_BATERIA = 1u << 1,
    FLAG_COMUNICACION = 1u << 2
};

void activar_error(Dispositivo *d) {
    d->flags |= FLAG_ERROR;
}

int tiene_error(const Dispositivo *d) {
    return (d->flags & FLAG_ERROR) != 0;
}

int main(void) {
    Dispositivo d = {
        .flags = 0,
        .estado = ESTADO_ENCENDIDO
    };

    activar_error(&d);

    printf("%d\n", tiene_error(&d));

    return 0;
}
```

Aquí aparecen:

- `typedef`;
- `enum`;
- `struct`;
- puntero;
- `const`;
- `->`;
- `&`;
- `|=`;
- `&`;
- `<<`.

---

# BÚSQUEDA Y ORDENAMIENTO

---

# 10.1. Búsqueda lineal

Problema:

> Encontrar un elemento en un array sin ordenar.

Algoritmo:

```c
int buscar(const int *a, int n, int objetivo) {
    for (int i = 0; i < n; i++) {
        if (a[i] == objetivo) {
            return i;
        }
    }

    return -1;
}
```

Complejidad:

```text
O(n)
```

---

# 10.2. Búsqueda del máximo

```c
int maximo(const int *a, int n) {
    int max = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}
```

⚠️ Requiere `n > 0`.

---

# 10.3. Invertir un array in-place

Sin array auxiliar:

```c
void invertir(int *a, int n) {
    int i = 0;
    int j = n - 1;

    while (i < j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;

        i++;
        j--;
    }
}
```

Idea:

```text
izquierda → ← derecha
```

---

# 10.4. Bubble sort

Idea:

> comparar vecinos e intercambiarlos cuando están en orden incorrecto.

```c
void bubble_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
```

Complejidad típica:

```text
O(n²)
```

---

# 10.5. Bubble sort optimizado

Si en una pasada no hubo intercambios, ya está ordenado.

```c
void bubble_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int hubo_cambio = 0;

        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                hubo_cambio = 1;
            }
        }

        if (!hubo_cambio) {
            break;
        }
    }
}
```

---

# 10.6. Selection sort

Idea:

1. buscar el mínimo;
2. colocarlo en la posición actual;
3. repetir.

```c
void selection_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }

        if (min != i) {
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
}
```

---

# 10.7. Invertir una cadena

```c
#include <string.h>

void invertir_cadena(char *s) {
    size_t i = 0;
    size_t j = strlen(s);

    if (j == 0) {
        return;
    }

    j--;

    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;

        i++;
        j--;
    }
}
```

---

# 10.8. Palíndromo

```c
#include <string.h>

int es_palindromo(const char *s) {
    size_t i = 0;
    size_t j = strlen(s);

    if (j == 0) {
        return 1;
    }

    j--;

    while (i < j) {
        if (s[i] != s[j]) {
            return 0;
        }

        i++;
        j--;
    }

    return 1;
}
```

---

# 10.9. Frecuencia de valores

Si los números están en un rango pequeño, puedes utilizar un arreglo de conteos.

Por ejemplo, si sólo pueden ir de 0 a 9:

```c
int frecuencia[10] = {0};

for (int i = 0; i < n; i++) {
    frecuencia[a[i]]++;
}
```

Esto es un patrón importantísimo.

---

# 10.10. MCM y MCD — Euclides

MCD:

```c
int mcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}
```

Idea:

```text
mcd(a, b) = mcd(b, a % b)
```

---

# 10.11. Simplificación de fracciones

```c
void simplificar(int *num, int *den) {
    int d = mcd(*num, *den);

    *num /= d;
    *den /= d;
}
```

Esto integra:

- función;
- punteros;
- dereferencia;
- algoritmo de Euclides.

---

# 10.12. Paridad

```c
n % 2 == 0
```

→ par.

```c
n % 2 != 0
```

→ impar.

Evita:

```c
n % 2
```

cuando necesitas transmitir claramente una intención al lector.

---

# 10.13. Año bisiesto

Regla:

```c
(anio % 400 == 0) ||
(anio % 4 == 0 && anio % 100 != 0)
```

Versión:

```c
if ((anio % 400 == 0) ||
    (anio % 4 == 0 && anio % 100 != 0)) {
    ...
}
```

---

# LIBRERÍA ESTÁNDAR — LAS MÁS ÚTILES

---

# 11.1. No existen “10 built-in matemáticas” como tal

En C, muchas funciones que parecen “del lenguaje” pertenecen a bibliotecas.

Por ejemplo:

```c
sqrt
pow
sin
cos
```

requieren:

```c
#include <math.h>
```

y normalmente, con GCC/Clang:

```bash
-lm
```

según plataforma.

---

# 11.2. Diez funciones/bloques que conviene memorizar

## 1. `printf`

```c
printf("%d\n", x);
```

`<stdio.h>`

Retorna el número de caracteres escritos o un valor negativo ante error, según el contrato estándar.

---

## 2. `scanf`

```c
scanf("%d", &x);
```

`<stdio.h>`

Retorna conversiones asignadas o `EOF`.

---

## 3. `getchar`

```c
int c = getchar();
```

`<stdio.h>`

Devuelve un `int` para poder representar `EOF`.

---

## 4. `fgets`

```c
fgets(buffer, sizeof buffer, stdin);
```

`<stdio.h>`

Muy útil para líneas completas.

---

## 5. `strlen`

```c
strlen(s);
```

`<string.h>`

Longitud de una cadena C, sin contar `'\0'`.

---

## 6. `strcmp`

```c
strcmp(a, b)
```

`<string.h>`

Compara dos cadenas.

Retorna:

```text
< 0
= 0
> 0
```

No asumas que devuelve exactamente `-1`, `0`, `1`.

---

## 7. `strcpy` / mejor conocer sus riesgos

```c
strcpy(dest, src);
```

`<string.h>`

⚠️ Si `dest` no tiene espacio suficiente, puedes causar overflow.

En examen debes comprender el tamaño disponible antes de copiar.

---

## 8. `memcpy`

```c
memcpy(dest, src, n);
```

`<string.h>`

Copia bytes.

⚠️ Las regiones no deben solaparse. Para solapamiento, usa `memmove`.

---

## 9. `malloc`

```c
int *a = malloc(n * sizeof *a);
```

`<stdlib.h>`

Reserva memoria dinámica.

Siempre debes comprobar:

```c
if (a == NULL) {
    ...
}
```

y después:

```c
free(a);
```

---

## 10. `free`

```c
free(a);
```

Libera memoria previamente obtenida dinámicamente.

No vuelvas a usar el puntero como si siguiera apuntando a una región válida.

---

# 11.3. Matemáticas: las que realmente conviene memorizar

Con `<math.h>`:

```c
sqrt(x)
pow(x, y)
fabs(x)
floor(x)
ceil(x)
fmod(x, y)
```

y trigonometría:

```c
sin(x)
cos(x)
tan(x)
```

### Ejemplo

```c
double raiz = sqrt(25.0);
double potencia = pow(2.0, 10.0);
```

⚠️ No son keywords del lenguaje.

---

# 11.4. Funciones de clasificación de caracteres

Con:

```c
#include <ctype.h>
```

muy útiles:

```c
isalpha(c)
isdigit(c)
isspace(c)
islower(c)
isupper(c)
tolower(c)
toupper(c)
```

Ejemplo:

```c
if (isdigit((unsigned char)c)) {
    ...
}
```

---

# 11.5. Conversión de cadenas a números

Con `<stdlib.h>`:

```c
atoi
atof
strtol
strtod
```

Para código robusto, `strtol` y `strtod` suelen ser preferibles a `atoi`/`atof`, porque permiten controlar errores con mayor precisión.

---

# `struct` + funciones + punteros — patrón maestro

---

## 12.1. Cabecera

```c
#ifndef SENSOR_H
#define SENSOR_H

typedef enum {
    NORMAL,
    ALERTA
} Estado;

typedef struct {
    int id;
    float temperatura;
    Estado estado;
} Sensor;

void actualizar(Sensor *s, float nueva_temperatura);
int esta_en_alerta(const Sensor *s);

#endif
```

---

## 12.2. Implementación

```c
#include "sensor.h"

void actualizar(Sensor *s, float nueva_temperatura) {
    s->temperatura = nueva_temperatura;

    if (nueva_temperatura > 40.0f) {
        s->estado = ALERTA;
    } else {
        s->estado = NORMAL;
    }
}

int esta_en_alerta(const Sensor *s) {
    return s->estado == ALERTA;
}
```

---

## 12.3. Uso

```c
#include <stdio.h>
#include "sensor.h"

int main(void) {
    Sensor s = {
        .id = 1,
        .temperatura = 25.0f,
        .estado = NORMAL
    };

    actualizar(&s, 45.0f);

    printf("%d\n", esta_en_alerta(&s));

    return 0;
}
```

---

# COMPILACIÓN, PREPROCESADOR Y LINKER

---

# 13.1. El modelo mental correcto

No pienses:

```text
.c → magia → exe
```

Piensa:

```text
fuente
  ↓
preprocesador
  ↓
unidad de traducción
  ↓
compilador
  ↓
objeto
  ↓
linker
  ↓
ejecutable
```

---

# 13.2. ¿Qué hace `#include`?

Conceptualmente:

```c
#include "mi.h"
```

hace que el preprocesador incorpore el contenido de la cabecera en la unidad de traducción.

No significa:

> “el archivo queda mágicamente enlazado al ejecutable”.

El `.h` normalmente contiene declaraciones; el código de una función se encuentra en una implementación `.c` o biblioteca compilada.

---

# 13.3. ¿Qué contiene `stdio.h`?

Contiene declaraciones y definiciones necesarias para utilizar la interfaz de stdio.

No debes imaginar que:

```c
stdio.h
```

es “el programa entero de `printf`”.

El código ejecutable de la biblioteca está en artefactos compilados y su integración depende de la plataforma.

---

# 13.4. Error clásico de linker

Si haces:

```bash
gcc main.c -o programa
```

pero `main.c` llama una función definida solamente en:

```text
util.c
```

puedes obtener:

```text
undefined reference to ...
```

La solución puede ser:

```bash
gcc main.c util.c -o programa
```

---

# 13.5. Error de compilación vs error de linker

### Error de compilación

Ejemplo:

```c
int x = ;
```

No es sintaxis válida.

### Error de linker

Tu código fuente puede ser sintácticamente válido:

```c
int sumar(int, int);

int main(void) {
    return sumar(1, 2);
}
```

pero si nunca existe la definición de `sumar`, el linker puede fallar.

---

# 13.6. Archivo `.h`: qué sí y qué no

### Sí

```c
#ifndef ...
#define ...

typedef ...
struct ...
enum ...

extern int contador;

int sumar(int, int);

#endif
```

### Evita

```c
int contador = 10;
```

en una cabecera que va a incluirse en múltiples `.c`.

Eso puede producir múltiples definiciones.

---

# 13.7. Excepción: definiciones especiales

Hay más detalles sobre:

```c
static
inline
static inline
```

pero no conviertas una regla simplificada del curso en una ley absoluta. Lo importante para tu examen:

> **cabecera = interfaz/declaraciones; implementación = `.c`**.

---

# MEMORIA: MODELO PRÁCTICO

---

# 14.1. Stack

Variables automáticas y datos asociados con llamadas de funciones suelen estar implementados usando una pila de llamadas.

Ejemplo:

```c
void f(void) {
    int x = 10;
}
```

`x` tiene duración automática.

---

# 14.2. Heap

Memoria dinámica:

```c
malloc
calloc
realloc
free
```

Ejemplo:

```c
int *a = malloc(10 * sizeof *a);
```

---

# 14.3. Datos estáticos/globales

Ejemplo:

```c
int contador = 0;
```

a nivel de archivo.

Tiene almacenamiento estático.

No significa automáticamente que esté en una única región física específica en todas las plataformas; piensa en **duración y linkage**, y sólo después en segmentos.

---

# 14.4. Segmento de código

Las funciones se representan mediante código ejecutable, y se puede trabajar con sus direcciones mediante punteros a función.

No imagines:

```c
int resultado = funcion();
```

como:

> copiar todo el código de `funcion` dentro de `resultado`.

Lo que ocurre es:

```text
llamada
↓
ejecución
↓
retorno de un valor
↓
asignación del valor
```

---

# ERRORES QUE MÁS TE PUEDEN COSTAR EN EL EXAMEN

---

# 15.1. Confundir `=` y `==`

```c
if (x = 5)
```

hace asignación.

Correcto si quieres comparar:

```c
if (x == 5)
```

---

# 15.2. Confundir `&` y `&&`

```c
&x
```

dirección.

```c
a && b
```

AND lógico.

---

# 15.3. Confundir `&` y `&`

También existe:

```c
a & b
```

AND bit a bit.

---

# 15.4. Confundir `*` de multiplicación y desreferencia

```c
a * b
```

multiplicación.

```c
*p
```

desreferencia.

```c
int *p;
```

declaración de puntero.

---

# 15.5. Confundir char y string

```c
'A'
```

carácter.

```c
"A"
```

cadena con:

```text
'A' '\0'
```

---

# 15.6. Olvidar `&` en `scanf`

Para:

```c
int n;
scanf("%d", &n);
```

correcto.

Para:

```c
char s[20];
scanf("%19s", s);
```

sin `&`.

---

# 15.7. Array fuera de rango

```c
int a[5];
a[5] = 10;
```

incorrecto.

Último índice:

```c
a[4]
```

---

# 15.8. Confundir tamaño con longitud

```c
char nombre[100] = "Ana";
```

Tamaño/capacidad:

```text
100
```

Longitud:

```text
3
```

---

# 15.9. `sizeof` en parámetro de array

Esto:

```c
void f(int a[]) {
    sizeof(a);
}
```

no produce el tamaño del array original.

---

# 15.10. `scanf` en bucles sin limpiar entrada

Patrón robusto:

```c
int n;
int c;

while (scanf("%d", &n) != 1) {
    printf("Entrada invalida.\n");

    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }
}
```

---

# 15.11. Paridad

Recuerda:

```c
i % 2 == 0
```

→ par.

```c
i % 2 != 0
```

→ impar.

---

# 15.12. No usar números mágicos

Malo:

```c
while ((c = getchar()) != 42)
```

Bueno:

```c
while ((c = getchar()) != '*')
```

Malo:

```c
if (c != 10)
```

Bueno:

```c
if (c != '\n')
```

---

# 15.13. `switch` con `default`

No hagas:

```c
if (opcion == 1 || opcion == 2 || opcion == 3) {
    switch (opcion) {
        ...
    }
}
```

Muchas veces basta:

```c
switch (opcion) {
    case 1:
        ...
        break;

    case 2:
        ...
        break;

    case 3:
        ...
        break;

    default:
        printf("Opcion invalida\n");
}
```

---

# 15.14. Incluir buenas prácticas

Para compartir código:

```c
#include <stdio.h>

int main(void) {
    ...
}
```

Prefiere:

```c
int main(void)
```

sobre:

```c
int main()
```

cuando estás expresando que `main` no recibe parámetros en esa declaración.

---

# 20 PROBLEMAS TIPO EXAMEN — ENUNCIADO + PENSAMIENTO + SOLUCIÓN

---

# Problema 1 — Máximo de un arreglo

## Enunciado

Lee 10 enteros y muestra el mayor.

## Cómo pensarlo

Necesitas un estado:

```text
max
```

Inicialízalo con el primer elemento.

Después compara desde el segundo.

## Solución

```c
#include <stdio.h>

int main(void) {
    int a[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    int max = a[0];

    for (int i = 1; i < 10; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    printf("Maximo: %d\n", max);

    return 0;
}
```

---

# Problema 2 — Invertir arreglo in-place

## Enunciado

Invierte un arreglo sin utilizar otro arreglo.

## Algoritmo

Dos punteros/índices:

```text
i → izquierda
j → derecha
```

Intercambia y acerca ambos.

## Solución

```c
void invertir(int *a, int n) {
    int i = 0;
    int j = n - 1;

    while (i < j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;

        i++;
        j--;
    }
}
```

---

# Problema 3 — Bubble Sort

## Enunciado

Ordena 8 números de menor a mayor.

## Cómo pensarlo

Compara:

```text
a[j]
a[j+1]
```

Si están al revés, intercambia.

## Solución

```c
void bubble_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int cambiado = 0;

        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                cambiado = 1;
            }
        }

        if (!cambiado) {
            break;
        }
    }
}
```

---

# Problema 4 — Buscar y regresar posición

## Enunciado

Recibe un arreglo y un valor. Devuelve el índice o `-1`.

## Solución

```c
int buscar(const int *a, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }

    return -1;
}
```

---

# Problema 5 — Rotación de tres variables

## Enunciado

Dados:

```text
a
b
c
```

transforma:

```text
a → b
b → c
c → a
```

## Solución

```c
void rotar(int *a, int *b, int *c) {
    int tmp = *c;

    *c = *b;
    *b = *a;
    *a = tmp;
}
```

---

# Problema 6 — MCD

## Algoritmo

Algoritmo de Euclides.

## Solución

```c
int mcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}
```

---

# Problema 7 — Simplificar fracción por referencia

## Solución

```c
void simplificar(int *num, int *den) {
    int d = mcd(*num, *den);

    *num /= d;
    *den /= d;
}
```

Integra:

```text
función
+ puntero
+ dereferencia
+ operador %
+ algoritmo matemático
```

---

# Problema 8 — Palíndromo

## Enunciado

Determina si una cadena se lee igual al revés.

## Solución

```c
#include <string.h>

int palindromo(const char *s) {
    size_t i = 0;
    size_t j = strlen(s);

    if (j == 0) {
        return 1;
    }

    j--;

    while (i < j) {
        if (s[i] != s[j]) {
            return 0;
        }

        i++;
        j--;
    }

    return 1;
}
```

---

# Problema 9 — Contar vocales

```c
int contar_vocales(const char *s) {
    int total = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' ||
            s[i] == 'e' ||
            s[i] == 'i' ||
            s[i] == 'o' ||
            s[i] == 'u' ||
            s[i] == 'A' ||
            s[i] == 'E' ||
            s[i] == 'I' ||
            s[i] == 'O' ||
            s[i] == 'U') {
            total++;
        }
    }

    return total;
}
```

---

# Problema 10 — Matriz transpuesta

## Idea

Si:

```text
A[i][j]
```

el transpuesto contiene:

```text
T[j][i] = A[i][j]
```

## Solución

```c
#define FILAS 3
#define COLS 4

void transponer(
    int a[FILAS][COLS],
    int t[COLS][FILAS]
) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            t[j][i] = a[i][j];
        }
    }
}
```

---

# Problema 11 — Máximo de cada fila

```c
void maximos_fila(int a[][4], int filas, int salida[]) {
    for (int i = 0; i < filas; i++) {
        salida[i] = a[i][0];

        for (int j = 1; j < 4; j++) {
            if (a[i][j] > salida[i]) {
                salida[i] = a[i][j];
            }
        }
    }
}
```

---

# Problema 12 — Punto de silla

## Enunciado

Encuentra un elemento que sea mínimo de su fila y máximo de su columna.

## Idea

Para cada elemento:

1. verifica si es mínimo de su fila;
2. si sí, verifica si es máximo de su columna.

## Solución

```c
#include <stdio.h>

void puntos_silla(int a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            int minimo_fila = 1;
            int maximo_columna = 1;

            for (int k = 0; k < 3; k++) {
                if (a[i][k] < a[i][j]) {
                    minimo_fila = 0;
                }

                if (a[k][j] > a[i][j]) {
                    maximo_columna = 0;
                }
            }

            if (minimo_fila && maximo_columna) {
                printf("Punto silla: [%d][%d]\n", i, j);
            }
        }
    }
}
```

---

# Problema 13 — Struct de empleados

## Definición

```c
typedef struct {
    int id;
    char nombre[50];
    float salario;
} Empleado;
```

## Función por referencia

```c
void aumentar_salario(Empleado *e) {
    e->salario *= 1.15f;
}
```

---

# Problema 14 — Enum + switch

```c
typedef enum {
    APAGADO,
    ENCENDIDO,
    ERROR_DISPOSITIVO
} Estado;
```

Uso:

```c
void imprimir_estado(Estado e) {
    switch (e) {
        case APAGADO:
            printf("Apagado\n");
            break;

        case ENCENDIDO:
            printf("Encendido\n");
            break;

        case ERROR_DISPOSITIVO:
            printf("Error\n");
            break;

        default:
            printf("Desconocido\n");
            break;
    }
}
```

---

# Problema 15 — Bitmask

## Enunciado

Un entero contiene tres flags:

```text
bit 0 = error
bit 1 = batería baja
bit 2 = comunicación
```

## Definición

```c
enum {
    FLAG_ERROR = 1u << 0,
    FLAG_BATERIA = 1u << 1,
    FLAG_COM = 1u << 2
};
```

Activar:

```c
flags |= FLAG_ERROR;
```

Consultar:

```c
if ((flags & FLAG_ERROR) != 0) {
    ...
}
```

Desactivar:

```c
flags &= ~FLAG_ERROR;
```

Invertir:

```c
flags ^= FLAG_ERROR;
```

---

# Problema 16 — Puntero a función

## Enunciado

Crea un menú donde puedas seleccionar suma o resta mediante un puntero a función.

## Solución

```c
#include <stdio.h>

typedef int (*Operacion)(int, int);

int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

Operacion seleccionar(int opcion) {
    if (opcion == 1) {
        return suma;
    }

    return resta;
}

int main(void) {
    Operacion op = seleccionar(1);

    printf("%d\n", op(10, 3));

    return 0;
}
```

---

# Problema 17 — Leer archivo carácter por carácter

```c
#include <stdio.h>

int main(void) {
    FILE *f = fopen("datos.txt", "r");

    if (f == NULL) {
        return 1;
    }

    int c;

    while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }

    fclose(f);

    return 0;
}
```

⚠️ `c` es `int`, no `char`.

---

# Problema 18 — Copia de archivo

```c
#include <stdio.h>

int main(void) {
    FILE *origen = fopen("origen.txt", "r");
    FILE *destino = fopen("destino.txt", "w");

    if (origen == NULL || destino == NULL) {
        if (origen != NULL) {
            fclose(origen);
        }

        if (destino != NULL) {
            fclose(destino);
        }

        return 1;
    }

    int c;

    while ((c = fgetc(origen)) != EOF) {
        fputc(c, destino);
    }

    fclose(origen);
    fclose(destino);

    return 0;
}
```

---

# Problema 19 — CSV sencillo

Archivo:

```text
1,10.5
2,20.0
3,5.5
```

Código:

```c
#include <stdio.h>

int main(void) {
    FILE *f = fopen("precios.csv", "r");

    if (f == NULL) {
        return 1;
    }

    int id;
    float precio;
    float total = 0.0f;

    while (fscanf(f, "%d,%f", &id, &precio) == 2) {
        total += precio;
    }

    printf("Total: %.2f\n", total);

    fclose(f);

    return 0;
}
```

---

# Problema 20 — Proyecto integrador completo

## Enunciado

Crear un sistema de sensores con:

- `.h`;
- `.c`;
- `typedef`;
- `struct`;
- `enum`;
- array;
- función;
- puntero;
- búsqueda;
- archivo;
- bitmask.

## `sensor.h`

```c
#ifndef SENSOR_H
#define SENSOR_H

#include <stddef.h>

typedef enum {
    SENSOR_NORMAL,
    SENSOR_ALERTA
} EstadoSensor;

enum {
    FLAG_ERROR = 1u << 0,
    FLAG_BATERIA_BAJA = 1u << 1,
    FLAG_COMUNICACION = 1u << 2
};

typedef struct {
    unsigned int id;
    char nombre[32];
    float temperatura;
    StateSensor estado;
    unsigned int flags;
} Sensor;

void evaluar_sensor(Sensor *s);
int buscar_max_temperatura(const Sensor *s, size_t n);
int guardar_sensores(const Sensor *s, size_t n, const char *nombre);

#endif
```

⚠️ Hay un error deliberado arriba:

```c
StateSensor
```

no existe.

Debe ser:

```c
EstadoSensor
```

La versión corregida:

```c
typedef struct {
    unsigned int id;
    char nombre[32];
    float temperatura;
    EstadoSensor estado;
    unsigned int flags;
} Sensor;
```

## ¿Por qué este error es bueno?

Porque en un examen debes ser capaz de distinguir:

- typo del identificador;
- error de compilación;
- error lógico;
- error de linker;
- error de ejecución.

---

# CHECKLIST FINAL

Antes de entrar al examen debes poder escribir sin consultar:

```c
int
float
double
char

if
else
switch
case
default

for
while
do while
break
continue

funciones
prototipos
return

*
&
NULL

array[]
matriz[][]
struct
typedef
enum

FILE *
fopen
fclose
fgetc
fputc
fgets
fprintf
fscanf

#define
#include
#ifndef
#define
#endif
extern
```

Y debes poder explicar:

## Memoria

- qué almacena una variable;
- diferencia entre valor y dirección;
- qué es un puntero;
- qué significa desreferenciar;
- por qué `scanf` necesita una dirección;
- diferencia entre array y puntero;
- por qué `sizeof(array)` no es igual a `sizeof(pointer)`.

## Funciones

- paso por valor;
- “paso por referencia” mediante puntero;
- retorno de `void`;
- retorno de `struct`;
- retorno de puntero;
- puntero a función;
- prototipos;
- contratos.

## Arrays

- índices;
- tamaño;
- `sizeof`;
- arrays de `char`;
- matrices;
- búsqueda;
- máximo/mínimo;
- inversión;
- Bubble Sort;
- frecuencias;
- diagonal;
- puntos de silla.

## Strings

- `'\0'`;
- diferencia entre carácter y string;
- `char[]`;
- `char *`;
- `%s`;
- `fgets`;
- `strlen`;
- `strcmp`.

## Módulos

- `.h`;
- `.c`;
- guardas;
- `extern`;
- definición;
- declaración;
- compilación;
- linker.

## Archivos

- `FILE *`;
- `fopen`;
- `NULL`;
- `"r"`, `"w"`, `"a"`;
- `fclose`;
- `fgetc`;
- `fputc`;
- `fgets`;
- `fprintf`;
- `fscanf`;
- `EOF`.

---

# TABLA DE SÍMBOLOS PARA MEMORIZAR

| Símbolo | Significado principal |
|---|---|
| `=` | asignación |
| `==` | comparación de igualdad |
| `!=` | diferente |
| `<` | menor |
| `>` | mayor |
| `<=` | menor o igual |
| `>=` | mayor o igual |
| `&&` | AND lógico |
| `||` | OR lógico |
| `!` | NOT lógico |
| `&x` | dirección de `x` |
| `a & b` | AND bit a bit |
| `*p` | desreferenciar |
| `a * b` | multiplicar |
| `int *p` | puntero a `int` |
| `->` | acceder miembro mediante puntero |
| `.` | acceder miembro de objeto |
| `%` | residuo |
| `++` | incrementar |
| `--` | decrementar |
| `+=` | suma y asignación |
| `-=` | resta y asignación |
| `*=` | multiplicación y asignación |
| `/=` | división y asignación |
| `<<` | shift izquierda |
| `>>` | shift derecha |
| `&=` | AND + asignación |
| `|=` | OR + asignación |
| `^=` | XOR + asignación |
| `~` | NOT bit a bit |
| `[]` | indexación / declaración de array |
| `()` | llamada o parámetros |
| `{}` | bloque |
| `;` | final de declaración/sentencia |
| `#` | directiva del preprocesador |

---

# MINI-RECETARIO DE EXAMEN

## Encontrar máximo

```c
max = a[0];

for (int i = 1; i < n; i++)
    if (a[i] > max)
        max = a[i];
```

## Encontrar mínimo

```c
min = a[0];

for (int i = 1; i < n; i++)
    if (a[i] < min)
        min = a[i];
```

## Buscar

```c
for (int i = 0; i < n; i++)
    if (a[i] == x)
        return i;

return -1;
```

## Swap

```c
tmp = a;
a = b;
b = tmp;
```

## Swap por referencia

```c
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```

## Recorrer matriz

```c
for (int i = 0; i < filas; i++)
    for (int j = 0; j < columnas; j++)
        ...
```

## Contar frecuencia

```c
frecuencia[a[i]]++;
```

## Par / impar

```c
n % 2 == 0
```

## Limpiar entrada

```c
int c;

while ((c = getchar()) != '\n' && c != EOF)
    ;
```

## Validar entero con `scanf`

```c
while (scanf("%d", &n) != 1) {
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
```

## Abrir archivo

```c
FILE *f = fopen("datos.txt", "r");

if (f == NULL) {
    ...
}
```

## Leer archivo

```c
int c;

while ((c = fgetc(f)) != EOF) {
    ...
}
```

## Estructura por referencia

```c
void modificar(Persona *p) {
    p->edad++;
}
```

---

# LAS 15 PREGUNTAS QUE DEBES HACERTE ANTES DE ENTREGAR CÓDIGO

1. ¿Inicialicé todas las variables que necesito?
2. ¿Mis índices empiezan en `0`?
3. ¿Me salí del límite del array?
4. ¿Estoy usando `=` cuando necesito `==`?
5. ¿Mi división es entera o flotante?
6. ¿`scanf` recibió una dirección cuando corresponde?
7. ¿Puede quedar basura en `stdin`?
8. ¿Mi `%c` está comiéndose un `\n`?
9. ¿Necesito `break` en este `switch`?
10. ¿Mi condición de salida realmente cambia?
11. ¿Puede haber división entre cero?
12. ¿Estoy desreferenciando un puntero nulo?
13. ¿Estoy retornando la dirección de una variable local?
14. ¿Abrí y cerré correctamente los archivos?
15. ¿Mi algoritmo funciona para casos frontera?

---

# CASOS FRONTERA QUE DEBES PROBAR

Siempre prueba mentalmente:

```text
0
1
-1
mínimo válido
máximo válido
array de tamaño 1
array vacío (si tu diseño lo permite)
todos los elementos iguales
elemento no encontrado
cadena vacía
cadena de un carácter
entrada inválida
divisor = 0
archivo inexistente
archivo vacío
EOF
```

---

# REGLA MAESTRA PARA LEER C

Cuando veas una línea rara, **léela de adentro hacia afuera**.

Ejemplo:

```c
int *p;
```

Primero:

```text
p
```

`p` es un identificador.

Luego:

```text
*p
```

es puntero.

Y finalmente:

```text
int
```

apunta a `int`.

---

Otro:

```c
int (*fp)(int, int);
```

Busca primero el identificador:

```text
fp
```

Está rodeado por:

```text
(*fp)
```

por tanto `fp` es puntero.

¿Puntero a qué?

```text
(int, int)
```

a una función que recibe dos `int`.

¿Qué devuelve?

```text
int
```

Resultado:

> `fp` es un puntero a una función que recibe dos `int` y devuelve `int`.

---

# REGLA MAESTRA PARA PUNTEROS

Cuando veas:

```c
int *p = &x;
```

tradúcelo mentalmente como:

```text
p contiene la dirección de x
```

Entonces:

```c
*p
```

significa:

```text
ve al lugar cuya dirección está en p
y accede al objeto que vive ahí
```

---

# REGLA MAESTRA PARA FUNCIONES

Cuando veas:

```c
resultado = funcion(a, b);
```

piensa:

```text
1. evaluar argumentos
2. llamar función
3. ejecutar cuerpo
4. return
5. obtener valor de retorno
6. asignarlo a resultado
```

No:

```text
“meter la función dentro de resultado”
```

---

# REGLA MAESTRA PARA ARRAYS

Cuando veas:

```c
int a[10];
```

piensa:

```text
10 objetos int consecutivos
```

No:

```text
“una variable mágica que contiene una lista”
```

---

# REGLA MAESTRA PARA STRUCT

Cuando veas:

```c
typedef struct {
    int id;
    float temperatura;
    char nombre[20];
} Sensor;
```

piensa:

```text
un objeto compuesto
├── id
├── temperatura
└── nombre[20]
```

Y si tienes:

```c
Sensor *p;
```

entonces:

```c
p->temperatura
```

significa:

```c
(*p).temperatura
```

---

# REGLA MAESTRA PARA ARCHIVOS

Piensa:

```text
DISCO
 ↓
fopen
 ↓
FILE *
 ↓
operaciones sobre stream
 ↓
fclose
```

`FILE *` no es “el texto”.

Es una referencia al estado del stream.

---

# CIERRE

Para este examen, el núcleo que debes dominar no es memorizar 200 líneas de C independientes. Es reconocer patrones:

```text
problema
 ↓
algoritmo
 ↓
estructura de control
 ↓
datos
 ↓
función
 ↓
puntero si necesito modificar
 ↓
array/matriz si tengo colección
 ↓
struct si tengo datos heterogéneos
 ↓
archivo si necesito persistencia
```

Y, sobre todo, debes poder mirar una expresión de C y traducirla mentalmente a lenguaje humano.

Ejemplo final:

```c
void ordenar_tres(int *a, int *b, int *c) {
    if (*a > *b)
        swap(a, b);

    if (*b > *c)
        swap(b, c);

    if (*a > *b)
        swap(a, b);
}
```

Lectura:

> “Tengo una función que no devuelve nada. Recibe tres punteros a entero. Compara y, mediante `swap`, modifica directamente los tres enteros originales hasta dejarlos ordenados.”

Esa traducción mental es la habilidad que conecta **sintaxis → memoria → algoritmo → resultado**.

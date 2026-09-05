# Examen práctico 26-P — Sistema de Registro de Ciclismo

## Guía de diseño, codificación y presentación

### 1. Objetivo del programa

Diseñar e implementar un sistema para almacenar y consultar la información de un equipo de hasta 20 ciclistas. Cada ciclista tiene nombre, fecha de nacimiento, teléfono, 12 tiempos de entrenamiento y un tiempo récord. Los tiempos se generan aleatoriamente entre 120 y 240 minutos y el récord es el menor de los 12 tiempos.

El archivo inicial `datos.txt` conserva únicamente nombre, fecha de nacimiento y teléfono. Los tiempos no se almacenan en el archivo: se generan al iniciar cada ejecución, tal como indica el planteamiento. `salida.txt` se utiliza únicamente cuando se selecciona la opción 6.

---

## 2. Especificación de estructuras de datos

### 2.1 Estructura `Nacimiento`

```text
Nacimiento
    dia  : entero
    mes  : entero
    año  : entero
```

Se utiliza una estructura independiente porque la fecha de nacimiento está formada por tres datos relacionados. Esto permite tratar la fecha como una sola unidad y reutilizarla dentro de cada ciclista.

### 2.2 Estructura `Ciclista`

```text
Ciclista
    nombre            : cadena de 25 caracteres
    fecha             : Nacimiento
    telefono          : cadena de 10 dígitos
    entrenamientos    : arreglo de 12 enteros
    record            : entero
```

- `nombre`: almacena el nombre del participante con la longitud indicada en el planteamiento.
- `fecha`: reutiliza la estructura `Nacimiento`.
- `telefono`: se maneja como cadena porque es un identificador de 10 dígitos; no se realizan operaciones aritméticas con él y así se conserva correctamente como dato textual.
- `entrenamientos[12]`: se utiliza un arreglo porque cada ciclista tiene exactamente 12 tiempos relacionados y se consultan por posición.
- `record`: almacena explícitamente el mejor tiempo del ciclista para no tener que recalcularlo cada vez que se necesite.

### 2.3 Arreglo principal

```text
Ciclista equipo[20]
```

Representa al conjunto completo de participantes. El límite de 20 corresponde directamente al máximo indicado en el examen.

---

## 3. Diagrama jerárquico de módulos

```text
PROGRAMA PRINCIPAL
│
├── cargar_datos
│   └── generar_tiempos_y_record
│
├── desplegar menú
│   ├── alta_ciclista
│   │   └── generar_tiempos_y_record
│   │
│   ├── desplegar_informacion
│   │   ├── longitud_texto
│   │   └── imprimir_centrado
│   │
│   ├── busqueda_peor
│   │
│   ├── mejor_rendimiento
│   │
│   ├── mejor_sesion
│   │
│   ├── generar_salida
│   │
│   └── guardar_datos
│
└── finalizar programa
```

El programa principal controla el flujo general. Cada módulo realiza una tarea específica y recibe solamente los datos que necesita.

---

## 4. Especificación de módulos

| Módulo | Función | Entrada | Salida / efecto |
|---|---|---|---|
| `main` | Controlar el programa y el menú | Datos del usuario | Ejecuta las opciones hasta salir |
| `cargar_datos` | Leer participantes desde `datos.txt` | Arreglo de ciclistas, número de ciclistas | Actualiza los participantes cargados |
| `generar_tiempos_y_record` | Generar 12 tiempos y calcular el récord | Un ciclista | Actualiza entrenamientos y récord |
| `alta_ciclista` | Registrar un nuevo participante | Arreglo y contador por referencia | Agrega un ciclista y aumenta el contador |
| `desplegar_informacion` | Mostrar la información en tabla | Arreglo y cantidad | Imprime la tabla |
| `longitud_texto` | Obtener longitud visible del texto | Cadena | Devuelve una longitud entera |
| `imprimir_centrado` | Centrar un texto dentro de un ancho | Cadena y ancho | Imprime texto centrado |
| `busqueda_peor` | Buscar por teléfono y hallar peor tiempo | Arreglo y cantidad | Muestra ciclista, tiempo y sesión |
| `mejor_rendimiento` | Buscar el menor tiempo global | Arreglo y cantidad | Muestra ciclista, tiempo y sesión |
| `mejor_sesion` | Comparar el rendimiento colectivo por sesión | Arreglo y cantidad | Muestra la sesión con menor suma |
| `generar_salida` | Crear `salida.txt` | Arreglo y cantidad | Escribe récords individuales y total |
| `guardar_datos` | Guardar los datos persistentes | Arreglo y cantidad | Actualiza `datos.txt` |

---

## 5. Pseudocódigo de los módulos

> El pseudocódigo se expresa de manera independiente de C, porque el examen solicita diseñar los algoritmos antes de codificarlos. Las únicas operaciones que el planteamiento permite expresar directamente en C dentro del diseño son las relacionadas con archivos.

### 5.1 Programa principal

```text
INICIO
    Crear un arreglo para almacenar hasta 20 ciclistas
    Inicializar cantidad de ciclistas en cero
    Inicializar opción y condición de salida
    Inicializar el generador de números aleatorios

    Cargar los datos existentes desde datos.txt

    MIENTRAS no se haya seleccionado salir
        Mostrar el menú
        Leer la opción

        SEGÚN la opción
            1: registrar un nuevo ciclista
            2: desplegar la información
            3: buscar el peor tiempo de un ciclista
            4: buscar el mejor tiempo global
            5: buscar la mejor sesión grupal
            6: generar salida.txt
            7: guardar datos y terminar
            OTRA: informar que la opción no es válida
        FIN SEGÚN
    FIN MIENTRAS
FIN
```

### 5.2 `cargar_datos`

```text
ABRIR datos.txt para lectura

SI el archivo pudo abrirse
    MIENTRAS no se hayan cargado 20 ciclistas Y existan datos
        Leer nombre
        Leer día, mes y año
        Leer teléfono

        Generar los 12 tiempos del ciclista
        Calcular su récord
        Incrementar la cantidad de ciclistas
    FIN MIENTRAS

    CERRAR archivo
FIN SI
```

### 5.3 `generar_tiempos_y_record`

```text
Inicializar el récord con un valor mayor al máximo permitido

PARA cada una de las 12 sesiones
    Generar un tiempo aleatorio entre 120 y 240 minutos
    Guardarlo en el arreglo de entrenamientos

    SI el tiempo actual es menor que el récord
        Actualizar el récord
    FIN SI
FIN PARA
```

### 5.4 `alta_ciclista`

```text
SI todavía hay espacio para otro participante
    Limpiar la entrada pendiente
    Leer nombre
    Leer fecha de nacimiento
    Leer teléfono

    Generar los 12 tiempos
    Calcular el récord
    Incrementar la cantidad de ciclistas

    Informar registro exitoso
SI NO
    Informar que se alcanzó el máximo de 20
FIN SI
```

### 5.5 `desplegar_informacion`

```text
Definir los nombres de los meses
Mostrar encabezado de la tabla

PARA cada ciclista
    Convertir la fecha a formato día, mes y año
    Convertir el récord de minutos a horas y minutos

    Preparar y mostrar las 12 sesiones en tres grupos de cuatro
    Centrar los textos dentro de las columnas
FIN PARA

Mostrar cierre de la tabla
```

### 5.6 `longitud_texto`

```text
Inicializar longitud en cero

MIENTRAS existan caracteres en el texto
    SI el carácter no corresponde a un byte de continuación UTF-8
        Incrementar longitud
    FIN SI
    Avanzar al siguiente carácter
FIN MIENTRAS

DEVOLVER longitud
```

### 5.7 `imprimir_centrado`

```text
Obtener la longitud visible del texto
Calcular cuántos espacios faltan para completar el ancho
Dividir los espacios entre izquierda y derecha
Ajustar a cero cualquier cantidad negativa
Imprimir espacios, texto y espacios
```

### 5.8 `busqueda_peor`

```text
Leer el teléfono a buscar
Inicializar posición y estado de encontrado

MIENTRAS existan ciclistas y todavía no se encuentre el teléfono
    Comparar el teléfono buscado con el del ciclista actual

    SI coinciden
        Inicializar el peor tiempo

        PARA las 12 sesiones
            SI el tiempo actual es mayor que el peor registrado
                Actualizar peor tiempo y número de sesión
            FIN SI
        FIN PARA

        Mostrar nombre, peor tiempo y sesión
        Marcar como encontrado
    FIN SI

    Avanzar al siguiente ciclista
FIN MIENTRAS

SI no fue encontrado
    Informar que no existe el participante
FIN SI
```

### 5.9 `mejor_rendimiento`

```text
SI existen ciclistas
    Inicializar el mejor tiempo con un valor mayor al máximo posible

    PARA cada ciclista
        PARA sus 12 entrenamientos
            SI el tiempo actual es menor que el mejor registrado
                Guardar tiempo, sesión y ciclista
            FIN SI
        FIN PARA
    FIN PARA

    Mostrar el resultado
SI NO
    Informar que no hay ciclistas
FIN SI
```

### 5.10 `mejor_sesion`

```text
SI existen ciclistas
    Inicializar la sesión ganadora sin seleccionar

    PARA cada una de las 12 sesiones
        Inicializar la suma de la sesión actual

        PARA cada ciclista
            Acumular su tiempo de esa sesión
        FIN PARA

        SI todavía no existe una sesión ganadora O la suma actual es menor
            Guardar la sesión y su suma
        FIN SI
    FIN PARA

    Mostrar la mejor sesión colectiva
SI NO
    Informar que no hay ciclistas
FIN SI
```

### 5.11 `generar_salida`

```text
ABRIR salida.txt para escritura

SI el archivo pudo abrirse
    Inicializar suma de récords

    PARA cada ciclista
        Convertir su récord a horas y minutos
        Escribir nombre y récord en una línea
        Acumular el récord del ciclista
    FIN PARA

    Convertir la suma total a horas y minutos
    Escribir el récord total del equipo
    CERRAR archivo
SI NO
    Informar error de apertura
FIN SI
```

### 5.12 `guardar_datos`

```text
ABRIR datos.txt para escritura

SI el archivo pudo abrirse
    PARA cada ciclista
        Escribir nombre
        Escribir fecha
        Escribir teléfono
        No escribir entrenamientos ni récord
    FIN PARA

    CERRAR archivo
SI NO
    Informar error de escritura
FIN SI
```

---

## 6. Justificación de las decisiones de codificación

### Variables y estructuras

No se utilizan variables globales, porque cada dato debe pertenecer al módulo que lo necesita o viajar explícitamente como parámetro. Esto también cumple una regla expresa del examen.

### Paso de parámetros

- `Ciclista equipo[]` se pasa a los módulos que necesitan consultar o modificar el conjunto de ciclistas.
- `num_ciclistas` se pasa por referencia cuando el módulo puede modificarlo, especialmente en el alta y la carga de datos.
- El ciclista que se modifica para generar tiempos se pasa por referencia, porque el objetivo es actualizar directamente sus entrenamientos y su récord.
- Los datos que solamente se consultan se pasan sin necesidad de crear copias adicionales.

### Arreglos

El arreglo `entrenamientos[12]` permite acceder directamente a cada sesión por índice. Es más simple y ligero que crear 12 variables independientes.

### `for` y `while`

Se usa `for` cuando el número de repeticiones está definido de antemano, por ejemplo, las 12 sesiones de entrenamiento. Se usa `while` cuando la repetición depende de una condición, por ejemplo, leer participantes hasta llegar a 20 o hasta terminar el archivo.

### `switch`

Se utiliza para seleccionar entre las siete opciones del menú porque todas son alternativas discretas de una misma decisión.

### `if`

Se utiliza para decisiones binarias o validaciones puntuales: archivo abierto, participante encontrado, nuevo mínimo, límite de ciclistas, etc.

### Búsqueda y mínimos/máximos

Para encontrar el peor tiempo se conserva el máximo actual. Para encontrar el mejor tiempo se conserva el mínimo actual. No es necesario ordenar los datos porque únicamente se necesita encontrar un valor extremo.

### Archivo `datos.txt`

Se guardan únicamente los datos persistentes solicitados por el examen: nombre, fecha y teléfono. Los tiempos y el récord se consideran datos de trabajo y se vuelven a generar al iniciar el programa.

### Archivo `salida.txt`

Se genera solamente al seleccionar la opción 6 y contiene los récords individuales y el récord total del equipo.

### Control de flujo

El programa evita `continue` y utiliza `break` únicamente dentro de `switch`, en cumplimiento de las reglas del examen. Cada función mantiene una sola responsabilidad y el `main` se limita a coordinar el flujo general.

---

## 7. Documentación interna que conviene agregar al código

Los comentarios deben explicar **qué hace el módulo y para qué**, no repetir literalmente cada línea.

Ejemplo de encabezado para una función:

```c
/*
 * Genera los 12 tiempos de entrenamiento de un ciclista
 * y calcula su tiempo record como el menor de ellos.
 */
```

Encabezados recomendados:

```text
main
    Controla la ejecución del programa y el menú principal.

cargar_datos
    Lee de datos.txt los datos persistentes de los ciclistas.

generar_tiempos_y_record
    Genera los 12 tiempos aleatorios y obtiene el récord.

alta_ciclista
    Registra un nuevo participante y actualiza la cantidad total.

desplegar_informacion
    Presenta todos los participantes en forma de tabla.

longitud_texto
    Calcula la longitud visible del texto para alinear la tabla.

imprimir_centrado
    Imprime un texto centrado dentro de un ancho determinado.

busqueda_peor
    Busca un ciclista por teléfono y determina su peor entrenamiento.

mejor_rendimiento
    Encuentra el menor tiempo entre todos los entrenamientos del equipo.

mejor_sesion
    Compara la suma de los tiempos de cada sesión para hallar la mejor.

generar_salida
    Escribe en salida.txt los récords individuales y el récord del equipo.

guardar_datos
    Guarda en datos.txt los datos persistentes antes de terminar.
```

---

## 8. Guía breve para la presentación

### Apertura

“Mi programa administra un equipo de hasta 20 ciclistas. Los datos persistentes son nombre, fecha y teléfono; los 12 tiempos de entrenamiento se generan al iniciar y el récord se calcula como el menor tiempo.”

### Explicar la estructura

“Separé la fecha en otra estructura porque está formada por tres datos relacionados. Después utilicé una estructura `Ciclista` que agrupa toda la información de cada participante. El arreglo de 12 enteros representa las sesiones y el campo `record` evita recalcular el récord cada vez que se necesita.”

### Explicar la modularización

“El `main` solamente coordina el programa. Cada función realiza una tarea específica: cargar, registrar, mostrar, buscar, comparar, generar salida o guardar. Esto facilita leer, probar y mantener el programa.”

### Explicar la entrada y salida

“`datos.txt` conserva los datos que deben permanecer entre ejecuciones. Los entrenamientos no se almacenan porque el examen indica que deben generarse aleatoriamente al iniciar. `salida.txt` se genera bajo demanda en la opción 6.”

### Explicar los algoritmos

“Para el peor tiempo busco el máximo. Para el mejor tiempo busco el mínimo. Para la mejor sesión sumo los tiempos de todos los ciclistas en cada sesión y comparo las 12 sumas.”

### Cierre

“Todas las opciones del menú trabajan sobre la misma estructura de datos y reciben solamente los parámetros necesarios. Además, el diseño evita variables globales y respeta las restricciones de control indicadas en el examen.”

---

# 9. Preguntas que podrían hacerme en la presentación

### 1. ¿Por qué usaste `typedef`?

Porque permite definir nombres claros para las estructuras y después declarar variables como `Ciclista` o `Nacimiento` sin repetir `struct`.

### 2. ¿Por qué hiciste otra estructura para `Nacimiento`?

Porque día, mes y año forman una sola entidad lógica y así la fecha queda encapsulada dentro de `Ciclista`.

### 3. ¿Por qué el teléfono es `char` y no `int`?

Porque es un identificador formado por dígitos, no una cantidad sobre la que se hagan operaciones. Como cadena también se conserva correctamente cualquier cero inicial.

### 4. ¿Por qué `entrenamientos` es un arreglo?

Porque existen 12 datos del mismo tipo y cada uno corresponde a una sesión diferente.

### 5. ¿Por qué guardas `record` si puedes volver a buscar el mínimo?

Porque el récord es un dato derivado que se consulta varias veces. Guardarlo evita recalcularlo continuamente y hace más directa la lectura de la información.

### 6. ¿Por qué no guardaste los entrenamientos en `datos.txt`?

Porque el planteamiento especifica que al iniciar los tiempos se generan aleatoriamente y al salir se guardan los datos del equipo salvo los tiempos.

### 7. ¿Por qué `datos.txt` tiene tres líneas por ciclista?

Porque el archivo solicitado contiene nombre, fecha de nacimiento y teléfono, cada uno en una línea.

### 8. ¿Por qué los tiempos están entre 120 y 240?

Porque 120 minutos son 2 horas y 240 minutos son 4 horas, que son los límites indicados en el examen.

### 9. ¿Por qué `rand() % 121`?

Porque genera valores de 0 a 120. Al sumar 120 se obtiene el intervalo completo de 120 a 240.

### 10. ¿Cómo calculas el récord?

Recorro las 12 posiciones y conservo el menor tiempo encontrado.

### 11. ¿Por qué usaste `for` para los entrenamientos?

Porque sé de antemano que siempre son exactamente 12 sesiones.

### 12. ¿Por qué usaste `while` para leer el archivo?

Porque no conozco de antemano cuántos ciclistas hay en el archivo; termino cuando no quedan datos o cuando alcanzo 20.

### 13. ¿Por qué usaste `switch` en el menú?

Porque el menú tiene siete opciones discretas y cada opción corresponde a una operación diferente.

### 14. ¿Por qué pasas `num_ciclistas` por referencia al registrar?

Porque la función debe modificar el contador original para que el resto del programa conozca el nuevo número de participantes.

### 15. ¿Por qué `equipo` no se pasa por referencia con `&`?

Porque al pasar un arreglo a una función se trabaja con la misma zona de memoria del arreglo; no es necesario usar `&` para modificar sus elementos.

### 16. ¿Qué diferencia hay entre pasar por valor y por referencia en tu programa?

Por valor uso datos cuando solamente necesito consultarlos. Por referencia uso un parámetro cuando la función debe modificar el dato original.

### 17. ¿Cómo encuentras el peor tiempo?

Busco el máximo de los 12 tiempos del ciclista.

### 18. ¿Cómo encuentras el mejor tiempo global?

Recorro todos los ciclistas y sus 12 sesiones, manteniendo el mínimo global.

### 19. ¿Cómo encuentras la mejor sesión colectiva?

Sumo los tiempos de todos los ciclistas para la sesión 1, luego para la 2 y así hasta la 12. La sesión con menor suma es la mejor.

### 20. ¿Por qué no ordenaste los tiempos?

Porque no necesito ordenar para encontrar un mínimo, un máximo o una suma. Recorrer directamente los datos es más sencillo y suficiente.

### 21. ¿Qué complejidad tiene buscar el mejor tiempo global?

Se recorren `20 × 12` datos como máximo, por lo que el número de comparaciones crece proporcionalmente al número de ciclistas y sesiones.

### 22. ¿Por qué no usaste variables globales?

Porque el examen lo prohíbe y además es mejor que cada módulo reciba explícitamente la información que necesita.

### 23. ¿Por qué no usaste `continue`?

Porque el examen lo prohíbe. La solución puede expresarse mediante condiciones y estructuras de control normales.

### 24. ¿Por qué hay `break`?

Los `break` están únicamente dentro de `switch`, que es el único lugar donde el examen permite utilizarlos.

### 25. ¿Qué pasa si no hay ciclistas?

Las funciones que necesitan participantes comprueban primero si la cantidad es mayor que cero y muestran un mensaje apropiado si no hay datos.

### 26. ¿Qué pasa si `datos.txt` no existe?

La carga inicial simplemente no incorpora participantes; posteriormente el programa puede registrar nuevos ciclistas.

### 27. ¿Qué pasa cuando ya existen 20 ciclistas?

La opción de alta informa que se alcanzó el límite y no agrega otro participante.

### 28. ¿Qué pasa al salir?

La información persistente se escribe nuevamente en `datos.txt` y el programa termina.

### 29. ¿Qué pasa con los tiempos al cerrar el programa?

No se guardan. En la siguiente ejecución vuelven a generarse aleatoriamente, porque el examen indica que los tiempos deben excluirse del archivo.

### 30. ¿Cuál es la ventaja de separar las funciones?

Cada módulo tiene una responsabilidad clara. Eso facilita entender, probar, corregir y reutilizar partes del programa.

### 31. ¿Por qué existe `longitud_texto`?

La tabla utiliza texto en español y algunos caracteres UTF-8 pueden ocupar más de un byte. La función busca obtener una longitud visible útil para alinear las columnas.

### 32. ¿Por qué existe `imprimir_centrado`?

Para evitar repetir el cálculo de espacios en cada columna y mantener la presentación de la tabla dentro de un solo módulo.

### 33. ¿Qué parte del programa modifica directamente la estructura?

El alta modifica un elemento de `equipo`, y `generar_tiempos_y_record` modifica los campos de entrenamientos y récord del ciclista que recibe.

### 34. ¿Qué parte realmente usa manejo de archivos?

`cargar_datos` lee `datos.txt`, `generar_salida` escribe `salida.txt` y `guardar_datos` actualiza `datos.txt`.

### 35. ¿Qué aprendiste con el proyecto?

Principalmente la separación entre diseño y codificación, el uso de estructuras y arreglos, el paso de parámetros y el manejo de archivos dentro de un programa modular.

---

# 10. Tres respuestas que debo poder explicar sin memorizar palabra por palabra

### ¿Por qué esta estructura?

“Porque representa directamente la información que el problema pide y agrupa datos relacionados.”

### ¿Por qué esta función?

“Porque esa tarea tiene una responsabilidad propia y separarla hace el programa más claro y fácil de mantener.”

### ¿Por qué este ciclo?

“Uso `for` cuando conozco el número de repeticiones y `while` cuando dependo de una condición de término.”

---

# 11. Idea central para defender todo el proyecto

```text
El diseño parte del problema.
        ↓
La estructura representa los datos.
        ↓
Los módulos representan las operaciones.
        ↓
El pseudocódigo representa los algoritmos.
        ↓
La codificación implementa esos módulos.
        ↓
El programa prueba la funcionalidad pedida.
```

La defensa debe mostrar que cada decisión del código se puede relacionar con una necesidad concreta del planteamiento.

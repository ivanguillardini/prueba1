# Explicación del Problema y Solución

## Descripción del Problema

El problema consiste en arreglar dos listas de números que son los IDs de ubicaciones donde puede estar el historiador jefe,  proporcionadas por dos grupos de historiadores. Cada lista contiene números únicos, pero las listas no son idénticas. El objetivo es:

1. **Parte 1**: consiste en calcular la distancia total entre las dos listas. Lo que primero hacemos es ordenar ambas listas de números en dos arrays diferentes, se emparejan los números más pequeños de ambas listas y se calcula la diferencia absoluta entre ellos. Luego, se suman todas estas diferencias y daría el resultado de la distancia total.

2. **Parte 2**: consiste en calcular una puntuación de similitud entre las dos listas. Para ello, se cuenta cuántas veces aparece cada número de la lista izquierda en la lista derecha, y se suma el producto de cada número por su frecuencia que aparece en la lista derecha.

## Solución Implementada

El código en C++ resuelve ambas partes del problema. A continuación, se explica cómo funciona:

### Estructura del Código

1. **Entrada de Datos**:
   - El programa lee pares de números desde la terminal. Cada par representa un número de la lista izquierda y este se alamacena en el array dinámico de la izquierda  y otro de la lista derecha que se alamacena en el array dinñamico de la derecha.
   - El usuario puede introducir tantos pares como desee y para  terminar debe poner en la entrada escribiendo `fin`, es decir una vez compiles y al ejectuarlo ./ tendrás que pegar en la terminal tu input y en la ultima línea pones `fin` le das al enter.

    **Ejemplo de Entrada**

    ```
    7   6
    2   3
    8   4
    1   5
    3   9
    fin

2. **Ordenamiento**:
   - Ambas listas se ordenan utilizando el algoritmo de divide y vencerás **Merge Sort** para que ambas listas queden emparejadas y facilite los cálculos posteriores.Este algoritmo funciona de la siguiente forma: divide el conjunto de elementos en subconjuntos más pequeños, los ordena por separado y luego los fusiona para obtener un conjunto ordenado más grande. Este algoritmo utiliza una estrategia de divide y vencerás.

3. **Cálculo de la Diferencia (Parte 1)**:
   - Una vez ordenadas  las lista  se recorre cada par de números y se calcula la diferencia absoluta entre los números emparejados de ambas listas y se suma al total.

4. **Cálculo de la Puntuación de Similitud (Parte 2)**:
   - Se utiliza un `unordered_map` para contar la frecuencia de cada número en la lista derecha.
   - Luego, se recorre la lista izquierda y se suma el producto de cada número por su frecuencia en la lista derecha.

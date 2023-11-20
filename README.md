# Parcial de Reposición

- [Parcial de Reposición](#parcial-de-reposición)
  - [Instrucciones](#instrucciones)
  - [Introducción](#introducción)
  - [Ejercicio 1 (**30** puntos)](#ejercicio-1-30-puntos)
    - [Ejemplo 1.1](#ejemplo-11)
    - [Ejemplo 1.2](#ejemplo-12)
    - [Ejemplo 1.3](#ejemplo-13)
    - [Restricciones](#restricciones)
  - [Ejercicio 2 (**30** puntos)](#ejercicio-2-30-puntos)
    - [Ejemplo 2.1](#ejemplo-21)
    - [Ejemplo 2.2](#ejemplo-22)
    - [Ejemplo 2.3](#ejemplo-23)
    - [Restricciones](#restricciones-1)
  - [Ejercicio 3 (**40** puntos)](#ejercicio-3-40-puntos)
    - [Ejemplo 3.1](#ejemplo-31)
    - [Ejemplo 3.2](#ejemplo-32)
    - [Ejemplo 3.3](#ejemplo-33)
    - [Restricciones](#restricciones-2)

## Instrucciones

1. Para iniciar, debe crear un *Fork* del repositorio:

![fork button](images/fork.png)

2. Vaya la pestaña de **actions** de su repositorio. Si ve un botón verde, haga clic en él para poder ejecutar las pruebas en el futuro.

![actions tab](images/actions.png)

3. Clone el nuevo repositorio en su computadora y ábralo en Visual Studio.

4. En el menú de Visual Studio, en la sección de *Build* o *Compilar*, construya la solución.

5. En el menú de Visual Studio, en la sección de Tests, seleccione *Run All Tests*

6. La mayoría de las pruebas deberían fallar.

## Introducción

- Todos los ejercicios deben compilar para poder ser probados. Si por lo menos uno de los ejercicios no compila, la nota será **cero**.
- Si el código original de un ejercicio no se modifica o la intención de su resolución no es clara, la nota del ejercicicio será de **cero puntos**, aún si hay pruebas que sí pasen para dicho ejercicio.
- NO agregue nuevos métodos `main()`, de lo contrario ninguna prueba podrá ejecutarse.
- NO cambie la firma de los métodos existentes (no agrege más parámetros ni cambie el nombre), estos son utilizados para probar su código.
- NO haga cambios en las pruebas, esto resulta en un **cero inmediato**.
- Puede agregar nuevas clases y/o archivos, como sea necesario.
- Las definiciones de funciones y atributos de las clases se encuentran en archivos `.h`, pero debe implementar las funciones dentro de los `.cpp` equivalentes.
- A continuación encontrará los enunciados de cada uno de los ejercicios. Su nota en cada uno de los ejercicios será la relación entre la cantidad de pruebas que sí pasen sobre la cantidad total de pruebas para ese ejercicio.
- En la pestaña de **Actions** podrá ver como las pruebas se ejecutan con su código implementado (si hace `git push` previamente). En los últimos pasos, puede ver los resultados y su nota:

![results step](images/results.png)
___

## Ejercicio 1 (**30** puntos)

Suponga un arreglo de tamaño `n` ordenado ascendemente y que puede estar rotado de entre `1` y `n` veces. Por ejemplo, el arreglo `nums = [0,1,2,4,5,6,7]` podría convertirse en:

- `[4,5,6,7,0,1,2]` si se rotara 4 veces.
- `[0,1,2,4,5,6,7]` si se rotara 7 veces.

Rotar el arreglo `[a[0], a[1], a[2], ..., a[n-1]]` 1 vez resulta en el arreglo `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Dado el arreglo ordenado `nums` y su longitud `n`, retorne el mínimo de los elementos del arreglo.

Su algoritmo debe resolver el problema con complejidad de tiempo `O(log n)`.

### Ejemplo 1.1

    nums = [3,4,5,1,2]
    resultado = 1

**Explicación:** El arreglo original era `[1,2,3,4,5]` y fue rotado 3 veces.

___

### Ejemplo 1.2

    nums = [4,5,6,7,0,1,2]
    resultado = 0

Explicación: El arreglo original era `[0,1,2,4,5,6,7]` y fue rotado 4 veces.

___

### Ejemplo 1.3

    nums = [11,13,15,17]
    resultado = 11

Explicación: El arreglo original era `[11,13,15,17]` y fue rotado 4 veces.
___

### Restricciones

- `n == nums.length`
- **1** <= `n` <= **5000**
- -**5000** <= `nums[i]` <= **5000**

___

## Ejercicio 2 (**30** puntos)

Dado un **vector** de strings `strings`, agrupe los anagramas. La respuesta puede retornarla en **cualquier orden**.

Un anagrama es una frase o palabra formada al reorganizar el orden de las letras de otra frase o palabra, utilizando las letras originales exactamente una vez.

### Ejemplo 2.1

    strings = ["eat","tea","tan","ate","nat","bat"]
    resultado = [["bat"],["nat","tan"],["ate","eat","tea"]]

### Ejemplo 2.2

    strings = [""]
    resultado = [[""]]

### Ejemplo 2.3

    strings = ["a"]
    resultado = [["a"]]

### Restricciones

- **1** <= `strings.length` <= **10<sup>4</sup>**
- **0** <= `strings[i].length` <= **100**
- `strings[i]` consiste solamente de letras minúsculas del alfabeto.

## Ejercicio 3 (**40** puntos)

Dada lista enlazada de longitud `n` en la cual cada nodo tiene un apuntador adicional, `random`, que apunta a cualquier nodo de la lista o a `nullptr`.

Relice una **copia profunda** de la lista. Esta copia profunda debe consistir de exactamente `n` **nodos completamente nuevos**, en donde el valor de cada uno de los nodos tiene el mismo valor del nodo correspondiente. Tanto el apuntador `next` como el apuntador `random` de los nuevos nodos deben apuntar a los nuevos nodos en la lista copiada de tal manera que los apuntadores en la lista original y en la lista copiada representan estados idéntidos. Ninguno de los apuntadores en la nueva lista debe apuntar a nodos en la lista original.

Por ejemplo, si existen dos nodos `X` y `Y` en la lista original, donde `X.random --> Y`, entonces los nodos copiados `x` y `y` en la lista nueva deben ser `x.random --> y`;

Retorne el nodo **head** de la lista enlazada copiada.

La función `copyList()` recibirá como parámetro únicamente el nodo `head` de la lista original.

### Ejemplo 3.1

![ejemplo 3.1](images/example_3_1.png)

### Ejemplo 3.2

![ejemplo 3.2](images/example3_2.png)

### Ejemplo 3.3

![ejemplo 3.3](images/example_3_1.png)

### Restricciones

- **0** <= `n` <= **1000**
- **-10<sup>4</sup>** <= `Node<int>.val` <= **104**
- `Node<int>.random` apunta a `nullptr` o a algún nodo dentro de la lista enlazada.

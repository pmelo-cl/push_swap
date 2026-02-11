# push_swap
## Descripción

**push_swap** es un proyecto del cursus de 42 cuyo objetivo es ordenar una pila de números enteros utilizando un conjunto limitado de instrucciones y **el menor número de movimientos posible**.

El programa recibe una lista de enteros como argumentos, los coloca en la pila **A** y debe ordenarlos de menor a mayor usando una pila auxiliar **B**.


## Objetivos

- Manipular estructuras de datos (stacks)
- Implementar y optimizar algoritmos de ordenación
- Minimizar el número de operaciones
- Respetar normas estrictas de estilo y memoria

## Reglas del proyecto

- Solo se pueden usar las siguientes instrucciones:

### Operaciones de swap
- `sa` : swap de los dos primeros elementos de A
- `sb` : swap de los dos primeros elementos de B
- `ss` : `sa` y `sb` al mismo tiempo

### Operaciones de push
- `pa` : mueve el primer elemento de B a A
- `pb` : mueve el primer elemento de A a B

### Operaciones de rotate
- `ra` : rota A hacia arriba
- `rb` : rota B hacia arriba
- `rr` : `ra` y `rb` al mismo tiempo

### Operaciones de reverse rotate
- `rra` : rota A hacia abajo
- `rrb` : rota B hacia abajo
- `rrr` : `rra` y `rrb` al mismo tiempo

## Compilación
EL programa se compila con el comando:
```bash
make
```
Para ejecutar el programa se hace con:
 ```bash
 ./push_swap <"numeros a ordenar">.
 ``` 
Ejemplos:
```bash
 ./push_swap 1 4 2 6
 ./push_swap 1 6 3 8 "2 0"
 ./push_swap 0 1 4 2 "7" "8 9" 
 ```
 ## Recursos
 - https://www.geeksforgeeks.org/c/doubly-linked-list-in-c/
 - https://www.w3schools.com/c/c_structs.php
 - El uso de IA se uso para encontrar errores en el codigo cuando no se lograban encontrar por si solos, así como a la hora de ell discutir cual algorimtmo implementar en el proyecto

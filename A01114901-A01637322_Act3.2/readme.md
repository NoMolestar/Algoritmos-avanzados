# Implementacion de los algoritmos Dijkstra and Floyd

## Luis Armando Salazar Lopez A01114901

## Carlos Moises Chavez Jimenez A01637322

### Primer Caso de Prueba

4
0 2 -1 3
-1 0 1 5
2 3 0 -1
3 -1 4 0

Dijkstra :

Floyd :
0 2 3 3
3 0 1 5
2 3 0 5
3 5 4 0

#### Explicación: Utilizamos este caso de prueba por ser el de ejemplo en canvas y por ser el caso más basico

### Segundo caso de Prueba

5
0 6 8 -1 4
-1 0 -1 1 7
-1 4 0 -1 -1
2 -1 5 0 -1
-1 -1 -1 3 0

Dijkstra :

Floyd :
0 6 8 7 4
3 0 6 1 7
7 4 0 5 11
2 8 5 0 6
5 11 8 3 0

#### Explicación: Aumentamos el tamaño de la matriz para verificar su funcionamiento en matrices con vertices impares

### Tercer caso de Prueba

6
0 54513 432 1 -1 -1
54513 0 -1 -1 36 -1
432 -1 0 7364 937 1
1 -1 7364 0 -1 98274
-1 36 937 -1 0 -1
-1 -1 1 98274 -1 0

Dijkstra :

Floyd :
0 1405 432 1 1369 433
1405 0 973 1406 36 974
432 973 0 433 937 1
1 1406 433 0 1370 434
1369 36 937 1370 0 938
433 974 1 434 938 0

#### Explicación: Utilizamos este caso de prueba para verificar que se encuentra el camino más corto. Incluso cuando el pasar por varias aristas representa menos peso que la arista directamente conectada al vertice objetivo

### Cuarto caso de Prueba

6
0 3 5 1 12 6
3 0 8 4 9 9
5 8 0 6 7 1
1 4 6 0 13 4
12 9 7 13 0 8
6 9 1 4 8 0

Dijkstra :

Floyd :
0 3 5 1 12 5
3 0 8 4 9 8
5 8 0 5 7 1
1 4 5 0 12 4
12 9 7 12 0 8
5 8 1 4 8 0

#### Explicación: Utilizamos este caso para verificar su funcionamiento cuando la matriz no tiene ningun infinito. Todas las aristas tienen peso. Así podemos también probar que se encuentra el camino con menos peso. Incluso cuando el pasar por varias aristas es menos pesado que la arista que esta directamente conectada al vertice objetivo

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
node 1 to node 2 : 2
node 1 to node 3 : 3
node 1 to node 4 : 3
node 2 to node 1 : 3
node 2 to node 3 : 1
node 2 to node 4 : 5
node 3 to node 1 : 2
node 3 to node 2 : 3
node 3 to node 4 : 5
node 4 to node 1 : 3
node 4 to node 2 : 5
node 4 to node 3 : 4

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
node 1 to node 2 : 6
node 1 to node 3 : 8
node 1 to node 4 : 7
node 1 to node 5 : 4
node 2 to node 1 : 3
node 2 to node 3 : 6
node 2 to node 4 : 1
node 2 to node 5 : 7
node 3 to node 1 : 7
node 3 to node 2 : 4
node 3 to node 4 : 5
node 3 to node 5 : 11
node 4 to node 1 : 2
node 4 to node 2 : 8
node 4 to node 3 : 5
node 4 to node 5 : 6
node 5 to node 1 : 5
node 5 to node 2 : 11
node 5 to node 3 : 8
node 5 to node 4 : 3

Floyd :
0 6 8 7 4
3 0 6 1 7
7 4 0 5 11
2 8 5 0 6
5 11 8 3 0

#### Explicación: Aumentamos el tamaño de la matriz para verificar su funcionamiento en matrices con vertices impares

### Tercer caso de Prueba

6
0 3 5 1 -1 -1
3 0 -1 -1 9 -1
5 -1 0 7 7 1
1 -1 7 0 -1 4
-1 9 7 -1 0 -1
-1 -1 1 4 -1 0

Dijkstra :
node 1 to node 2 : 3
node 1 to node 3 : 5
node 1 to node 4 : 1
node 1 to node 5 : 12
node 1 to node 6 : 5
node 2 to node 1 : 3
node 2 to node 3 : 8
node 2 to node 4 : 4
node 2 to node 5 : 9
node 2 to node 6 : 8
node 3 to node 1 : 5
node 3 to node 2 : 8
node 3 to node 4 : 5
node 3 to node 5 : 7
node 3 to node 6 : 1
node 4 to node 1 : 1
node 4 to node 2 : 4
node 4 to node 3 : 5
node 4 to node 5 : 12
node 4 to node 6 : 4
node 5 to node 1 : 12
node 5 to node 2 : 9
node 5 to node 3 : 7
node 5 to node 4 : 12
node 5 to node 6 : 8
node 6 to node 1 : 5
node 6 to node 2 : 8
node 6 to node 3 : 1
node 6 to node 4 : 4
node 6 to node 5 : 8

Floyd :
0 3 5 1 12 5
3 0 8 4 9 8
5 8 0 5 7 1
1 4 5 0 12 4
12 9 7 12 0 8
5 8 1 4 8 0

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
node 1 to node 2 : 3
node 1 to node 3 : 5
node 1 to node 4 : 1
node 1 to node 5 : 12
node 1 to node 6 : 5
node 2 to node 1 : 3
node 2 to node 3 : 8
node 2 to node 4 : 4
node 2 to node 5 : 9
node 2 to node 6 : 8
node 3 to node 1 : 5
node 3 to node 2 : 8
node 3 to node 4 : 5
node 3 to node 5 : 7
node 3 to node 6 : 1
node 4 to node 1 : 1
node 4 to node 2 : 4
node 4 to node 3 : 5
node 4 to node 5 : 12
node 4 to node 6 : 4
node 5 to node 1 : 12
node 5 to node 2 : 9
node 5 to node 3 : 7
node 5 to node 4 : 12
node 5 to node 6 : 8
node 6 to node 1 : 5
node 6 to node 2 : 8
node 6 to node 3 : 1
node 6 to node 4 : 4
node 6 to node 5 : 8

Floyd :
0 3 5 1 12 5
3 0 8 4 9 8
5 8 0 5 7 1
1 4 5 0 12 4
12 9 7 12 0 8
5 8 1 4 8 0

#### Explicación: Utilizamos este caso para verificar su funcionamiento cuando la matriz no tiene ningun infinito. Todas las aristas tienen peso. Así podemos también probar que se encuentra el camino con menos peso. Incluso cuando el pasar por varias aristas es menos pesado que la arista que esta directamente conectada al vertice objetivo

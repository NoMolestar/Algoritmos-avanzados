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
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 1

Floyd :
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 1

#### Explicación: Utilizamos este caso de prueba por ser el de ejemplo en canvas y por ser el caso más basico

### Segundo caso de Prueba

5
1 1 1 1 1
0 0 1 0 1
1 1 1 1 1
1 0 0 0 0
1 1 1 1 1

Dijkstra :
1 1 1 0 0
0 0 1 0 0
1 1 1 0 0
1 0 0 0 0
1 1 1 1 1

Floyd :
1 1 1 1 1
0 0 0 0 1
1 1 1 1 1
1 0 0 0 0
1 1 1 1 1

#### Explicación: Utilizamos este caso para verificar que Ramificacion tome el camino más corto, a diferencia de Backtracking

### Tercer caso de Prueba

8
1 0 1 1 1 0 0 0
1 0 1 0 1 0 0 0
1 0 1 0 1 1 0 0
1 1 1 0 1 0 0 0
0 0 0 0 1 0 0 0
1 1 1 1 1 1 0 0
1 0 0 0 0 0 1 0
1 1 1 1 1 1 1 1

Dijkstra :
1 0 1 1 1 0 0 0
1 0 1 0 1 0 0 0
1 0 1 0 1 0 0 0
1 1 1 0 1 0 0 0
0 0 0 0 1 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1

Floyd :
1 0 1 1 1 0 0 0
1 0 1 0 1 0 0 0
1 0 1 0 1 0 0 0
1 1 1 0 1 0 0 0
0 0 0 0 1 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1

#### Explicación: Utilizamos este caso para verificar que ambos se pueden mover hacia todas las direcciones ya sea izquierda, derecha, arriba o abajo

### Cuarto caso de Prueba

8
1 0 1 1 1 0 0 0
1 0 1 0 1 0 0 0
1 0 1 0 1 1 0 0
1 1 1 0 1 0 0 0
0 0 0 0 1 0 0 0
1 1 1 1 1 1 0 0
1 0 0 0 0 0 1 0
1 1 1 1 1 1 1 1

Dijkstra :
1 1 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 1 1 1 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 1 1 1 0 0
0 0 0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0 1 1

Floyd :
1 1 1 1 1 1 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 1 1 1 0 0
0 0 0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0 1 1

#### Explicación: Utilizamos este caso para verificar que ambos pueden trabajar con matrices que tengan dimensiones de doble digito (Grandes). A la par de que comprobamos la diferencia entre el recorrido de backtracking y ramificación

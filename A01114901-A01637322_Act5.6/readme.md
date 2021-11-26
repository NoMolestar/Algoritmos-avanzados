# Actividad 5.6 Implementación de Simulated annealing

## Luis Armando Salazar Lopez A01114901

## Carlos Moises Chavez Jimenez A01637322

## Ingeniería en Tecnologías Computacionales

## Profesor Gildardo Sánchez Ante

## Instituto Tecnológico y de Estudios Superiores de Monterrey

### Comentarios del programa

Este programa implementa nuestra versión de Simulated Annealing (SA) para resolver el problema del agente viajero. Recibimos un archivo .csv con la matriz de distancias entre ciudades. Devolveremos mediante pantalla el recorrido con menos costo encontrado. Y mediante archivo de texto, el costo que se fue obteniendo mediante cada iteración.

### Caso de Prueba con Lectura de Archivo .CSV

Archivo de Entrada: cities_128.csv

Salida:

- Mediante impresión de pantalla:

Temperatura inicial: 9731.55
El costo del camino inicial es: 164443

Ciudad origen Ciudad destino Costo
66 82 726
82 83 582
83 18 539
18 55 51
55 81 126
81 95 234
95 84 1405
84 31 53
31 16 694
16 65 244
65 68 219
68 39 160
39 62 596
62 17 278
17 23 715
23 78 30
78 110 1878
110 91 236
91 118 238
118 72 407
72 103 153
103 11 483
11 53 462
53 94 815
94 43 432
43 47 521
47 87 871
87 27 366
27 5 537
5 126 543
126 124 1283
124 40 1179
40 42 564
42 67 310
67 3 716
3 61 614
61 51 317
51 4 443
4 122 260
122 19 227
19 2 360
2 69 824
69 38 246
38 6 326
6 12 240
12 101 979
101 56 1485
56 71 383
71 0 88
0 90 47
90 107 1785
107 48 1246
48 9 575
9 25 512
25 35 891
35 105 44
105 115 826
115 59 773
59 120 480
120 73 394
73 30 217
30 8 278
8 98 58
98 10 236
10 121 701
121 20 497
20 86 841
86 104 1770
104 119 1333
119 88 706
88 63 1924
63 26 484
26 14 210
14 64 127
64 33 250
33 114 358
114 80 1185
80 85 2198
85 109 523
109 57 387
57 44 416
44 52 958
52 79 248
79 15 333
15 21 768
21 45 322
45 116 1157
116 36 205
36 117 754
117 127 370
127 96 431
96 89 1354
89 97 255
97 92 1037
92 58 1455
58 46 124
46 22 673
22 1 393
1 7 290
7 113 837
113 74 1221
74 111 156
111 99 337
99 29 755
29 112 1546
112 123 1346
123 54 787
54 108 200
108 24 1428
24 37 294
37 13 444
13 41 909
41 28 624
28 106 1375
106 60 384
60 75 216
75 32 95
32 125 640
125 34 200
34 77 298
77 102 195
102 100 326
100 76 1877
76 70 565
70 49 427
49 93 460
93 50 1414
50 66 563

Temperatura final: 7.00649e-44
El costo del camino final es: 78756

- Mediante archivo de texto se muestra la tabla con el número de iteraciones. Para este caso utilizamos 100000. Aquí pondremos como demostración los primero 5. En el archivo de texto generado se muestra completo.

La temperatura inicial es 9731.55
El costo del camino inicial es 164443

Iteración Costo Temperatura
1 163063 9634.23
2 158915 9537.89
3 160604 9442.51
4 161929 9348.09
5 160176 9254.61
.
.
.

La temperatura final es 7.00649e-44
El costo del camino final es 78756

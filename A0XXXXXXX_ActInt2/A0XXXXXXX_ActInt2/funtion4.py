from scipy.spatial import Voronoi, voronoi_plot_2d
import numpy as np
import matplotlib.pyplot as plt

auxList = []

# Leemos el archivo de texto y lo guardamos como lista
f = open("./caso1.txt", "r")
lineas = f.readlines()

# Calculamos donde empiezan las coordenadas en el archivo
aux = int(lineas[0])
num = 2 * aux + 1

# Recorremos las coordenadas para guardarlas
for i in range(aux):

    # Eliminamos los elementos de la cadena que no nos sirven
    ejemplo = lineas[num].replace("(", "")
    ejemplo = ejemplo.replace(")", "")
    ejemplo = ejemplo.replace("\n", "")

    # Separamos en coordenada X y Y
    listCor = ejemplo.split(",")
    corX = listCor[0]
    corY = listCor[1]

    # Agregamos ambos puntos a nuestra lista
    auxList.append([float(corX), float(corY)])

    num += 1
# Convertimos nuestra matriz a un array de Numpy
mat = np.array(auxList)

# Calcular poligonos de Voronoi
vor = Voronoi(mat)


def simple_voronoi(vor, saveas=None, lim=None):
    # Hacer diagrama de Voronoi
    fig = voronoi_plot_2d(
        vor,
        show_points=True,
        show_vertices=True,
        s=4,
        line_width=2,
        line_alpha=0.6,
        point_size=10,
        line_colors="green",
    )

    # Configurar muestreo del diagrama
    fig.set_size_inches(5, 5)
    plt.title("Distribucion de colonias con el servicio contratado")
    plt.axis("equal")

    if lim:
        plt.xlim(*lim)
        plt.ylim(*lim)

    # Mostramos el diagrama
    plt.show()


simple_voronoi(vor, saveas="square", lim=(0, 600))

from scipy.spatial import Voronoi, voronoi_plot_2d
import numpy as np
import matplotlib.pyplot as plt

f = open("./caso1.txt", "r")
lineas = f.readlines()
for linea in lineas:
    print(linea)

# Calculate Voronoi Polygons
points = np.array([[200, 500], [300, 100], [450, 150], [520, 480]])
vor = Voronoi(points)


def simple_voronoi(vor, saveas=None, lim=None):
    # Make Voronoi Diagram
    fig = voronoi_plot_2d(vor, show_points=True, show_vertices=True, s=4)

    # Configure figure
    fig.set_size_inches(5, 5)
    plt.axis("equal")

    if lim:
        plt.xlim(*lim)
        plt.ylim(*lim)

    plt.show()


simple_voronoi(vor, saveas="square", lim=(0, 600))

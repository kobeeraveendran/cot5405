import matplotlib.pyplot as plt
import numpy as np
from itertools import product, combinations

if __name__ == "__main__":
    fig = plt.figure()

    ax = fig.add_subplot(132, projection = '3d')
    r = [0, 5]

    for s, e in combinations(np.array(list(product(r, r, r))), 2):
        if np.sum(np.abs(s - e)) == r[1] - r[0]:
            ax.plot3D(*zip(s, e), color = "black")

    x_equals_y = np.array([[0, 0, 0], [5, 5, 0], [5, 5, 5], [0, 0, 5], [0, 0, 0]])
    y_equals_z = np.array([[0, 0, 0], [0, 5, 5], [5, 5, 5], [5, 0, 0], [0, 0, 0]])
    x_equals_z = np.array([[0, 0, 0], [5, 0, 5], [5, 5, 5], [0, 5, 0], [0, 0, 0]])

    boundaries = [
        x_equals_y, 
        y_equals_z, 
        x_equals_z
    ]

    for slice in boundaries:
        X, Y, Z = zip(*slice)
        ax.plot3D(X, Y, Z)

    ax.set_xlabel('X-axis')
    ax.set_ylabel('Y-axis')
    ax.set_zlabel('Z-axis')

    ax.set_title("Region R for N = 3")

    plt.show()
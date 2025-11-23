"""
Решение СЛАУ методом квадратных корней.

Вариант 4.
"""

# import copy
import math
from matrix import Matrix
import lu

test_matrix = Matrix.from_dsv("""
6 4 1 3 1
4 6 2 6 1
1 2 7 3 6
3 6 3 9 4
1 1 6 4 8
""")

# test_matrix = (
#     line.split()
#     for line in test_matrix.splitlines()
#     if line
# )

# test_matrix = [list(map(float, row)) for row in test_matrix]

# print(list(test_matrix))

test_column = Matrix.column([24, 35, 38, 46, 37])

# order = len(test_matrix)

# assert len(test_matrix) == len(test_matrix[0]) == len(test_column) == order

# zero_vector = [0] * order

# lower = [zero_vector.copy() for _ in range(order)]

# upper = copy.deepcopy(lower)

# print(lower)

# # левое верхнее значение
# lower[0][0] = math.sqrt(test_matrix[0][0])

# # Заполняем первый столбец.
# for i in range(1, order):
#     lower[i][0] = test_matrix[i][0] / lower[0][0]


def decompose(mat_orig):
    assert mat_orig.is_square()
    order = mat_orig.nrows

    lower = Matrix(order, order, filler=0)

    # k - номер слоя
    for k in range(order):

        # диагональный элемент

        lower[k, k] = mat_orig[k, k]
        for j in range(k):
            lower[k, k] -= lower[k, j] ** 2
        lower[k, k] = math.sqrt(lower[k, k])

        # остальной столбец

        for i in range(k+1, order):
            lower[i, k] = mat_orig[i, k]
            for j in range(k):
                lower[i, k] -= lower[i, j] * lower[k, j]
            lower[i, k] /= lower[k, k]

    return lower


# print("L:")

# for row in lower:
#     print(row)


# for i in range(order):
#     for j in range(order):
#         upper[i][j] = lower[j][i]


# print("U:")

# for row in upper:
#     print(row)


# Решаем LY = B, ищем Y

# y = zero_vector.copy()

# for i in range(order):
#     y[i] = test_column[i]
#     for j in range(i):
#         y[i] -= y[j] * lower[i][j]
#     y[i] /= lower[i][i]

# print("Y:", y)


# Решаем L^T X = Y, ищем X

# x = zero_vector.copy()

# for i in reversed(range(order)):
#     x[i] = y[i]
#     for j in reversed(range(i+1, order)):
#         x[i] -= x[j] * upper[i][j]
#     x[i] /= upper[i][i]

# print("X:", x)


def solve(mat, col, debug=False):
    l = decompose(mat)
    u = l.transpose()

    # Решаем LY = B, ищем Y
    y = lu.solve_lower(l, col)

    # Решаем L^T X = Y, ищем X
    x = lu.solve_upper(u, y)

    if debug:
        print('L:')
        print(l)

        print('U:')
        print(u)

        # print('DEBUG:')
        # print(l.multiply(u) - mat)
        # print(l.multiply(y) - col)
        # print(u.multiply(x))

    return x


if __name__ == '__main__':
    result = solve(test_matrix, test_column, debug=True)
    ax = test_matrix.multiply(result)

    print('x =', result)
    print('Ax =', ax)
    print('Ax - b =', ax - test_column)

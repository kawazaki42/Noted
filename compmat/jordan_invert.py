"""
Обращение матрицы методом Жордана-Гаусса

Вариант 4
"""

from math import isclose

DEBUG = False

A = [
    [9, 8, 1, 4, 9],
    [6, 5, 5, 2, 9],
    [5, 7, 9, 9, 1],
    [6, 8, 2, 1, 3],
    [6, 8, 9, 9, 2],
]


def idmat(n):
    result = [None] * n

    for i in range(n):
        result[i] = [0] * n
        result[i][i] = 1

    return result


def jordan(mat):
    n = len(mat)

    assert all(len(row) == n for row in mat)

    b = idmat(n)

    for i in range(n):
        mat[i] += b[i]
        if DEBUG:
            print(mat[i])

    for k in range(n):
        assert not isclose(mat[k][k], 0), "not supported"

        # Пересчитываем все что
        # ПРАВЕЕ но ВОЗМОЖНО ВЫШЕ или НИЖЕ но НЕ В ВЕДУЩЕЙ СТРОКЕ
        for i in range(n):
            if i == k:
                continue
            # столбец свободных коэффицентов также пересчитываем
            for j in range(k+1, n + n):
                mat[i][j] = (
                    mat[i][j] * mat[k][k] -
                    mat[i][k] * mat[k][j]
                ) / mat[k][k]

        # Обнуляем все элементы столбца k кроме ведущего
        for i in range(n):
            if i != k:
                mat[i][k] = 0

        # строку k делим на a[k][k]
        # пересчитываем в обратном порядке, чтобы не забыть a[k][k]
        # столбец свободных коэффицентов также пересчитываем
        for j in reversed(range(k, n+n)):
            mat[k][j] /= mat[k][k]

        assert mat[k][k] == 1

    if DEBUG:
        # pprint(mat)
        for row in mat:
            print(*(round(x, 2) for x in row))

    return [row[n:] for row in mat]


for row in jordan(A):
    print(*(round(x, 2) for x in row))

# print(idmat(5))
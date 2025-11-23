"""
Решение системы линейных уравнений методом LU-разложения.

Вариант 4.
"""

from matrix import Matrix

DEBUG = False

REVISION = 'lower iterates from 0'

# 8 1 2 5 5 21
# 7 9 3 9 3 31
# 8 3 5 7 9 32
# 6 2 2 7 6 23
# 4 1 3 4 6 18

tests = []

_matrix = [
    [8, 1, 2, 5, 5],
    [7, 9, 3, 9, 3],
    [8, 3, 5, 7, 9],
    [6, 2, 2, 7, 6],
    [4, 1, 3, 4, 6],
]

_column = [
    21,
    31,
    32,
    23,
    18,
]

tests.append(
    (Matrix.from_list(_matrix),
     Matrix.column(_column))
)

_matrix = [
    [8, 9, 8, 6, 9],
    [1, 9, 1, 5, 4],
    [4, 4, 5, 5, 5],
    [6, 5, 8, 4, 8],
    [1, 7, 1, 6, 3],
]

_column = [40, 20, 23, 31, 18]

tests.append(
    (Matrix.from_list(_matrix),
     Matrix.column(_column))
)


def decompose(mat_orig):
    """Разложить матрицу на верхне- и нижнетреугольную."""
    # if type(mat_orig) == list:
    if isinstance(mat_orig, list):
        mat_orig = Matrix.from_list(mat_orig)

    assert mat_orig.is_square()

    order = mat_orig.nrows

    # matrix_order = len(mat_orig)

    # _none_row = [0] * matrix_order

    # lower_matrix = [_none_row.copy() for _ in range(matrix_order)]
    # upper_matrix = [_none_row.copy() for _ in range(matrix_order)]
    l = Matrix(order, order, filler=0)
    u = Matrix(order, order, filler=0)

    # основная диагональ верхней матрицы заполнена единицами
    for i in range(order):
        u[i, i] = 1

    # "слой" матрицы номер 0
    # ---

    # Левый столбец нижней матрицы равен левому столбцу исходной
    for i in range(order):
        l[i, 0] = mat_orig[i, 0]

    assert l[0, 0] != 0

    # Ищем первую строку верхней матрицы по формуле
    for j in range(order):
        # NOTE: l[0][0] - постоянный индекс
        u[0, j] = mat_orig[0, j] / l[0, 0]

    # Остальные "слои" матрицы
    # ---

    # k - индекс слоя.
    for k in range(1, order):
        # заполняем столбец с индексом k
        # (постоянный для всего слоя)
        # в нижней матрице.

        # i - индекс элемента столбца
        # (меняется от начала слоя до конца матрицы)
        for i in range(k, order):
            # начальное значение - из исходной матрицы
            l[i, k] = mat_orig[i, k]

            # вычитаем все предыдущие слои.
            # k - индекс предыдущего слоя
            for m in range(k):
                l[i, k] -= l[i, m] * u[m, k]

        # заполняем строку с индексом k
        # (постоянный для всего слоя)
        # в верхней матрице.

        # j - индекс элемента строки
        # меняется от начала слоя до конца матрицы,
        # однако u[k][k] уже есть, и равен 1.
        # его не трогаем.

        for j in range(k+1, order):
            # начальное значение - из исходной матрицы
            u[k, j] = mat_orig[k, j]

            # вычитаем все предыдущие слои.
            # k - индекс предыдущего слоя
            for m in range(k):
                u[k, j] -= l[k, m] * u[m, j]

            u[k, j] /= l[k, k]

    # if DEBUG:
    #     for i in range(order):
    #         print(u[i])

    #     print()

    #     for i in range(order):
    #         print(l[i])

    return l, u


def solve_lower(lower, column):
    """Шаг 2. Решаем систему LY = B"""
    # order = len(lower)
    assert lower.nrows == column.nrows
    order = column.nrows

    # y = [None] * order
    y = Matrix(order, 1)

    # print(y.ncols)

    # первый элемент найти легче всего.
    # y[0] = column[0] / lower[0, 0]

    # k - индекс элемента вектора-столбца
    for k in range(order):
        # ищем решение для y[k] исходя из уравнения номер k

        y[k] = column[k]

        # m - индекс предыдущей неизвестной (элемента вектора y)
        # Обратный ход из метода Гаусса.

        # вычитаем "лишнее" (сумму)
        # вычитаем все что левее диагонали с соответствующим коэффицентом
        for m in range(k):
            y[k] -= y[m] * lower[k, m]

        # делим на коэффицент при нашей переменной (y[k])
        y[k] /= lower[k, k]

    return y


def solve_upper(upper, y):
    """Шаг 3. Решаем систему UX = Y"""
    # order = len(upper)
    assert upper.nrows == y.nrows
    order = y.nrows

    # x = [None] * order
    x = Matrix(order, 1)

    # assert len(x) == len(y)
    # assert x.nrows == y.nrows

    # В верхней матрице идем снизу (как в обычном методе Гаусса)
    # x[-1] = y[-1]

    # k - индекс элемента вектора-столбца
    # k - индекс искомой переменной x[k]
    # k = order-1, ..., 0
    for k in reversed(range(order)):
        # ищем решение для x[k] исходя из уравнения номер k

        x[k] = y[k]

        # m - индекс предыдущей неизвестной (элемента вектора x)
        # Обратный ход из метода Гаусса.

        # вычитаем "лишнее" (сумму)
        # вычитаем все что правее диагонали с соответствующим коэффицентом
        for m in range(k+1, order):
            x[k] -= x[m] * upper[k, m]

        # делим на коэффицент при нашей переменной (y[k])
        x[k] /= upper[k, k]

    return x

def solve(mat, col):
    l, u = decompose(mat)
    y = solve_lower(l, col)
    x = solve_upper(u, y)

    return x

# Проверка
# ===

if __name__ == '__main__':
    # x = solve(test_matrix_2, test_column_2)

    mat, col = tests[1]

    xvec = solve(mat, col)

    # order = len(test_matrix_2)
    order = mat.nrows

    # recomputed_column = [0] * order
    #
    # for i in range(order):
    #     for j in range(order):
    #         # recomputed_column[i] += xvec[j] * test_matrix_2[i, j]
    #         recomputed_column[i] += xvec[j] * tests[1][0][i, j]

    recomputed_column = mat.multiply(xvec)

    print()
    print("x =", xvec)
    print("результирующий столбец: ", recomputed_column)
    print("разница с исходными данными: ", recomputed_column - col)

"""
Решение системы линейных уравнений методом LU-разложения.

Вариант 4.
"""

# 8 1 2 5 5 21
# 7 9 3 9 3 31
# 8 3 5 7 9 32
# 6 2 2 7 6 23
# 4 1 3 4 6 18

test_matrix = [
    [8, 1, 2, 5, 5],
    [7, 9, 3, 9, 3],
    [8, 3, 5, 7, 9],
    [6, 2, 2, 7, 6],
    [4, 1, 3, 4, 6],
]

test_column = [
    21,
    31,
    32,
    23,
    18,
]

# test_matrix = [
#     [8, 9, 8, 6, 9],
#     [1, 9, 1, 5, 4],
#     [4, 4, 5, 5, 5],
#     [6, 5, 8, 4, 8],
#     [1, 7, 1, 6, 3],
# ]

# test_column = [40, 20, 23, 31, 18]

matrix_order = len(test_matrix)

# Шаг 1. Разложение матрицы на верхне- и нижнетреугольную.
# ===

_none_row = [0] * matrix_order

lower_matrix = [_none_row.copy() for _ in range(matrix_order)]
upper_matrix = [_none_row.copy() for _ in range(matrix_order)]

# основная диагональ верхней матрицы заполнена единицами
for i in range(matrix_order):
    upper_matrix[i][i] = 1

# "слой" матрицы номер 0
# ---

# Левый столбец нижней матрицы равен левому столбцу исходной
for i in range(matrix_order):
    lower_matrix[i][0] = test_matrix[i][0]

assert lower_matrix[0][0] != 0

# Ищем первую строку верхней матрицы по формуле
for j in range(matrix_order):
    # NOTE: lower_matrix[0][0] - постоянный индекс
    upper_matrix[0][j] = test_matrix[0][j] / lower_matrix[0][0]

# Остальные "слои" матрицы
# ---

# k - индекс слоя.
for k in range(1, matrix_order):
    # заполняем столбец с индексом k
    # (постоянный для всего слоя)
    # в нижней матрице.

    # i - индекс элемента столбца
    # (меняется от начала слоя до конца матрицы)
    for i in range(k, matrix_order):
        # начальное значение - из исходной матрицы
        lower_matrix[i][k] = test_matrix[i][k]

        # вычитаем все предыдущие слои.
        # k - индекс предыдущего слоя
        for m in range(k):
            lower_matrix[i][k] -= lower_matrix[i][m] * upper_matrix[m][k]

    # заполняем строку с индексом k
    # (постоянный для всего слоя)
    # в верхней матрице.

    # j - индекс элемента строки
    # меняется от начала слоя до конца матрицы,
    # однако upper_matrix[k][k] уже есть, и равен 1.
    # его не трогаем.

    for j in range(k+1, matrix_order):
        # начальное значение - из исходной матрицы
        upper_matrix[k][j] = test_matrix[k][j]

        # вычитаем все предыдущие слои.
        # k - индекс предыдущего слоя
        for m in range(k):
            upper_matrix[k][j] -= lower_matrix[k][m] * upper_matrix[m][j]

        upper_matrix[k][j] /= lower_matrix[k][k]

# Вывод
# ---

for i in range(matrix_order):
    print(upper_matrix[i])

print()

for i in range(matrix_order):
    print(lower_matrix[i])

# Шаг 2. Решаем систему LY = B
# ===

y = [None] * matrix_order

# первый элемент найти легче всего.
y[0] = test_column[0] / lower_matrix[0][0]

# k - индекс элемента вектора-столбца
for k in range(1, matrix_order):
    # ищем решение для y[k] исходя из уравнения номер k

    y[k] = test_column[k]

    # m - индекс предыдущей неизвестной (элемента вектора y)
    # Обратный ход из метода Гаусса.

    # вычитаем "лишнее" (сумму)
    # вычитаем все что левее диагонали с соответствующим коэффицентом
    for m in range(k):
        y[k] -= y[m] * lower_matrix[k][m]

    # делим на коэффицент при нашей переменной (y[k])
    y[k] /= lower_matrix[k][k]

# Шаг 3. Решаем систему UX = Y
# ===

x = [None] * matrix_order

assert len(x) == len(y)

# В верхней матрице идем снизу (как в обычном методе Гаусса)
x[-1] = y[-1]

# k - индекс элемента вектора-столбца
# k = matrix_order-2, ..., 0
for k in reversed(range(matrix_order-1)):
    # ищем решение для x[k] исходя из уравнения номер k

    x[k] = y[k]

    # m - индекс предыдущей неизвестной (элемента вектора x)
    # Обратный ход из метода Гаусса.

    # вычитаем "лишнее" (сумму)
    # вычитаем все что правее диагонали с соответствующим коэффицентом
    for m in range(k+1, matrix_order):
        x[k] -= x[m] * upper_matrix[k][m]

# Проверка
# ===

recomputed_column = [0] * matrix_order

for i in range(matrix_order):
    for j in range(matrix_order):
        recomputed_column[i] += x[j] * test_matrix[i][j]

print()

print(x)

print(recomputed_column)
"""Решение системы линейных алгебраических уравнений методом Гаусса.

Вариант 4
"""

# from pprint import pprint
import copy

DEBUG = True

"Точность вычисления"
EPSILON = 1e-6

test_data = [
    [-6.55, +2.42, +6.56, -2.6,  +6.42,   5.08],
    [-6.58,  +4.0, +7.99, +9.07, +0.87,  -8.42],
    [-3.45, +0.61, +6.27, +4.46, -3.18,   7.32],
    [+1.65, -1.56, +8.93, -4.89, -5.94,  -5.18],
    [-0.83, +8.82, +4.46, -6.58, +7.28,  -9.69]
]


def gauss(matrix, jordan=False, debug=False):
    # допустим, что основная матрица всегда квадратная
    m = len(matrix)
    n = m

    # Прямой ход
    # ==========

    # тогда расширенная имеет n+1 столбцов
    for row in matrix:
        assert len(row) == n+1

    for k in range(m):
        # Если a[k,k] == 0, то ищем a[i,k] != 0
        if abs(matrix[k][k]) < EPSILON:
            for i in range(k+1, m):
                if abs(matrix[i][k]) >= EPSILON:
                    # меняем местами
                    matrix[i], matrix[k] = matrix[k], matrix[i]
                    break
            else:
                # система неоднозначна:
                # либо несовместна, либо имеет бесконечное мн-во решений
                pass
        
        if not jordan:
            # Все что ниже И правее ведущего элемента - пересчитываем
            for i in range(k+1, m):
                # столбец свободных коэффицентов также пересчитываем
                for j in range(k+1, n+1):
                    matrix[i][j] = (matrix[i][j] * matrix[k][k] -
                                    matrix[i][k] * matrix[k][j]) / matrix[k][k]
        else:
            # Пересчитываем все что
            # ПРАВЕЕ но ВОЗМОЖНО ВЫШЕ или НИЖЕ но НЕ В ВЕДУЩЕЙ СТРОКЕ
            for i in range(m):
                if i == k:
                    continue
                # столбец свободных коэффицентов также пересчитываем
                for j in range(k+1, n+1):
                    matrix[i][j] = (matrix[i][j] * matrix[k][k] -
                                    matrix[i][k] * matrix[k][j]) / matrix[k][k]

        if not jordan:
            # Обнуляем элементы НИЖЕ ведущего
            for i in range(k+1, m):
                matrix[i][k] = 0
        else:
            # Обнуляем все элементы столбца k кроме ведущего
            for i in range(m):
                if i != k:
                    matrix[i][k] = 0
        
        # строку k делим на a[k][k]
        # пересчитываем в обратном порядке, чтобы не забыть a[k][k]
        # столбец свободных коэффицентов также пересчитываем
        for j in reversed(range(k, n+1)):
            matrix[k][j] /= matrix[k][k]

        assert matrix[k][k] == 1

    if debug:
        # pprint(matrix)
        for row in matrix:
            print(row)
    
    ### Обратный ход ###

    # Вектор значений переменных
    # (ответ на задачу)
    x = [None] * n

    # ищем значения переменных, начиная с последней.

    # Первая известная переменная.
    x[-1] = matrix[-1][-1]
    assert matrix[-1][-2] == 1

    # k - номер искомой переменной. x[n-1] уже найден
    for k in reversed(range(n-1)):
        # каждую уже известную переменную умножаем на соответствующий
        # столбец и вычитаем их сумму ("примеси") из крайнего правого
        # столбца (столбца свободных коэффицентов). Получаем значение
        # x[k].
        x[k] = matrix[k][n] - sum(matrix[k][j] * x[j]
                                  for j in range(k+1, n))

    return x
    

print("Методом Гаусса:")
result = gauss(copy.deepcopy(test_data), debug=DEBUG)
print(result)

if DEBUG:
    for row in test_data:
        # for i, a in enumerate(row[:-1]):
        m = len(test_data)
        print( sum(row[i] * result[i] for i in range(m)), '==', row[-1] )


print("Методом Жордана-Гаусса:")
result = gauss(copy.deepcopy(test_data), jordan=True, debug=DEBUG)
print(result)

if DEBUG:
    for row in test_data:
        # for i, a in enumerate(row[:-1]):
        m = len(test_data)
        print( sum(row[i] * result[i] for i in range(m)), '==', row[-1] )
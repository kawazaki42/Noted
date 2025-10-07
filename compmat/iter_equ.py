"""
Решение СЛАУ методом простых итераций и методом Зейделя.

Вариант 4.
"""

test_matrix = [
    [44, 1, 1, 1, 5],
    [2, 49, 3, 5, 3],
    [1, 4, 31, 3, 4],
    [1, 4, 1, 34, 5],
    [5, 1, 2, 4, 49],
]

test_column = [56, 122, 112, 85, 70]

DEBUG = True

def solve_iter(mat, col):
    x0 = len(mat) * [0]

    while True:
        if DEBUG:
            print(x0)

        x1 = x0.copy()
        for i, equ in enumerate(test_matrix):
            x1[i] = test_column[i]
            for j, k in enumerate(equ):
                if j == i:
                    continue
                x1[i] -= k * x0[j]
            x1[i] /= equ[i]

        diffs = [abs(x1[m] - x0[m]) for m in range(len(x0))]

        if all(d < 1e-6 for d in diffs):
            break

        x0 = x1

    return x1


def solve_seidel(mat, col):
    x0 = len(mat) * [0]

    while True:
        if DEBUG:
            print(x0)

        x1 = x0.copy()
        # i - номер уравнения
        # а также номер искомой переменной
        for i, equ in enumerate(test_matrix):
            x1[i] = test_column[i]
            # j - номер коэффицента в уравнении
            for j, coef in enumerate(equ):
                if j == i:
                    continue
                elif j < i:
                    x1[i] -= coef * x1[j]
                else:
                    x1[i] -= coef * x0[j]
            x1[i] /= equ[i]

        diffs = [abs(x1[m] - x0[m]) for m in range(len(x0))]

        if all(d < 1e-6 for d in diffs):
            break

        x0 = x1

    return x1


print(solve_iter(test_matrix, test_column))
print('***');
print(solve_seidel(test_matrix, test_column))

# 1 2 3 2 1 = кайф


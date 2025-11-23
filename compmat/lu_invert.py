"""
Нахождение обратной матрицы методом LU-разложения.

Вариант 4
"""

from matrix import Matrix
import lu

test = Matrix.from_dsv("""
9 8 1 4 9
6 5 5 2 9
5 7 9 9 1
6 8 2 1 3
6 8 9 9 2
""")

# assert test.is_square()

# test_matrix = [map(int, line.split()) for line in test_matrix]

# test_matrix = [list(i) for i in test_matrix]

# print(test_matrix)

def invert(orig_mat):
    assert orig_mat.is_square()

    l, u = lu.decompose(orig_mat)

    linv = invert_triangle(l, upper=False)
    # matrix_print( matrix_multiply(l, linv) )

    uinv = invert_triangle(u, upper=True)
    # matrix_print( matrix_multiply(u, uinv) )

    # return matrix_multiply(uinv, linv)

    return uinv.multiply(linv)


# def matrix_multiply(a, b):
#     result_rows = len(a)
#     result_cols = len(b[0])
#     result = matrix_filled(result_rows, result_cols, filler=0)

#     assert len(a[0]) == len(b)
#     vec_size = len(b)

#     for i in range(result_rows):
#         for j in range(result_cols):
#             for m in range(vec_size):
#                 result[i][j] += a[i][m] * b[m][j]

#     return result


def invert_triangle(mat, upper=False):
    # order = len(mat)
    # assert mat.nrows == mat.ncols
    assert mat.is_square

    order = mat.nrows

    inv = Matrix(order, order, filler=0)

    # диагональ
    for i in range(order):
        inv[i, i] = 1 / mat[i, i]

    ir = range(order)
    if upper:
        ir = reversed(ir)

    for i in ir:
        if not upper:
            jr = range(i)
        else:
            jr = range(i+1, order)
            jr = reversed(jr)

        for j in jr:
            if not upper:
                mr = range(j, i)
            else:
                mr = range(i+1, j+1)

            for m in mr:
                inv[i, j] += mat[i, m] * inv[m, j]
            inv[i, j] *= -inv[i, i]

    return inv


# print(test_matrix)

# def matrix_filled(rows, cols, filler=None):
#     result = []

#     for i in range(rows):
#         result.append([filler] * cols)

#     return result

# def matrix_print(mat, end='\n'):
#     for line in mat:
#         line = (round(elem, 2) for elem in line)
#         print(*line)
#         # for elem in line:
#         #     print()

#     print(end=end)

# matrix_print(l)

# print()

# matrix_print(u)

if __name__ == '__main__':
    # matrix_print( matrix_multiply( *lu.decompose(test_matrix) ) )
    # print()
    result = invert(test)

    # matrix_print(result)

    print(result)

    # matrix_print( matrix_multiply(result, test_matrix) )

    print("проверка: умножим входную матрицу на обратную")

    print( test.multiply(result) )

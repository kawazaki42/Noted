from matrix import Matrix
import lu_invert
import sqrt

# вариант 4

test = Matrix.from_dsv("""
5 3 4 3 3
3 5 3 1 1
4 3 9 2 5
3 1 2 8 3
3 1 5 3 6
""")


def invert(mat):
    lower = sqrt.decompose(mat)
    linv = lu_invert.invert_triangle(lower, upper=False)
    uinv = linv.transpose()

    return uinv.multiply(linv)


if __name__ == '__main__':
    result = invert(test)
    print(result)
    print("проверка: умножим входную матрицу на обратную")
    print( test.multiply(result) )

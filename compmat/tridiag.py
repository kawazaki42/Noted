"""
Решение трехдиагональных СЛАУ методом прогонки

Вариант 4
"""

# центральная диагональ
# c = [7, 7, 4, 8, 9]
c = [2, -2, -5, 3, -5]

# диагональ ниже центральной
# l = [None, 8, 6, 2, 3]
l = [None, 3, 7, 4, 2]

# диагональ выше центральной
# r = [3, 8, 2, 3, None]
r = [5, 8, -5, 9, None]

# результирующий столбец
# f = [10, 23, 12, 13, 12]
f = [5, 4, 3, 2, 1]


def get_p(k):
    if k == 0:
        return f[0] / c[0]

    n = f[k] - l[k] * get_p(k-1)
    d = c[k] - l[k] * get_q(k-1)

    return n/d


def get_q(k):
    if k == 0:
        return r[0] / c[0]

    d = c[k] - l[k] * get_q(k-1)

    return r[k]/d



def main(c, l, r, f):
    n = len(c)

    x = [None] * n

    x[-1] = get_p(n-1)

    for k in reversed(range(n-1)):
        x[k] = get_p(k) - get_q(k) * x[k+1]

    return x


if __name__ == '__main__':
    print( main(c, l, r, f) )
import pprint


class Matrix:

    def __init__(self, nrows, ncols, filler=None):
        self.nrows = nrows
        self.ncols = ncols

        self._data = []

        for i in range(nrows):
            self._data.append([filler] * ncols)

        assert self.is_size_valid()

    @classmethod
    def from_list(cls, list):
        self = cls(len(list), len(list[0]))

        self._data = list

        if not self.is_size_valid():
            raise ValueError

        return self

    @classmethod
    def column(cls, list):
        data = [[elem] for elem in list]

        return cls.from_list(data)

    def to_list(self):
        return self._data

    def column_to_list(self):
        assert self.ncols == 1

        return [r[0] for r in self._data]

    @classmethod
    def from_dsv(cls, values, delimiter=None, elemtype=float):
        values = values.strip()

        rows = values.splitlines()

        data = [elemtype(r.split(delimiter)) for r in rows]

        self = cls(len(data), len(data[0]))
        self._data = data

        if not self.is_size_valid():
            raise ValueError

        return self

    def is_size_valid(self):
        if len(self._data) != self.nrows:
            return False

        for row in self._data:
            if len(row) != self.ncols:
                return False

        return True

    def is_square(self):
        assert self.is_size_valid()

        return self.nrows == self.ncols

    def __str__(self):
        if self.ncols == 1:
            return str(self.column_to_list())

        return pprint.pformat(self._data)

    def __getitem__(self, ij):
        if not isinstance(ij, tuple):
            if self.ncols == 1:
                return self._data[ij][0]

        i, j = ij
        return self._data[i][j]

    def __setitem__(self, ij, value):
        if not isinstance(ij, tuple):
            if self.ncols == 1:
                self._data[ij][0] = value
                return

        i, j = ij
        self._data[i][j] = value

    def __iter__(self):
        return iter(self._data)

    def multiply(self, other):
        if self.ncols != other.nrows:
            raise ValueError

        vecsize = self.ncols

        result = Matrix(self.nrows, other.ncols, filler=0)

        for i in range(self.nrows):
            for j in range(self.ncols):
                for k in range(vecsize):
                    result[i, j] += self[i,k] * other[k,j]

        return result


import pprint
import copy


class Matrix:
    round_to = 2

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
        data = [[elemtype(e) for e in r.split(delimiter)] for r in rows]

        # for i in range(self.nrows):
        #     for j in range(self.ncols):
        #         rows[i][j]

        self = cls(len(data), len(data[0]))
        self._data = data

        if not self.is_size_valid():
            raise ValueError

        return self

    def copy(self):
        return Matrix.from_list(copy.deepcopy(self.to_list()))

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
            # return str(self.column_to_list())
            return str([round(r[0], self.round_to) for r in self._data])

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

    def __add__(self, other):
        result = self.copy()
        result += other
        return result

    def __neg__(self):
        result = self.copy()
        for i in range(self.nrows):
            for j in range(self.ncols):
                result[i,j] = -result[i,j]
        return result

    def __isub__(self, other):
        self += -other
        return self

    def __sub__(self, other):
        return self + -other

    def __iadd__(self, other):
        scalar_add = not isinstance(other, Matrix)

        if not scalar_add:
            if (self.nrows == other.nrows) and (self.ncols == other.ncols):
                pass
            else:
                raise ValueError

        for i in range(self.nrows):
            for j in range(self.ncols):
                if scalar_add:
                    self._data[i][j] += other
                else:
                    self._data[i][j] += other[i, j]

        return self

    def __iter__(self):
        return iter(self._data)

    def multiply(self, other):
        if self.ncols != other.nrows:
            raise ValueError

        vecsize = self.ncols

        result = Matrix(self.nrows, other.ncols, filler=0)

        for i in range(result.nrows):
            for j in range(result.ncols):
                for k in range(vecsize):
                    result[i, j] += self[i,k] * other[k,j]

        return result


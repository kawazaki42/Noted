#ifndef DUMB_COMPLEX_HPP
#define DUMB_COMPLEX_HPP

#include <string>


namespace dumb {
    /// Комплексное число.
    struct complex {
        /// Вещественная часть.
        double real;
        /// Мнимая часть.
        double imag;

        /// Нулевое комплексное число (0+0i).
        complex();

        // complex(const double real);

        /// Комплексное число с указанными вещественной и мнимой частью.
        ///
        /// Мнимая часть нулевая по умолчанию, поэтому возможно неявное
        /// преобразование из обычного числа
        complex(const double real, const double imag = 0);

        /// Сложение комплексных чисел (по компонентам).
        complex operator +(const complex &other) const;
        /// Вычитание комплексных чисел (по компонентам).
        complex operator -(const complex &other) const;
        /// Умножение комплексных чисел (по закону дистрибутивности).
        complex operator *(const complex &other) const;

        /// Вычислить аргумент комплексного числа в радианах.
        ///
        /// Аргумент - это угол между осью Ox и вектором (real, imag).
        double arg() const;

        /// Модуль (абсолютное значение) комплексного числа.
        ///
        /// Модуль - это длина вектора (real, imag)
        double abs() const;

        /// Строковое представление.
        std::string to_string() const;

        // /// Преобразовать из строки.
        // static complex from_string(const std::string &s);
    };

    /// Равенство.
    bool operator ==(const complex &a, const complex &b);

    /// Ввод с `istream` (напр. файлы, `cin`)
    std::istream &operator >>(std::istream &s, complex &c);
}

#endif  // DUMB_COMPLEX_HPP

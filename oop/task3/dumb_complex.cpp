#include <cassert>
#include <cmath>
#include <format>
#include <istream>
#include <string>
#include "dumb_complex.hpp"


namespace dumb {
    /// Комплексное число с указанными вещественной и мнимой частью.
    ///
    /// Мнимая часть нулевая по умолчанию, поэтому возможно неявное
    /// преобразование из обычного числа
    complex::complex(const double real, const double imag):
        real(real), imag(imag) {}

    // complex::complex(const double real): complex(real, 0) {}

    /// Нулевое комплексное число (0+0i).
    complex::complex(): complex(0, 0) {}

    /// Сумма
    complex complex::operator +(const complex &other) const {
        return {real + other.real, imag + other.imag};
    }

    /// Разность
    complex complex::operator -(const complex &other) const {
        return {real - other.real, imag - other.imag};
    }

    /// Произведение (по закону дистрибутивности)
    complex complex::operator *(const complex &other) const {
        return {
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        };
    }

    /// Модуль (абсолютное значение)
    double complex::abs() const {
        /// hypot вычисляет корень суммы квадратов.
        return std::hypot(real, imag);
    }

    /// Аргумент
    double complex::arg() const {
        /// atan2(y, x) работает как atan(y/x) (обычный арктангенс),
        /// но также учитывает знаки аргументов.
        return std::atan2(imag, real);
    }

    /// Строковое представление
    std::string complex::to_string() const {
        // std::string imag_s = std::to_string(imag);
        char imag_sign = imag < 0 ? '-' : '+';

        // if(imag < 0)
        //     imag_s = "- " + imag_s;

        return std::format(
            "{} {} {}i", real, imag_sign, std::abs(imag)
        );
    }

    // /// Преобразовать из строки.
    // complex complex::from_string(const std::string &s) {

    // }

    /// Ввод с `istream` (напр. файлы, `cin`)
    std::istream &operator >>(std::istream &s, complex &c) {
        char sign;
        char i{'\0'};

        s >> c.real >> std::ws >> sign >> std::ws >> c.imag >> i;

        if(i != 'i')
            s.setstate(std::istream::failbit);

        if(sign == '-') {
            c.imag = -c.imag;
        } else if(sign != '+') {
            s.setstate(std::istream::failbit);
        }

        return s;
    }


    /// Равенство.
    bool operator ==(const complex &a, const complex &b) {
        return (
            a.real == b.real and
            a.imag == b.imag
        );
    }

    /// Запустить набор тестов.
    ///
    /// Если один из тестов не пройден, завершает программу с ошибкой.
    /// Если все тесты пройдены, ничего не делает.
    void test() {
        {
            dumb::complex c{3, 4};
            assert( std::abs(c.real - 3) < 1e-6 );
            assert( std::abs(c.imag - 4) < 1e-6 );

            auto d = c + 5;

            dumb::complex e{8, 4};
        
            assert( (d - e).abs() < 1e-6 );
        }

        {
            dumb::complex c;
            assert( std::abs(c.real) < 1e-6);
            assert( std::abs(c.imag) < 1e-6);
        }

        {
            dumb::complex a{1, 2};
            dumb::complex b{3, 4};

            dumb::complex c{ a*b };

            assert(std::abs(c.real + 5) < 1e-6);
            assert(std::abs(c.imag - 10) < 1e-6);
        }

        {
            dumb::complex z{3, 4};
            assert(z.arg() - 0.927 < 0.001);
        }

        {
            dumb::complex z{-3, -4};
            assert(z.abs() - 5 < 1e-6);
        }
    }
}

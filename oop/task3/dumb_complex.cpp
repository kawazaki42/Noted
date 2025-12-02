#include <cmath>
#include <format>
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

    /// Равенство.
    bool operator ==(const complex &a, const complex &b) {
        return (
            a.real == b.real and
            a.imag == b.imag
        );
    }
}

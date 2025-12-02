#include <cmath>
#include "dumb_complex.hpp"


namespace dumb {
    complex::complex(double real, double imag): real(real), imag(imag) {}
    complex::complex(): complex(0, 0) {}

    complex complex::operator +(const complex &other) const {
        return {real + other.real, imag + other.imag};
    }

    complex complex::operator -(const complex &other) const {
        return {real - other.real, imag - other.imag};
    }

    complex complex::operator *(const complex &other) const {
        return {
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        };
    }

    double complex::abs() const {
        return std::hypot(real, imag);
    }

    double complex::arg() const {
        return std::atan2(imag, real);
    }
}

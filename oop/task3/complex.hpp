// https://github.com/VetrovSV/OOP/blob/master/Задания%20I.md#задание-1-простой-класс

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

// #include <complex.>
#include <format>
#include <cmath>


namespace fake {
    template<typename R>
    struct complex {
    // public:
        R real, imag;

        complex(): real(0), imag(0) {}
        // implicit
        complex(const R real, const R imag): real(real), imag(imag) {}
        complex(const R real): real(real), imag(0) {}

        // R get_real() const {
        //     return real;
        // }

        // R get_imag() const {
        //     return imag;
        // }

        // void operator +=(double other);
        complex &operator +=(const complex &other) {
            real += other.real;
            imag += other.imag;
            return *this;
        }

        // complex operator +(const complex &other) const {
        //     // complex result = *this;
        //     // result += other;
        //     // return result;
        //     return {real + other.real, imag + other.imag};
        // }

        complex &operator *=(const complex &other) {
            return *this = *this * other;
        }

        complex &operator -=(const complex &other) {
            real -= other.real;
            imag -= other.imag;
            return *this;
        }

        complex operator -(const complex &other) {
            return {real + other.real, imag + other.imag};
        }

        complex operator *(const complex<R> &other) const {
            return {
                real * other.real - imag * other.imag,
                real * other.imag + imag * other.real
            };
        }

        inline R abs() const {
            return std::hypot(real, imag);
        }

        R arg() const {
            // arcsin(imag / (2 * std::hypot(real, imag)));
            // return std::atan(imag/real);
            return std::atan2(imag, real);
        }

        std::string to_string() const {
            return std::format("{} + {}_i", real, imag);
        }
    };

    template<typename A, typename B>
    complex<A> operator +(const complex<A> &a, const complex<B> &b) {
        // complex result = *this;
        // result += other;
        // return result;
        return {a.real + b.real, a.imag + b.imag};
    }

    // template<typename A, typename B>
    // fake::complex<B> std::operator +(const A a, const fake::complex<B> &b) {
    //     return {a + b.real, b.imag};
    // }

    template<typename A, typename B>
    fake::complex<B> std::operator +(const A a, const fake::complex<B> &b) {
        return {a + b.real, b.imag};
    }

    // template struct complex<long double>;

    // template<typename R>
    complex<long double> operator ""_i(const long double imag) {
        // return complex<long double>(0, imag);
        return {0, imag};
    }

    complex<unsigned long long> operator ""_i(const unsigned long long imag) {
        // return complex<long double>(0, imag);
        return {0, imag};
    }
}


// template<typename R>
// void fake::complex<R>::operator +=(const complex &other) {
//     real += other.real;
//     imag += other.imag;
// }


// template<typename R>
// // by value intentionally
// fake::complex<R> fake::complex<R>::operator +(complex &other) const {
//     other += *this;
//     return other;
// }


// template<typename R>
// void fake::complex<R>::operator *(complex &other) const {
//     auto new_real = real * other.real - imag * other.imag;
//     auto new_imag = real * other.imag + imag * other.real;

//     return complex(new_real, new_imag);
// }


// template <typename R>
// fake::complex<R>::complex(): real(0), imag(0) {}


// template <typename R>
// fake::complex<R>::complex(R real, R imag): real(real), imag(imag) {}


#endif

// https://github.com/VetrovSV/OOP/blob/master/Задания%20I.md#задание-1-простой-класс

#ifndef COMPLEX_HPP
#define COMPLEX_HPP


namespace fake {
    template<typename R>
    class complex {
        R real, imag;

    public:
        complex();
        complex(const R real, const R imag = 0);

        R get_real() const {
            return real;
        }

        R get_imag() const {
            return imag;
        }

        // void operator +=(double other);
        void operator +=(const complex<R> &other);
        complex<R> operator +(const complex<R>) const;
        void operator *(const complex<R> &other) const;
    };

    complex<double> operator ""_i(long double imag);
}


template<typename R>
void fake::complex<R>::operator +=(const complex &other) {
    real += other.real;
    imag += other.imag;
}


template<typename R>
// by value intentionally
fake::complex<R> fake::complex<R>::operator +(complex other) const {
    other += *this;
    return other;
}


template<typename R>
void fake::complex<R>::operator *(complex &other) const {
    auto new_real = real * other.real - imag * other.imag;
    auto new_imag = real * other.imag + imag * other.real;

    return complex(new_real, new_imag);
}


template <typename R>
fake::complex<R>::complex(): real(0.0), imag(0.0) {}


template <typename R>
fake::complex<R>::complex(R real, R imag): real(real), imag(imag) {}


#endif

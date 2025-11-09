#include "complex.hpp"


// void fake::complex::operator +=(double other) {
//     real += other;
// }


// void fake::complex::operator *=(complex &other) {
//     real * other.real - imag * other.imag
// }



// void fake::complex::operator +=(complex &other) {
//     real += other.real;
//     imag += other.imag;
// }


// fake::complex::complex(): real(0.0), imag(0.0) {}


// fake::complex::complex(double real, double imag): real(real), imag(imag) {}


fake::complex<double> fake::operator ""_i(long double imag) {
    return complex<double>(0, imag);
}
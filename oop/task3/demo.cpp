#include <cstddef>
#include <ios>
#include <iostream>
// #include "complex.hpp"
#include "dumb_complex.hpp"

using std::cout, std::endl;
// using fake::operator""_i;


int main() {
    // cout << (3 + 4_i).to_string() << endl;
    // fake::complex{5, 6} + 5;
    // 5 - fake::complex{5, 6};
    // 4_i - 1;
    // dumb::complex{5, 6} - 5;
    // fake::complex<double> c = 5;
    // cout << (fake::complex<double>{0, -5} - fake::complex<double>{2, 3}).to_string() << endl;

    cout << dumb::complex(-3, 4).to_string() << endl;

    dumb::complex c{1, 2};

    cout << (c + 5).to_string() << endl;

    cout << std::boolalpha << (c + 5 != dumb::complex{6, 2}) << endl;

    // c += {3, 4};

    /// динамический объект
    dumb::complex *pc = new dumb::complex{13, 37};
    cout << pc->to_string() << endl;
    delete pc;

    /// статический массив из объектов
    dumb::complex cs[10];  // 10 конструкторов сразу

    cs[5].imag = 100;

    for(auto &c: cs) {
        cout << c.to_string() << ' ';
    }
    cout << endl;

    /// динамический массив из объектов
    dumb::complex *dcs;
    dcs = new dumb::complex[10];  // 10 вызовов конструкторов

    cs[5].imag = 100;

    // foreach не работает
    for(size_t i = 0; i < 10; i++) {
        cout << c.to_string() << ' ';
    }
    cout << endl;

    delete[] dcs;

    /// (статический) массив из указателей на объекты
    dumb::complex *pcs[10];

    for(size_t i = 0; i < 10; i++) {
        // по одному конструктору за раз
        pcs[i] = new dumb::complex{0, (double)i};
    }

    for(auto p: pcs) {
        cout << p->to_string() << ' ';
    }
}

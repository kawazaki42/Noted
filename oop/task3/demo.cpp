#include <cassert>
#include <cstddef>
#include <ios>
#include <iostream>
#include <fstream>
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

    // cout << dumb::complex(-3, 4).to_string() << endl;

    /// статический объект
    dumb::complex c{3, 4};
    cout << (c + 5).to_string() << endl;

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


    // c += {3, 4};

    /// динамический объект
    dumb::complex *pc = new dumb::complex{13, 37};
    cout << pc->to_string() << endl;
    delete pc;

    /// статический массив из объектов
    dumb::complex cs[10];  // 10 конструкторов сразу

    // изменим один из объектов
    cs[5].imag = 100;

    for(auto &c: cs) {
        cout << c.to_string() << "  ";
    }
    cout << endl;

    /// динамический массив из объектов
    dumb::complex *dcs;
    dcs = new dumb::complex[10];  // 10 вызовов конструкторов

    cs[5].imag = 100;

    // foreach не работает
    for(size_t i = 0; i < 10; i++) {
        cout << c.to_string() << "  ";
    }
    cout << endl;

    delete[] dcs;

    /// (статический) массив из указателей на объекты
    dumb::complex *pcs[10];  // ни один конструктор не вызван

    for(size_t i = 0; i < 10; i++) {
        // по одному конструктору за раз
        pcs[i] = new dumb::complex{0, (double)i};
    }

    // foreach работает; p - указатель
    for(auto p: pcs) {
        cout << p->to_string() << "  ";
        delete p;
    }
    cout << endl;
    
    const std::string fname{"complex.txt"};

    {
        // вывод в файл
        std::ofstream f{fname};
        f << c.to_string() << endl;
    }

    {
        // ввод из файла
        std::ifstream f{fname};
        dumb::complex c, e{3, 4};
        f >> c;
        assert((c - e).abs() < 1e-6);
        std::cout << c.to_string();
    }
}

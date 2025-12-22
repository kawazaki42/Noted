#include <cassert>
#include <cstddef>
#include <iostream>
#include <fstream>
// #include "complex.hpp"
#include "dumb_complex.hpp"

using std::cout, std::endl;
// using fake::operator""_i;
using std::literals::operator ""s;


int main(int argc, char **argv) {
    // проверка: включен ли assert?
    if(argc-1 >= 1 and argv[0+1] == "--fail"s) {
        std::cerr << "Проверка на выполнение тестов." << endl;
        std::cerr << "Если assert включен, программа должа упасть..." << endl;
        assert(false);
        std::cerr << "assert отключен! тесты не запускаются!" << endl;
    }

    // тесты

    dumb::test();
    
    const std::string fname{"complex.txt"};

    {
        // вывод в файл
        dumb::complex c{3, 4};
        std::ofstream f{fname};
        f << c.to_string() << endl;
    }

    {
        // ввод из файла
        std::ifstream f{fname};
        dumb::complex c, e{3, 4};
        f >> c;
        assert((c - e).abs() < 1e-6);
        std::cout << c.to_string() << endl;
    }


    // демонстрация

    /// статический объект
    dumb::complex c{3, 4};
    cout << (c + 5).to_string() << endl;

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

    /// динамический массив из (статических) объектов
    dumb::complex *dcs;
    dcs = new dumb::complex[10];  // 10 вызовов конструкторов

    // изменим один из объектов
    dcs[4].imag = 200;

    // foreach не работает
    for(size_t i = 0; i < 10; i++) {
        cout << dcs[i].to_string() << "  ";
    }
    cout << endl;

    delete[] dcs;

    /// (статический) массив из указателей на объекты
    dumb::complex *pcs[10];  // ни один конструктор не вызван

    // Заполним его указателями на объекты.
    // Тогда это будет статический массив из динамических объектов.
    for(size_t i = 0; i < 10; i++) {
        // по одному конструктору за раз
        pcs[i] = new dumb::complex{0, static_cast<double>(i)};
    }

    // foreach работает; p - указатель
    for(auto p: pcs) {
        cout << p->to_string() << "  ";
        delete p;
    }
    cout << endl;
}

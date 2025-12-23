#include <iostream>
#include "shape.hpp"
#include "square.hpp"
#include "circle.hpp"

using std::cout, std::endl;


int main() {
    // статичные объекты.
    fake::circle<double> c{1};
    fake::rect<double> r{640, 480};
    fake::square<int> s{15};

    // cout << c.get_area() << endl;
    // cout << r.get_width() << endl;
    // cout << r.get_area() << endl;
    // cout << s.get_area() << endl;
    // // s.set_corner_br(2, 2);
    // // s.set_end(3, 2);
    // s.set_begin(1, 1);
    // cout << s.get_begin().y << ' ' << s.get_begin().x << endl;
    // cout << s.get_end().y << ' ' << s.get_end().x << endl;
    // cout << s.get_width() << ' ' << s.get_height() << endl;
    // cout << s.get_area() << endl;

    // Демонстрация полиморфизма.

    /// (статический) массив из полиморфных объектов (указателей)
    fake::shape<double> *arr[3];

    // заполним массив объектами.
    arr[0] = new fake::circle<double>(42.0, 13, 37);
    // arr[1] = new fake::rect<double>(2, 28, 13, 37);
    arr[1] = new fake::rect<double>(37, 13, 28, 2);
    arr[2] = new fake::square<double>(9, 40, 2);

    // вызовем некоторый метод на каждом объекте.
    for(auto p : arr) {
        cout << p->get_area() << endl;
    }

    // очистка памяти
    for(auto p : arr) {
        delete p;
    }

    /// указатель на объект, реализующий shape
    /// (на некоторую фигуру)
    fake::shape<double> *sh;

    sh = &c;  // sh указывает на круг c
    // compile-time error: no such method
    // std::cout << sh->get_radius() << endl;
    std::cout << sh->get_area() << endl;

    /// указатель на круг (не на любую фигуру)
    fake::circle<double> *csh;

    // не работает без каста (compile-time error)
    // csh = sh;
    csh = dynamic_cast< fake::circle<double> * >(sh);

    cout << "csh->get_radius(): ";
    if(csh == nullptr) {
        cout << "dynamic cast failed" << endl;
    } else
        cout << csh->get_radius() << endl;  // shuould be successful

    /// указатель на квадрат
    fake::square<double> *ssh;

    // compile-time error
    // ssh = sh;
    ssh = dynamic_cast< fake::square<double> * >(sh);

    cout << "ssh->get_area(): ";
    if(ssh == nullptr) {
        cout << "dynamic cast failed" << endl;
    } else
        cout << ssh->get_area() << endl;

    // описать dynamic_cast с get_radius и `shape *`

    // Вывод: объект `c` сам помнит, что он круг.
    // На него может указывать `shape *` (`sh` в нашем случае),
    // но при этом виртуальные методы вызываются от `circle`.
    // Круг не квадрат, dynamic_cast не может ничего с этим сделать.
}

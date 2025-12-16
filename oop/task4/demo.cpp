#include <iostream>
#include "shape.hpp"
#include "square.hpp"
#include "circle.hpp"

using std::cout, std::endl;


int main() {
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

    fake::shape<double> *arr[3];

    arr[0] = new fake::circle<double>(42.0, 13, 37);
    arr[1] = new fake::rect<double>(2, 28, 13, 37);
    arr[2] = new fake::square<double>(9, 40, 2);

    for(auto &p : arr) {
        cout << p->get_area() << endl;
    }

    for(auto &p : arr) {
        delete p;
    }

    fake::shape<double> *sh;

    sh = &c;
    std::cout << sh->get_area() << endl;

    fake::circle<double> *csh;

    // не работает
    // csh = sh;
    csh = dynamic_cast< fake::circle<double> * >(sh);

    cout << csh->get_area() << endl;
}

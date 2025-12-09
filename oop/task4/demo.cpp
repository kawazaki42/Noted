#include <iostream>
#include "square.hpp"
#include "circle.hpp"

using std::cout, std::endl;


int main() {
    fake::circle<double> c{1};
    fake::rect<double> r{640, 480};
    fake::square<int> s{15};

    cout << c.get_area() << endl;
    cout << r.get_width() << endl;
    cout << r.get_area() << endl;
    cout << s.get_area() << endl;
    // s.set_corner_br(2, 2);
    // s.set_end(3, 2);
    s.set_begin(1, 1);
    cout << s.get_begin().y << ' ' << s.get_begin().x << endl;
    cout << s.get_end().y << ' ' << s.get_end().x << endl;
    cout << s.get_width() << ' ' << s.get_height() << endl;
    cout << s.get_area() << endl;
}

#include <iostream>
#include "shape.hpp"

using std::cout, std::endl;


int main() {
    fake::circle<double> c{1};
    fake::rect<double> r{640, 480};
    fake::square<int> s{15};

    cout << c.get_area() << endl;
    cout << r.get_width() << endl;
    cout << r.get_area() << endl;
    cout << s.get_area() << endl;
    s.set_corner_br(2, 2);
    cout << s.get_area() << endl;
}

#include <iostream>
#include "complex.hpp"

using std::cout, std::endl;
using fake::operator""_i;


int main() {
    cout << 3 + 4_i << endl;
}

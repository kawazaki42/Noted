/**
 * @author kawazaki42
 * 
 * Главная процедура программы.
 * 
 * (11д)
 *     Даны `x`, `y`, `z`.
 *     Вычислить `a`, `b` по заданным формулам (см. задачник)
 * 
 * @see https://ivtipm.github.io/Programming/Glava01/index01.htm#z11
 */

// потоки ввода-вывода
#include <iostream>

// вычисления
#include "calc.h"

// использовать функции из стандартной библиотеки C++
// using namespace std;


/**
 * Главная процедура.
 * @return 0 при успешном завершении
 */ 
int main(int argc, char **argv) {

    // argv[0] - имя программы
    // аргументы идут после
    if(argc - 1 >= 1) {
        // if(std::string("--test") == std::string(argv[1]) ) {
        if(std::string("--test") == argv[1] ) {
            calc::test::run();
            return 0;
        }
    }

    /// Входные данные
    double x, y, z;

    /*
     * cout - поток вывода
     * cin - поток ввода
     * endl - перевод строки
     */

    std::cout << "Введите x: ";
    std::cin >> x;

    std::cout << "Введите y: ";
    std::cin >> y;

    std::cout << "Введите z: ";
    std::cin >> z;

    std::cout << std::endl;

    std::cout
        << "a = "
        << calc::calc_a(x, y)
        << std::endl;

    std::cout
        << "b = "
        << calc::calc_b(z)
        << std::endl;

    return 0;
}
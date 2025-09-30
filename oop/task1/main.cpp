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

// std::string, std::stod
#include <string>

// вычисления
#include "calc.hpp"

// использовать функции из стандартной библиотеки C++
// using namespace std;

// Отобразить текст справки.
void help(std::string argv_0) {
    std::cout << "Usage: " << std::endl;
    std::cout << argv_0 << " [<x> <y> <z>]" << std::endl;
}


/**
 * Главная процедура.
 * @return 0 при успешном завершении
 */ 
int main(int argc, char **argv) {

    // argv[0] - имя программы
    // аргументы идут после.

    // Если передан 1 аргумент
    if(argc-1 == 1) {
        // if(std::string("--test") == std::string(argv[1]) ) {
        const std::string arg_test = "--test";
        const std::string arg_help = "--help";

        if(arg_test == argv[1] ) {
            calc::test::run();

            // Если test::run не завершил программу - тесты пройдены.
            return 0;
        }

        if(arg_help == argv[1] ) {
            help(argv[0]);
            return 0;
        }
    }
    
    /// Входные данные
    double x, y, z;

    if (argc-1 == 3) {
        x = std::stod(argv[1]);
        y = std::stod(argv[2]);
        z = std::stod(argv[3]);
    } else if (argc-1 == 0) {
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
    } else {
        std::cerr << "Неправильное кол-во аргументов!" << std::endl;

        help(argv[0]);

        return 1;
    }


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
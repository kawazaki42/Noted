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
using namespace std;


/**
 * Главная процедура.
 * @return 0 при успешном завершении
 */ 
int main() {
    /// Входные данные
    double x, y, z;

    /*
     * cout - поток вывода
     * cin - поток ввода
     * endl - перевод строки
     */

    cout << "Введите x: ";
    cin >> x;

    cout << "Введите y: ";
    cin >> y;

    cout << "Введите z: ";
    cin >> z;

    cout << endl;
    cout << "a = " << calc_a(x, y) << endl;
    cout << "b = " << calc_b(z) << endl;

    return 0;
}
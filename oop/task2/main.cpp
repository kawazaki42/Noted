/**
 * @author kawazaki42
 * 
 * Главная процедура программы.
 * 
 * (136)
 *     Дана последовательность a[1..n]. Вычислить:
 *     м) sin | a_1 + ... + a_n |
 * 
 * @see https://ivtipm.github.io/Programming/Glava01/index01.htm#z11
 */

// Заголовочные файлы (_импорты_)

// Страндартная библиотека
 
// ввод-вывод
#include <iostream>

// Зависимости внутри проекта

// внутренняя логика
#include "calc.hpp"

/// Главная процедура программы.
/// @return 0 при успешном завершении программы
int main(int argc, char **argv) {
    // const size_t n = 20;

    const std::string FLAG_TEST = "--test";

    if(argc-1 >= 1) {
        if(argv[1] == FLAG_TEST) {
            calc::test::all();
            return 0;
        }
    }

    size_t n;

    std::cout << "Длина последовательности: ";

    std::cin >> n;

    // Последовательность действительных чисел согласно условию задачи.
    double *a = new double[n];

    // Заполняем случайными числами
    arr::randomize(a, n);

    // Отображение последовательности

    std::cout << "Последовательность:" << std::endl;

    arr::display(a, n);

    // Ответ на задачу
    std::cout
        << std::endl
        << "Синус модуля суммы последовательности: "
        << calc::sin_abs_sum(a, n)
        << std::endl;

    // Не забываем очистить память
    delete[] a;
}
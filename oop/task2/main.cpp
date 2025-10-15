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
#include <format>
#include <iostream>

// Зависимости внутри проекта

// внутренняя логика
#include "calc.hpp"

/// Главная процедура программы.
/// @return 0 при успешном завершении программы
int main(int argc, char **argv) {
    // const size_t n = 20;

    std::vector<double> input;

    const std::string FLAG_TEST = "--test";

    if(argc-1 >= 1) {
        if(argv[1] == FLAG_TEST) {
            calc::test::all();
            return 0;
        } else
            input = arr::file::load(argv[1]);
    } else {
        char response;
        std::cout << "Ввести числа вручную? (y/N) ";
        std::cin >> response;

        size_t n;
        std::cout << "Длина последовательности: ";
        std::cin >> n;

        input.resize(n);

        if(response == 'y') {
            std::cout << std::format("Введите числа ({}):\n", n);
            arr::fill_from_stdin(input);
        }
        else {
            arr::randomize(input);

            // Отображение последовательности
            std::cout << "Последовательность:" << std::endl;
            arr::display(input);
            std::cout << std::endl;
        }
    }

    // Последовательность действительных чисел согласно условию задачи.
    // double *a = new double[n];

    // Заполняем случайными числами
    // arr::randomize(a, n);

    // Ответ на задачу
    std::cout
        << "Синус модуля суммы последовательности: "
        // << calc::sin_abs_sum(a, n)
        << calc::sin_abs_sum(input)
        << std::endl;

    // Не забываем очистить память
    // delete[] a;
}
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

// operator ""s
using namespace std::string_literals;

/// Главная процедура программы.
/// @return 0 при успешном завершении программы
int main(int argc, char **argv) {
    // const size_t n = 20;

    // std::vector<double> input;
    double *input;
    size_t input_size{0};
    std::string outfile;

    // const std::string FLAG_TEST = "--test";

    size_t parse_argc = argc;

    using cstr = char *;
    
    // итератор "массива" аргументов-строк
    cstr *parse_argv = argv;

    // пропускаем argv[0], т.е. имя программы
    parse_argc--;
    parse_argv++;

    while(parse_argc) {

    // }

    // if(argc-1 >= 1) {
        // if(argv[1] == FLAG_TEST) {
        if(*parse_argv == "--test"s) {
            calc::test::all();
            return 0;
        } else if (*parse_argv == "--dump"s) {
            parse_argv++;
            parse_argc--;

            outfile = *parse_argv;

            parse_argv++;
            parse_argc--;
        } else {
            // input = arr::file::load(*parse_argv);
            input = arr::file::load(*parse_argv, input_size);
            parse_argv++;
            parse_argc--;
        }
    }
    // else {
    // if(input.size() == 0) {
    if(input_size == 0) {
        char response;
        std::cout << "Ввести числа вручную? (y/N) ";
        std::cin >> response;

        // size_t n;
        std::cout << "Длина последовательности: ";
        // std::cin >> n;
        std::cin >> input_size;

        // input.resize(n);
        input = new double[input_size];

        if(response == 'y') {
            // std::cout << std::format("Введите числа ({}):\n", n);
            std::cout << std::format("Введите числа ({}):\n", input_size);
            // arr::fill_from_stdin(input);
            arr::fill_from_stdin(input, input_size);
        }
        else {
            // arr::randomize(input);
            arr::randomize(input, input_size);

            // Отображение последовательности
            std::cout << "Последовательность:" << std::endl;
            // arr::display(input);
            arr::display(input, input_size);
            std::cout << std::endl;
        }
    }

    if( !outfile.empty() ) {
        // arr::file::dump(outfile, input);
        arr::file::dump(outfile, input, input_size);
    }

    // Последовательность действительных чисел согласно условию задачи.
    // double *a = new double[n];

    // Заполняем случайными числами
    // arr::randomize(a, n);

    // Ответ на задачу
    std::cout
        << "Синус модуля суммы последовательности: "
        << calc::sin_abs_sum(input, input_size)
        // << calc::sin_abs_sum(input)
        << std::endl;

    // Не забываем очистить память
    // delete[] a;
}
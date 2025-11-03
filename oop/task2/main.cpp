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

// basename
#include <filesystem>
#include <format>
#include <iostream>
#include <string>

// Зависимости внутри проекта

// внутренняя логика
#include "calc.hpp"

// строковый литерал который создает std::string
using std::string_literals::operator ""s;

using std::vector;
using std::string;


// const string HELP_FORMAT =
const std::format_string<const string &> HELP_FORMAT =
R"({} [<infile>] [--help] [--test] [--dump <outfile>] [--no-vector]

Вычислить синус модуля суммы последовательности чисел.

--help  Вывести эту справку
--test  Выполнить тесты вместо обычной работы программы.
        Если тесты пройдены, не выводит сообщений и
        завершает программу с нулевым статусом.
--dump <outfile>  Вывести входную последовательность в текстовый файл
--no-vector  Использовать обычные массивы (double *)
             вместо класса std::vector
)";


/// Вывести справку
/// @param progname имя программы (`argv[0]`)
constexpr void print_help(const string &progname) {
    std::cout << std::format(HELP_FORMAT, progname);
}


/// Главная процедура программы.
/// @return 0 при успешном завершении программы
int main(int argc, char **argv) {
    // const size_t n = 20;

    vector<double> input_vec;

    double *input_ptr;
    size_t input_size{0};

    string outfile;

    // const std::string FLAG_TEST = "--test";

    using cstr = char *;

    size_t orig_argc = argc;
    cstr *orig_argv = argv;

    bool no_vector = false;
    
    // итератор "массива" аргументов-строк
    // cstr *parse_argv = argv;

    // пропускаем argv[0], т.е. имя программы
    argc--;
    argv++;

    while(argc) {

    // }

    // if(argc-1 >= 1) {
        // if(argv[1] == FLAG_TEST) {
        if(*argv == "--help"s) {
            // используем класс std::filesystem::path
            // чтобы выводить имя программы без каталогов
            // (не абсолютный путь)
            std::filesystem::path p{orig_argv[0]};
            print_help( p.filename().string() );
            return 0;
        }
        else if(*argv == "--test"s) {
            calc::test::all();
            return 0;
        }
        else if(*argv == "--no-vector"s) {
            no_vector = true;
        }
        else if(*argv == "--dump"s) {
            // пропускаем название параметра
            argv++;
            argc--;

            outfile = *argv;
        }
        else {
            if(no_vector) {
                input_ptr = arr::file::load<double>(*argv, input_size);
            }
            else {
                input_vec = arr::file::load<double>(*argv);
                input_size = input_vec.size();
            }
        }

        // следующий аргумент
        argv++;
        argc--;
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

        if(no_vector) {
            input_ptr = new double[input_size];
            std::cerr
                << "Вручную создан массив по адресу: " << input_ptr
                << std::endl;
        }
        else {
            input_vec.resize(input_size);
        }

        if(response == 'y') {
            // std::cout << std::format("Введите числа ({}):\n", n);
            std::cout << std::format("Введите числа ({}):\n", input_size);

            if(no_vector) {
                arr::fill_from_stdin(input_ptr, input_size);
            }
            else {
                arr::fill_from_stdin(input_vec);
            }
        }
        else {
            if(no_vector) {
                arr::randomize(input_ptr, input_size);
            }
            else {
                arr::randomize(input_vec);
            }

            // Отображение последовательности
            std::cout << "Последовательность:" << std::endl;

            if(no_vector) {
                arr::display(input_ptr, input_size);
            }
            else {
                arr::display(input_vec);
            }

            std::cout << std::endl;
        }
    }

    if( !outfile.empty() ) {
        if(no_vector) {
            arr::file::dump(outfile, input_ptr, input_size);
        }
        else {
            arr::file::dump(outfile, input_vec);
        }
    }

    // Последовательность действительных чисел согласно условию задачи.
    // double *a = new double[n];

    // Заполняем случайными числами
    // arr::randomize(a, n);

    double result;
    if(no_vector) {
        result = calc::sin_abs_sum(input_ptr, input_size);
    }
    else {
        result = calc::sin_abs_sum(input_vec);
    }

    // Ответ на задачу
    std::cout
        << "Синус модуля суммы последовательности: " << result
        << std::endl;

    // Не забываем очистить память
    if(no_vector) {
        delete[] input_ptr;
    }
    // delete[] a;
}
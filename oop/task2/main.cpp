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
using std::cout;
using std::cin;
using std::endl;


// const string HELP_FORMAT =
const std::format_string<const string &> HELP_FORMAT =
R"({} [<infile>] [--help] [--test] [--dump <outfile>] [--no-vector]

Вычислить синус модуля суммы последовательности чисел.

--help  Вывести эту справку
--random  использовать случайные числа вместо стандартного ввода
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
    cout << std::format(HELP_FORMAT, progname);
}


/// Главная процедура программы.
/// @return 0 при успешном завершении программы
int main(int argc, char **argv) {
    // входная последовательность (вид массива на выбор)
    /// режим без вектора
    bool no_vector = false;

    /// входной вектор
    vector<double> input_vec;

    /// входной массив (указатель)
    double *input_ptr;

    /// размер входных данных
    size_t input_size{0};

    /// имя выходного файла
    string outfile;

    /// использовать ли случайные числа
    bool random;

    // обработка аргументов командной строки
    // используем argv как итератор

    using cstr = char *;
    cstr *orig_argv = argv;
    size_t orig_argc = argc;

    // пропускаем argv[0], т.е. имя программы
    argc--;
    argv++;

    while(argc) {
        if(*argv == "--help"s) {
            // используем класс std::filesystem::path
            // чтобы выводить имя программы без каталогов
            // (не абсолютный путь)
            std::filesystem::path p{orig_argv[0]};
            print_help( p.filename().string() );
            return 0;
        }
        else if(*argv == "--version"s) {
            cout << "commit summary: add random flag" << endl;
            return 0;
        }
        else if(*argv == "--random"s) {
            random = true;
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
            // примем любой другой аргумент как имя входного файла
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

    // если мы не считали данные из файла
    if(input_size == 0) {
        // char response;
        // cout << "Ввести числа вручную? (y/N) ";
        // cin >> response;

        cout << "Длина последовательности: ";
        cin >> input_size;

        if(no_vector) {
            input_ptr = new double[input_size];
            std::cerr
                << "Вручную создан массив по адресу: " << input_ptr
                << endl;
        }
        else {
            input_vec.resize(input_size);
        }

        if(not random) {
            cout << std::format("Введите числа ({}):\n", input_size);

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

            cout << "Последовательность:" << endl;

            if(no_vector) {
                arr::display(input_ptr, input_size);
            }
            else {
                arr::display(input_vec);
            }

            cout << endl;
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

    double result;
    if(no_vector) {
        result = calc::sin_abs_sum(input_ptr, input_size);
    }
    else {
        result = calc::sin_abs_sum(input_vec);
    }

    // Ответ на задачу
    cout
        << "Синус модуля суммы последовательности: " << result << endl;

    // Не забываем очистить память
    if(no_vector) {
        delete[] input_ptr;
    }
}
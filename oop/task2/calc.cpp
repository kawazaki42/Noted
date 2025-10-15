/**
 * @author kawazaki42
 * 
 * Логика программы.
 * 
 * (136)
 *     Дана последовательность a[1..n]. Вычислить:
 *     м) sin | a_1 + ... + a_n |
 * 
 * @see https://ivtipm.github.io/Programming/Glava01/index01.htm#z11
 */

// Заголовочные файлы (_импорты_)

// Стандартная библиотека
// assert (для тестов)
#include <cassert>

// sin
#include <cmath>

// ssize_t
#include <cstddef>

// файловые потоки
#include <fstream>

// // rand, srand
// #include <cstdlib>

// // time
// #include <ctime>

// setw, setprecision, fixed
#include <iomanip>

// потоки ввода-вывода (для arr::display)
#include <iostream>

// математические константы
#include <numbers>

// Библиотека случайных чисел из C++
#include <random>

// std::vector (динамический массив)
#include <vector>


// Внутренние зависимости

// интерфейс этого модуля
#include "calc.hpp"


/// Логика программы.
namespace calc {
    /// Найти синус модуля суммы последовательности.
    /// @param nums последовательность (динамический массив)
    /// @param len длина последовательности
    double sin_abs_sum(const double nums[], size_t len) {
        double sum = 0.0;

        // for(double elem : nums) {
        for(size_t i = 0; i < len; i++) {
            sum += nums[i];
        }

        return std::sin( std::abs(sum) );
    }

    double sin_abs_sum(const std::vector<double> nums) {
        // double sum = std::accumulate(nums.begin(), nums.end(), 0);

        double sum = 0.0;

        for(double elem : nums) {
            sum += elem;
        }

        return std::sin( std::abs(sum) );
    }

    /// Тесты для логики программы.
    namespace test {
        /// Сравнить два дробных значения с точностью `calc::test::EPSILON`
        /// @param a, b дробные значения
        /// @return true, если значения достаточно близки
        /// @return false, если значения достаточно далеки
        inline bool is_close(double a, double b) {
            return std::abs(a - b) < test::EPSILON;
        }
        
        // /// TODO
        // /// запустить один тест
        // inline void one(double nums[], size_t len, double expected) {
        //     assert((
        //         is_close(
        //             sin_abs_sum(nums, len),
        //             expected
        //         ), "..."
        //     ));
        // }

        /// TODO
        /// запустить все тесты
        void all() {
            // double set[] = {1, -1, 2, -2};
            // one(set, 4, 1);
            // std::vector data{1, -1, 2, -2};

            double res, expected;

            res = sin_abs_sum({1, -1, 2, -2});
            // expected = 0.0;

            assert( is_close(res, 0.0) );

            res = sin_abs_sum({
                std::numbers::pi,
                std::numbers::pi,
                std::numbers::pi,
                std::numbers::pi,
            });
            // std::cout << res;
            assert( is_close(res, 0.0) );

            // TODO: сделать с вектором из нулей

            // assert( is_close(double a, double b) )

            assert(
                is_close(
                    sin_abs_sum({
                    std::numbers::pi,
                    std::numbers::pi,
                    std::numbers::pi,
                    std::numbers::pi / 2,
                    }),
                    -1.0
                )
            );
        }
    }
}


/// Работа с массивами.
namespace arr {
    /// Заполнить массив случайными числами.
    /// @param nums массив типа `double`
    /// @param len длина массива
    /// @param min минимальное значение случайного числа
    /// @param max максимальное значение случайного числа
    void randomize(
        double nums[],
        size_t len,
        double min,  // default: -100.0
        double max   // default: +100.0
    ) {
        // // Инициализируем генератор случайных чисел.
        // TODO: вынести в main?
        // srand(time(NULL));

        // устройство-источник случайных чисел
        std::random_device rd;

        // реализация генератора случайных чисел
        std::default_random_engine eng(rd());

        // диапазон случайных чисел
        std::uniform_real_distribution dist(min, max);

        for(size_t i = 0; i < len; i++) {
            // следующее случайное число
            // в диапазоне dist
            // сгенерированное при помощи eng
            nums[i] = dist(eng);
        }
    }

    void randomize(std::vector<double> &a, double min, double max) {
        // устройство-источник случайных чисел
        std::random_device rd;
    
        // реализация генератора случайных чисел
        std::default_random_engine eng(rd());
    
        // диапазон случайных чисел
        std::uniform_real_distribution dist(min, max);
    
        // для заполнения вектора необходимо брать каждый элемент по ссылке
        for(double &e : a) {
            // следующее случайное число
            // в диапазоне dist
            // сгенерированное при помощи eng
            e = dist(eng);
        }
    }

    // std::vector<double> randvec(size_t len, double min, double max) {
    //     std::vector<double> result(len);


    //     return result;
    // }

    // double *input(size_t len) {
    //     double *result = new double[len];

    //     for(size_t i = 0; i < len; i++)
    //         std::cin >> result[i];

    //     return result;
    // }

    // std::vector<double> input(size_t len) {
    //     std::vector<double> result(len);

    //     for(double &e : result) {
    //         std::cin >> e;
    //     }

    //     return result;
    // }

    void fill_from_stdin(std::vector<double> &a) {
        for(double &e : a) {
            std::cin >> e;
        }
    }

    const size_t ELEMS_PER_ROW = 10;

    /// Отобразить массив на стандартном выводе.
    ///
    /// Группы по 10 чисел разделяются на отдельные строки.
    /// @param nums массив
    /// @param len длина массива
    void display(double nums[], size_t len) {

        for(size_t i = 0; i < len; i++) {
            // операция над потоком вывода:
            std::cout

                // не использовать формат по типу 6.022e+23
                // для дробных чисел
                << std::fixed

                // кол-во цифр после запятой
                << std::setprecision(2)

                // ширина одного поля (числа)
                << std::setw(10)

                // само число
                << nums[i];
            
            // делим числа на группы:
            // 0-9, 10-19, 20-29...
            // (по 10 чисел в каждой)

            /// Позиция элемента в строке
            size_t rowpos = i % ELEMS_PER_ROW;

            // Если элемент последний в строке, выполнить перенос
            if(rowpos == ELEMS_PER_ROW-1) {
                std::cout << std::endl;
            }
        }
    }

    /// Отобразить массив на стандартном выводе.
    ///
    /// Группы по 10 чисел разделяются на отдельные строки.
    /// @param nums последовательность (`std::vector`)
    void display(const std::vector<double> nums) {
        for(size_t i = 0; i < nums.size(); i++) {
            // операция над потоком вывода:
            std::cout

                // не использовать формат по типу 6.022e+23
                // для дробных чисел
                << std::fixed

                // кол-во цифр после запятой
                << std::setprecision(2)

                // ширина одного поля (числа)
                << std::setw(10)

                // само число
                << nums[i];
            
            // делим числа на группы:
            // 0-9, 10-19, 20-29...
            // (по 10 чисел в каждой)

            /// Позиция элемента в строке
            size_t rowpos = i % ELEMS_PER_ROW;

            // Если элемент последний в строке, выполнить перенос
            if(rowpos == ELEMS_PER_ROW-1) {
                std::cout << std::endl;
            }
        }
    }

    namespace file {
        std::vector<double> load(std::string name) {
            std::ifstream f(name);

            std::vector<double> result;

            for(double n; f >> n;) {
                // NOTE: каждый вызов push_back выделяет память наперед.
                result.push_back(n);
            }

            // освободить выделенную но не использованную память
            result.shrink_to_fit();

            return result;
        }
    }
}
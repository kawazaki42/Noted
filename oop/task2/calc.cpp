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
// #include <cmath>

// ssize_t
#include <cstddef>

// файловые потоки
// #include <fstream>

// // rand, srand
// #include <cstdlib>

// // time
// #include <ctime>

// setw, setprecision, fixed
// #include <iomanip>

// потоки ввода-вывода (для arr::display)
// #include <iostream>

// математические константы
#include <numbers>

// Библиотека случайных чисел из C++
// #include <random>

// std::vector (динамический массив)
#include <vector>


// Внутренние зависимости

// интерфейс этого модуля
#include "calc.hpp"


/// Логика программы.
// namespace calc {
    /// Тесты для логики программы.
    // namespace test {
        /// Запустить набор тестов.
        ///
        /// Завершает программу с ошибкой,
        /// если хотя бы один тест провалится.
        void calc::test::all() {
            // double set[] = {1, -1, 2, -2};
            // one(set, 4, 1);
            // std::vector data{1, -1, 2, -2};

            // double res, expected;

            auto zerosum = sin_abs_sum<double>({1, -1, 2, -2});
            // expected = 0.0;

            assert( is_close(zerosum, 0.0) );

            auto fourpi = sin_abs_sum<double>({
                std::numbers::pi,
                std::numbers::pi,
                std::numbers::pi,
                std::numbers::pi,
            });
            // std::cout << res;
            assert( is_close(fourpi, 0.0) );

            // TODO: сделать с вектором из нулей

            // assert( is_close(double a, double b) )

            auto three_and_half_pi = sin_abs_sum<double>({
                std::numbers::pi,
                std::numbers::pi,
                std::numbers::pi,
                std::numbers::pi / 2,
            });

            assert( is_close(three_and_half_pi, -1.0) );

            auto four_zeros = sin_abs_sum<double>({0, 0, 0, 0});

            assert( is_close(four_zeros, 0.0) );
        }
    // }
// }

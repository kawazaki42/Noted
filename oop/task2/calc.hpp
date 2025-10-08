/**
 * @author kawazaki42
 * 
 * Логика программы (интерфейсная часть)
 * 
 * (136)
 *     Дана последовательность a[1..n]. Вычислить:
 *     м) sin | a_1 + ... + a_n |
 * 
 * @see https://ivtipm.github.io/Programming/Glava01/index01.htm#z11
 */

// защита от повторных включений: условная директива.
#ifndef CALC_HPP
#define CALC_HPP

// size_t
#include <cstddef>


/// Логика программы.
namespace calc {
    /// Найти синус модуля суммы последовательности.
    /// @param nums последовательность (динамический массив)
    /// @param len длина последовательности
    double sin_abs_sum(double nums[], size_t len);

    /// Тесты для логики программы.
    namespace test {
        /// Точность сравнения.
        const double EPSILON = 1e-6;

        /// Сравнить два дробных значения с точностью `calc::test::EPSILON`
        /// @param a, b дробные значения
        /// @return true, если значения достаточно близки
        /// @return false, если значения достаточно далеки
        inline bool is_close(double a, double b);

        void all();
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
        double min = -100.0,
        double max = +100.0
    );

    /// Отобразить массив на стандартном выводе.
    ///
    /// Группы по 10 чисел разделяются на отдельные строки.
    /// @param nums массив
    /// @param len длина массива
    void display(double nums[], size_t len);
}


#endif  // CALC_HPP
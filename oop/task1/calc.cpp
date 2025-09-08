/**
 * @author kawazaki42
 * 
 * Вычисления по формуле.
 * 
 * (11д)
 *     Даны `x`, `y`, `z`.
 *     Вычислить `a`, `b` по заданным формулам (см. задачник)
 * 
 * @see https://ivtipm.github.io/Programming/Glava01/index01.htm#z11
 */

// Интерфейсная часть модуля
#include "calc.h"


/**
 * Вычислить величину `a` по условиям задачи.
 * @param x, y входные данные задачи
 * @see https://ivtipm.github.io/Programming/Glava01/index01.htm#z11
 */
double calc_a(double x, double y) {
    /// Результат функции.
    double result;

    /// sin(y). Избегаем второй вызов функции для скорости
    double siny = sin(y);

    result = 2.0 * cos(x - M_PI / 6.0);
    result /= 1.0/2.0 + siny*siny;

    return result;
}


/**
 * Вычислить величину `b` по условиям задачи.
 * @param z входные данные задачи
 * @see https://ivtipm.github.io/Programming/Glava01/index01.htm#z11
 */
double calc_b(double z) {
    /// Результат функции.
    double result;

    // z^2. Избегаем повторное вычисление
    double z2 = z*z;

    result = z2;
    result /= 3.0 + z2/5.0;
    result += 1;

    return result;
}
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

#include <cassert>

// Интерфейсная часть модуля
#include "calc.h"


namespace calc {
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
    
        result = 2.0 * cos(x - M_PI/6.0);
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

    namespace test {
        // точность сравнения результатов
        // const double EPSILON = 1e-6;
        
        bool is_close(double a, double b) {
            return abs(a - b) < EPSILON;
        }

        // bool run()
        void run() {
            double x, y, z;
            double a, b;
            
            x = M_PI_2 + M_PI/6;
            y = 0;
            z = 0;

            a = calc_a(x, y);
            b = calc_b(z);

            assert(is_close(a, 0));
            assert(is_close(b, 1));

            // if(!is_equal(a, 0))
            //     return false;

            // if(!is_equal(b, 1))
            //     return false;

            // return true;
        }
    }
}
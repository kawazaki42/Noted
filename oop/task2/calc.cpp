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

#include <cmath>

// rand, srand
#include <cstdlib>
// time
#include <ctime>

// Библиотека случайных чисел из C++
#include <random>


namespace calc {
    double sin_abs_sum(double nums[], size_t len) {
        double sum = 0.0;

        for(size_t i = 0; i < len; i++) {
            sum += nums[i];
        }

        return sin( abs(sum) );
    }
}


namespace arr {
    void randomize(double nums[], size_t len) {
        // Инициализируем генератор случайных чисел.
        // TODO: вынести в main?
        // srand(time(NULL));

        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution dist(-100.0, +100.0);

        for(size_t i = 0; i < len; i++) {
            nums[i] = dist(eng);
        }
    }
}
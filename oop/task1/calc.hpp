/**
 * @author kawazaki42
 * 
 * Вычисления по формуле (интерфейсная часть).
 * 
 * (11д)
 *     Даны `x`, `y`, `z`.
 *     Вычислить `a`, `b` по заданным формулам (см. задачник)
 * 
 * @see https://ivtipm.github.io/Programming/Glava01/index01.htm#z11
 */

// математические операции и константы
#include <cmath>


namespace calc {
    /**
     * Вычислить величину `a` по условиям задачи.
     * @param x, y входные данные задачи
     * @see https://ivtipm.github.io/Programming/Glava01/index01.htm#z11
     */
    double calc_a(double x, double y);
    
    
    /**
     * Вычислить величину `b` по условиям задачи.
     * @param z входные данные задачи
     * @see https://ivtipm.github.io/Programming/Glava01/index01.htm#z11
     */
    double calc_b(double z);

    // Тесты для логики программы.
    namespace test
    {
        // Точность сравнения результатов.
        // const double EPSILON;
        const double EPSILON = 1e-6;

        // Достаточно ли близки два дробных значения?
        //
        // Точнее говоря, не превышает ли отклонение число EPSILON?
        bool is_close(double a, double b);

        // Запустить набор тестов.
        //
        // Завершает программу с ненулевым статусом,
        // если провалится хотя бы один тест.
        void run();
    }
}
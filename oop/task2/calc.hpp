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
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>


/// Логика программы.
namespace calc {
    /// Найти синус модуля суммы последовательности.
    /// @param nums последовательность (динамический массив)
    /// @param len длина последовательности
    template<typename T>
    T sin_abs_sum(const T nums[], size_t len);

    /// Найти синус модуля суммы последовательности.
    /// @param nums последовательность (`std::vector`)
    template<typename T>
    T sin_abs_sum(const std::vector<T> &nums);

    /// Тесты для логики программы.
    namespace test {
        /// Точность сравнения.
        const double EPSILON = 1e-6;

        /// Сравнить два дробных значения с точностью `calc::test::EPSILON`
        /// @param a, b дробные значения
        /// @return true, если значения достаточно близки
        /// @return false, если значения достаточно далеки
        template<typename T>
        constexpr bool is_close(T a, T b) {
            return std::abs(a - b) < test::EPSILON;
        }
        
        /// Запустить набор тестов.
        ///
        /// Завершает программу с ошибкой,
        /// если хотя бы один тест провалится.
        void all();
    }
}


/// Найти синус модуля суммы последовательности.
/// @param nums последовательность (динамический массив)
/// @param len длина последовательности
template<typename T>
T calc::sin_abs_sum(const T nums[], size_t len) {
    T sum = 0.0;

    // for(T elem : nums) {
    for(size_t i = 0; i < len; i++) {
        sum += nums[i];
    }

    return std::sin( std::abs(sum) );
}


/// Найти синус модуля суммы последовательности.
/// @param nums последовательность (`std::vector`)
template<typename T>
T calc::sin_abs_sum(const std::vector<T> &nums) {
    // T sum = std::accumulate(nums.begin(), nums.end(), 0);

    // T sum = 0.0;

    // for(T elem : nums) {
    //     sum += elem;
    // }

    // return std::sin( std::abs(sum) );

    // don't repeat yourself
    return sin_abs_sum(nums.data(), nums.size());
}


/// Работа с массивами.
namespace arr {
    /// Заполнить массив случайными числами.
    /// @param nums массив
    /// @param len длина массива
    /// @param min минимальное значение случайного числа
    ///            (по умолчанию -100)
    /// @param max максимальное значение случайного числа
    ///            (по умолчанию +100)
    template<typename T>
    void randomize(
        T nums[],
        size_t len,
        T min = -100.0,
        T max = +100.0
    );

    /// Заполнить массив случайными числами.
    /// @param nums массив (`std::vector`)
    /// @param min минимальное значение случайного числа
    ///            (по умолчанию -100)
    /// @param max максимальное значение случайного числа
    ///            (по умолчанию +100)
    template<typename T>
    void randomize(
        std::vector<T> &nums,
        T min = -100.0,
        T max = +100.0
    );

    /// Заполнить массив со стандартного ввода.
    /// @param nums массив (`std::vector`) с заданным размером
    ///             (`std::vector::resize`)
    template<typename T>
    void fill_from_stdin(std::vector<T> &nums);

    /// Заполнить массив со стандартного ввода.
    /// @param nums массив
    /// @param size размер массива
    template<typename T>
    void fill_from_stdin(T *nums, size_t size);

    /// Отобразить массив на стандартном выводе.
    ///
    /// @param nums массив
    /// @param len длина массива
    /// @param elems_per_row кол-во элементов на строке
    ///                      (по умалчанию 10)
    template<typename T>
    void display(T nums[], size_t len, size_t elems_per_row = 10);

    /// Отобразить массив на стандартном выводе.
    ///
    /// @param nums массив (`std::vector`)
    /// @param elems_per_row кол-во элементов на строке
    ///                      (по умалчанию 10)
    template<typename T>
    void display(const std::vector<T> &nums, size_t elems_per_row = 10);

    /// Работа с файлами
    namespace file {
        /// Загрузить массив из файла.
        /// @param name имя файла
        /// @return вектор со значениями из файла
        template<typename T>
        std::vector<T> load(const std::string &name);

        /// Загрузить массив из файла.
        /// @param name имя файла
        /// @param[out] size переменная с размером массива
        /// @return массив (`T *`) со значениями из файла
        template<typename T>
        T *load(const std::string &name, size_t &size);

        /// Сохранить массив в файл
        /// @param name имя файла
        /// @param nums массив (`std::vector`)
        template<typename T>
        void dump(const std::string &name, std::vector<T> &nums);

        /// Сохранить массив в файл
        /// @param name имя файла
        /// @param nums массив
        /// @param size размер массива
        template<typename T>
        void dump(const std::string &name, T *nums, size_t size);
    }
}


/// Заполнить массив случайными числами.
/// @param nums массив
/// @param len длина массива
/// @param min минимальное значение случайного числа
///            (по умолчанию -100)
/// @param max максимальное значение случайного числа
///            (по умолчанию +100)
template<typename T>
void arr::randomize(
    T nums[],
    size_t len,
    T min,
    T max
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


/// Заполнить массив случайными числами.
/// @param nums массив (`std::vector`)
/// @param min минимальное значение случайного числа
///            (по умолчанию -100)
/// @param max максимальное значение случайного числа
///            (по умолчанию +100)
template<typename T>
void arr::randomize(
    std::vector<T> &nums,
    T min,
    T max
) {
    // // устройство-источник случайных чисел
    // std::random_device rd;

    // // реализация генератора случайных чисел
    // std::default_random_engine eng(rd());

    // // диапазон случайных чисел
    // std::uniform_real_distribution dist(min, max);

    // // для заполнения вектора необходимо брать каждый элемент по ссылке
    // for(T &e : nums) {
    //     // следующее случайное число
    //     // в диапазоне dist
    //     // сгенерированное при помощи eng
    //     e = dist(eng);
    // }

    return arr::randomize(nums.data(), nums.size(), min, max);
}


/// Заполнить массив со стандартного ввода.
/// @param nums массив (`std::vector`) с заданным размером
///             (`std::vector::resize`)
template<typename T>
void arr::fill_from_stdin(std::vector<T> &nums) {
    // for(double &e : nums) {
    //     std::cin >> e;
    // }

    return arr::fill_from_stdin(nums.data(), nums.size());
}

/// Заполнить массив со стандартного ввода.
/// @param nums массив
/// @param size размер массива
template<typename T>
void arr::fill_from_stdin(T *nums, size_t size) {
    for(size_t i{0}; i < size; i++) {
        std::cin >> nums[i];
    }
}


/// Отобразить массив на стандартном выводе.
///
/// @param nums массив
/// @param len длина массива
/// @param elems_per_row кол-во элементов на строке
///                      (по умалчанию 10)
template<typename T>
void arr::display(T nums[], size_t len, size_t elems_per_row) {
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
        size_t rowpos = i % elems_per_row;

        // Если элемент последний в строке, выполнить перенос
        if(rowpos == elems_per_row-1) {
            std::cout << std::endl;
        }
    }
}


/// Отобразить массив на стандартном выводе.
///
/// @param nums массив (`std::vector`)
/// @param elems_per_row кол-во элементов на строке
///                      (по умалчанию 10)
template<typename T>
void arr::display(const std::vector<T> &nums, size_t elems_per_row) {
    // for(size_t i = 0; i < nums.size(); i++) {
    //     // операция над потоком вывода:
    //     std::cout

    //         // не использовать формат по типу 6.022e+23
    //         // для дробных чисел
    //         << std::fixed

    //         // кол-во цифр после запятой
    //         << std::setprecision(2)

    //         // ширина одного поля (числа)
    //         << std::setw(10)

    //         // само число
    //         << nums[i];
        
    //     // делим числа на группы:
    //     // 0-9, 10-19, 20-29...
    //     // (по 10 чисел в каждой)

    //     /// Позиция элемента в строке
    //     size_t rowpos = i % elems_per_row;

    //     // Если элемент последний в строке, выполнить перенос
    //     if(rowpos == elems_per_row-1) {
    //         std::cout << std::endl;
    //     }
    // }

    // whoa i repeated so much...

    return arr::display(nums.data(), nums.size(), elems_per_row);
}


/// Загрузить массив из файла.
/// @param name имя файла
/// @return вектор со значениями из файла
template<typename T>
std::vector<T> arr::file::load(const std::string &name) {
    if(not std::filesystem::exists(name)) {
        throw std::runtime_error("файл не существует: " + name);
    }

    // std::ifstream f(name);
    std::ifstream f;

    // вызываем исключение при ошибке
    // f.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    f.open(name);
    // fail() может появиться при eof()
    // f.exceptions(std::ifstream::badbit);

    if(!f) {
        // throw std::ifstream::failure(
        throw std::runtime_error(
            "не удалось открыть файл для чтения: " + name
        );
    }


    std::vector<T> result;

    for(T n; f >> n;) {
        // NOTE: каждый вызов push_back выделяет память наперед.
        result.push_back(n);
    }

    // освободить выделенную но не использованную память
    result.shrink_to_fit();

    return result;
}


/// Загрузить массив из файла.
/// @param name имя файла
/// @param[out] size переменная с размером массива
/// @return массив (`T *`) со значениями из файла
template<typename T>
T *arr::file::load(const std::string &name, size_t &size) {
    if(not std::filesystem::exists(name)) {
        throw std::runtime_error("файл не существует: " + name);
    }

    // std::ifstream f(name);
    std::ifstream f;

    // вызываем исключение при ошибке
    // f.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    f.open(name);
    // fail() может появиться при eof()
    // f.exceptions(std::ifstream::badbit);



    if(!f) {
        // throw std::ifstream::failure(
        throw std::runtime_error(
            "не удалось открыть файл для чтения: " + name
        );
    }

    // вычисляем размер памяти перед выделением

    size = 0;
    for(T ignored; f >> ignored;)
        size++;

    T *result = new T[size];

    // сбросить флаги и перейти в начало файла
    f.clear();
    f.seekg(0, std::ifstream::beg);

    // // it - указатель, который мы используем в качестве итератора
    // // да, я просто хейтер простого индекса итерации ;)

    // for(T *it = result; it < (result + size); it++)
    //     f >> *it;

    // хотя, раз он до тошноты простой,
    // компилятор может его оптимизировать...

    for(size_t i{0}; i < size; i++) {
        f >> result[i];
    }

    return result;

    // NOTE: а, не, это не проканало. У вектора нельзя украсть data()
    //       и чтоб при этом десткуктор его не за'delet'ил.

    // NOTE: тут наоборот функция которая работает с обычным указателем
    // вызывает векторную

    // std::vector<T> result{ arr::file::load<T>(name) };
    // size = result.size();
    // return result.data();
}


/// Сохранить массив в файл
/// @param name имя файла
/// @param nums массив (`std::vector`)
template<typename T>
void arr::file::dump(const std::string &name, std::vector<T> &nums) {
    // std::ofstream f(name);

    // for(const auto x : nums) {
    //     f << x << std::endl;
    // }

    return arr::file::dump(name, nums.data(), nums.size());
}


/// Сохранить массив в файл
/// @param name имя файла
/// @param nums массив
/// @param size размер массива
template<typename T>
void arr::file::dump(const std::string &name, T *nums, size_t size) {
    if(not std::filesystem::exists(name)) {
        throw std::runtime_error("файл не существует: " + name);
    }

    std::ofstream f;

    // вызываем исключение при ошибке
    // f.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    f.open(name);
    // fail() может появиться при eof()
    // f.exceptions(std::ifstream::badbit);


    if(!f) {
        // throw std::ofstream::failure(
        throw std::runtime_error(
            "не удалось открыть файл для записи: " + name
        );
    }

    for(size_t i{0}; i < size; i++) {
        f << nums[i] << std::endl;
    }
}


#endif  // CALC_HPP
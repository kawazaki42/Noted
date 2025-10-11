// Шаблоны это исключение из правила про заголовки функций:
// если их делать в .cpp то но скомпилируется!

// это потому что E - это неизвестный тип после компиляции!
// а должен быть известен!

#ifndef OVERLOAD_LIB_HPP
#define OVERLOAD_LIB_HPP

#include <iostream>

// Шаблон функции: обратите внимание на типовую переменную E
// так лучше, потому что функции ничем не отличаются кроме типов


// template <typename E, typename SIZE_T>
template <typename E>  // E от слова элемент
void print_array(E *arr, size_t size) {
    // E x = (E) 0;  // такое тоже бывает

    for(size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}


// можно использовать одновременно и перегрузку, и шаблоны!


template <typename E>
// Нафигачим типовой безопасности за одно
// void print_array(const vector<E> &arr, size_t size) {

// Вектор сам хранит свой размер!
void print_array(const std::vector<E> &arr) {
    // E x = (E) 0;  // такое тоже бывает

    // for(size_t i = 0; i < arr.size(); i++) {
    //     // [i] работает для векторов, как и для массивов
    //     std::cout << arr[i] << " ";
    // }

    // более удобная конструкция:

    for(E l : arr) {
        // [i] работает для векторов, как и для массивов
        std::cout << l << " ";
    }

    std::cout << std::endl;
}


#endif  // OVERLOAD_LIB_HPP
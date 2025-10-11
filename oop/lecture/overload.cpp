#include <iostream>
#include <vector>

#include "overload_lib.hpp"

using namespace std;

// // Перегрузка функции:
// // называются одинаково, но типы разные
// // это пример _статического полиморфизма_ 


// void print_array(float *arr, size_t size) {
//     for(size_t i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
// }


// void print_array(int *arr, size_t size) {
//     for(size_t i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
// }


void do_something() {
    // float *a = new float[10] {1, 2, 333.0/106.0, 4, 5, 6, 7, 8, 9, 0};
    // print_array(a, 10);
    // delete[] a;  // Забыли!

    // // программу не рушит, но расходует лишнюю память!


    // это динамический массив из
    // стандартной библиотеки C++

    // 100 элементов - можно указать размер,
    // а можно не указывать
    vector<float> a(100);
    // vector<float> a{100};

    // (почти) каждый раз по новой выделяет память
    a.push_back(123);
    a.push_back(123);
    a.push_back(123);

    vector<int> b(100);

    // без ссылки не работает!
    // for(int el : b) {
    for(int &el : b) {
        el = 10;
    }

    print_array(a);
    print_array(b);
}


int main() {
    // size_t n = 10;

    // float *a = new float[n] {1, 2, 333.0/106.0, 4, 5, 6, 7, 8, 9, 0};
    // int *b = new int[n] {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    // short *c = new short[n] {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    // double *d = new double[n] {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    
    // // иногда компилятор сам выводит типы,
    // // и тогда можно не писать угловые скобки
    // // print_array(a, n);
    // print_array<float>(a, n);
    // cout << "\n";
    // print_array<int>(b, n);
    // print_array<short>(c, n);
    // print_array<double>(d, n);

    // Если написать неправильно, компилятор выдаст ошибку


    do_something();
}
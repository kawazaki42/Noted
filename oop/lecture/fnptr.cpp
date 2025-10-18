#include <iostream>

using namespace std;

// FVoidFloat - тип указателя на функцию,
// функция должна принимать float и возвращать void

// typedef void(*FVoidFloat)(float);

// то же самое, более понятная запись
using FVoidFloat = void(*)(float);

void print_array(float *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}


// void(*print)(float) - указатель на функцию, который называется print
// функция должна принимать float и возвращать void


void print_array_apply(float *arr, size_t size, FVoidFloat print) {
    for (size_t i = 0; i < size; i++) {
        print( arr[i] );
    }
}


void simple_print(float x) { cout << x << " "; }
void precision_print(float x) { cout << format("{:7.2f}", x) << " "; }


int main() {
    size_t n = 5;
    float *a = new float[n] {
        // `1.` это то же что и `1.0`
        1./2, 2./2, 3./2, 4./7, 5./17
    };

    // переменная типа указателя на функцию
    FVoidFloat func = precision_print;
    func = simple_print;

    func(42.0);

    // идея для троллинга: заменить незаметно sin/cos

    // print_array(a, n, simple_print);
    // ошибка! не вызывам функцию раньше времени!
    // print_array_apply(a, n, precision_print(2));
    print_array_apply(a, n, precision_print);
}


// см. также: std::function
#include <iostream>
#include <cassert>

using namespace std;


int main() {
    // указатель на тип float
    float *p;
    float x = 42;

    p = (float *)42;
    cout <<  p << endl;

    p = &x;  // оператор взятия адреса
    cout <<  p << endl;
    cout << *p << endl;  // обращение к ячейке памяти по адресу p

    *p = 543.34234;

    cout << *p << endl;  // 543...
    cout <<  x << endl;  // 543...


    float &r = x;  // обязательно инициализировать

    cout << r << endl;

    cout << &r << endl;
    
    float y = 10'000;
    r = y;

    cout << x << endl;

    cout << &r << endl;

    cout << r << endl;
}
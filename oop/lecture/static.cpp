#include <iostream>
using namespace std;


void foo() {
    // int x = 0;  // 0 0 0 0
    // static - ведет себя как глобальная
    static int x = 0;  // 0 1 2 3

    cout << x << endl;

    x++;
}


// template <typename T>
// void bar(vector<T>);


int main() {
    foo();
    foo();
    foo();
    foo();
}

/*
 * конспект по статике
 */
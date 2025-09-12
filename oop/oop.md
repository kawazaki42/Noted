http://urait.ru/

Страуструп - C++

как проверить книгу на новизну

C++11:
- `nullptr` = `NULL`

  ```c
  #define NULL = 0
  ```

- `auto` - авто-выведение типа (вместо автоопределения времени существования)
  
  ```c++
  int x;
  auto y = 4u;  // беззнаковый
  ```

Варианты из практики!

Отчет со скринами (чтоб проверить сами ли делали)

переменная среды `PATH` - пути к исполняемым файлам

описать работу в терминале

Завершение на `TAB`

Кнопки со стрелками - история команд

// `mkvmerge` - склейка видео

тесты на `assert`

курсивом - бонусные

Конспекты в 1 файле

задание на 2 недели

```c
#include <cstdio>    // c, не c++
#include <iostream>  // c++, без .h!
```

```c++
3.5l // double!
```


`123.45e-67` = $ 123.45 \cdot 10^{-67} $

Используем `std::string`!

```c++
#include <iostream>

std::cout << "Hello, World!" << std::endl;

// или

using namespace std;
cout << "Hello, World!" << endl;
// Character OUTput, END Line
// << это такая функция
// cout это объект потока вывод

cout << setw(12) << fixed << setprecision(2);

cout << x << endl;

// fixed - без e

string s = format("{:.3f}", 3'000'000.14159265)

```

```c++
// Автор

#include <iostream>  // для ввода-вывода
#include <math.h>    // sqrt - квадратный корень
#include <format>    // -std=c++20

#include "unitA.h"
#include "geometry.h"

using namespace std;  // искать в стандартной библиотеке


/// вычислить расстояние от начала координат до x1, y1 
float distance_from_0(float x1, float y1) {
    return sqrt(x*x + y*y);
}


int main(){
    // if(distance_from_0(1.0, 0.0) != 1.0) {
    //     clog << "СЛОМАЛАСЬ ФУНКЦИЯ!!!" << endl;
    //     exit(1);
    // }

    assert(distance_from_0(1.0, 0.0) == 1.0);
    assert( abs(distance_from_0(0.0, 0.1)) - 0.1 < 1e-6);

    Point p1;  // NOTE: no `struct` keyword needed

    float x, y;
    float d;

    std::cout << "Введите координаты точки\n";

    std::cout << "x = ";
    std::cin >> x;

    std::cout << "y = ";
    std::cin >> y;

    // d = sqrt(x*x + y*y);

    std::cout << std::format("Расстояние = {:.2f}\n", d);
    return 0;
}
```

```c++
/// @file unitA.h

#pragma once

struct A {
    int x;
}
```

```c++
/// @file geometry.cpp


struct Point {
    double x, y;
};


float distance_from_0(float x1, float y1) {
    
}


float distance( const Point &p1, const Point, &p2 ) {
    // & - аналог ключевого слова var в паскале
    // память экономим!
    return sqrt( pow(p1.x, p2.x, 2) + pow(p1.y, p2.y, 2) );
}

void read_point( Point &point ) {
    cout << "x = ";
    cin >> point.x;

    cout << "y = ";
    cin >> point.y;
}

// Одинаковое имя с разными аргументами можно в C++!
// Называется перегрузка функций

Point read_point() {
    Point point;

    return point;
}

Point *read_point() {
    Point point;

    return &point;  // висячий указать! ошибка!
}
```
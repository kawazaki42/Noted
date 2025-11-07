#include <fstream>
#include <iostream>
// #include <stdexcept>
#include <string>
#include <vector>
#include "Lecture.hpp"

using namespace std;


void pretty_print(const Lecture &lec) {
    cout << lec.to_string() << endl;

    float *arr = new float[10];
    // arr - указатель (!) на float (float *)
    // arr - локальная переменная (попадает в стек)
    // 10 ячеек типа float попадут в динамическую память (куча)
    delete[] arr;
}


Lecture lec_oop_1111;


int main() {
    Lecture lec_oop_0;  // является переменной

    // и эти тоже:

    // но точнее их назвать обьектами или экземплярами класса

    // Lecture lec_oop_1;
    // lec_oop_1.title = "Введение в ООП";
    // lec_oop_1.questions = vector<string>();
    // lec_oop_1.resume = "...";

    Lecture lec_oop_2;
    // cout << lec_oop_2.duration;

    vector<string> themes{"struct", "ООП", "UML class diagram"};
    Lecture lec_oop_3("Введение в ООП", 55, themes);
    Lecture lec_oop_4(
        "Введение в ООП", -55,
        {"struct", "ООП", "UML class diagram"}
    );

    Lecture lec_oop_5("Введение в ООП", 55);
    Lecture lec_oop_6("Введение в ООП");

    // lec_oop_4.duration = -55;
    lec_oop_4.set_duration(60);


    // cout << lec_oop_4.to_string();
    cout << lec_oop_4.get_duration();

    const float pi = 3.14159265;
    const Lecture lec_oop_7;

    // ошибка!
    // lec_oop_7.questions = vector<string>{"Что такое ооп", "Что такое класс"};

    cout << lec_oop_7.to_string();
    pretty_print(lec_oop_7);

    // можно и без скобочек было...
    // _динамический_ экземпляр
    // но лучше так не делать! лучше чтоб он авто был (на стеке)
    Lecture *lec_oop_8 = new Lecture();
    // lec_oop_8 - указатель на объект (НЕ сам объект)

    // обычная точка не сработает!

    // ошибка! это же указатель!
    // lec_oop_8.title = "Introduction to OOP";

    (*lec_oop_8).title = "Introduction to OOP";

    // делает то же самое, но красивше
    lec_oop_8->title = "Introduction to OOP";
    cout << lec_oop_8->to_string() << endl;

    delete lec_oop_8;

    // массив из объектов
    // 10 объектов инициализированных дефолтным конструктором
    // в авто памяти (стеке)
    Lecture array[10];

    array[3].set_duration(60);

    // динамический массив
    // в дин. памяти (куче)
    Lecture *array2 = new Lecture[10];

    array2[3].set_duration(60);

    delete[] array2;  // см. cppreference

    const size_t n = 10;

    // статический массив из указателей на объект
    // конструктор ни разу не вызвался!
    Lecture *array_pointers[n];

    for(size_t i{0}; i < n; i++) {
        array_pointers[i] = new Lecture(
            format("Лекция {}", i+1),
            90 + rand()%5
        );
    }

    for(size_t i{0}; i < n; i++) {
        delete array_pointers[i];
    }

    Lecture lec_oop_13("Введение в ООП", 55, vector<string>{"Struct", "OOP", "UML"});

    ofstream file("lec_14.txt");

    file << lec_oop_13.title << endl;
    file << lec_oop_13.get_duration() << endl;

    file.close();

    // массив из обьектов
    vector<Lecture> arr77;  // пустой (0 обьектов)
    vector<Lecture> arr78(10);  // 10 обьектов с дефолтным конструктором

    cout << arr78[4].to_string();

    vector<Lecture> arr79;  // пока пустой
    arr79.resize(10);   // положили 10 обьектов с дефолтным конструктором

    // массив из указателей
    vector<Lecture *> arr80(10);  // массив из указателей
    // мы создали 0 обьектов но 10 указателей

    arr80[4] = new Lecture("Введение в ООП", 55);

    cout << arr80[4]->to_string();

    delete arr80[4];
}
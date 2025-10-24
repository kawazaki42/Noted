#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;


struct Lecture {
    // поля - переменные обьявленные внутри структуры
    // public, private - модификаторы доступа

    public:
        string title;

        vector<string> recap_themes;
        vector<string> themes;
        vector<string> questions;
        string resume;

    private:
        short duration;

    public:

    // конструктор - спец. функция внутри класса (структуры)
    // для инициализации полей
    // Конструктор по умолчанию (без параметров)
    Lecture() {
        title = "";
        duration = 90;
    }

    Lecture(const string &title, short duration1, const vector<string> &themes1) {
        // title - параметр конструктора, не класса!
        // title = title;
        // this - указатель на текущий экземпляр
        // с ним к тому же яснее
        this->title = title;
        // this->duration = duration1;
        set_duration(duration1);
        this->themes = themes1;
    }

    Lecture(const string &title1, short duration1 = 90) {
        title = title1;
        duration = duration1;
    }

    // сеттер для поля duration
    // задает его значение
    void set_duration(short duration1) {
        if(duration > 0) {
            this->duration = duration1;
        } else {
            throw invalid_argument("<= 0");
        }
    }

    // геттер для поля duration
    short get_duration() {
        return duration;
    }

    // метод - функция обьявленная внутри класса

    string to_string() {
        return title + format("; длительность {} минут", duration);
        // todo: выводить другие поля
    }
};


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
}
#include <string>
#include <vector>


/// Класс описывает лекцию (название, темы, длительность...)
// struct Lecture {
class Lecture {
    // struct - public по умолчанию
    // class - private по умолчанию

    // поля - переменные обьявленные внутри структуры
    // public, private - модификаторы доступа

    public:
        std::string title;

        std::vector<std::string> recap_themes;
        std::vector<std::string> themes;
        std::vector<std::string> questions;
        std::string resume;

    // приватим поля, которые следует проверять
    private:
        short duration;

    public:

    // конструктор - спец. функция внутри класса (структуры)
    // для инициализации полей
    // Конструктор по умолчанию (без параметров)
    Lecture();

    Lecture(
        const std::string &title,
        short duration1,
        const std::vector<std::string> &themes1
    );

    Lecture(const std::string &title1, short duration1 = 90);

    // сеттер для поля duration
    // задает его значение
    void set_duration(short duration1);

    // геттер для поля duration
    short get_duration() const;

    // метод - функция обьявленная внутри класса

    std::string to_string() const;
};

/*
 * 
 *
 *
 *
 */
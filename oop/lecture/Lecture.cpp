#include <format>
#include "Lecture.hpp"


Lecture::Lecture() {
    title = "";
    duration = 90;
}


Lecture::Lecture(
    const std::string &title,
    short duration1,
    const std::vector<std::string> &themes1
) {
    // title - параметр конструктора, не класса!
    // title = title;
    // this - указатель на текущий экземпляр
    // с ним к тому же яснее
    this->title = title;
    // this->duration = duration1;
    set_duration(duration1);
    this->themes = themes1;
}


Lecture::Lecture(const std::string &title1, short duration1) {
    title = title1;
    duration = duration1;
}

// сеттер для поля duration
// задает его значение
void Lecture::set_duration(short duration1) {
    if(duration > 0) {
        this->duration = duration1;
    } else {
        throw std::invalid_argument("<= 0");
    }
}

// геттер для поля duration
short Lecture::get_duration() const {
    return duration;
}

// метод - функция обьявленная внутри класса

std::string Lecture::to_string() const {
    return title + std::format("; длительность {} минут", duration);
    // todo: выводить другие поля
}

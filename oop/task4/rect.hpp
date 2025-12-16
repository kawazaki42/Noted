#ifndef RECT_HPP
#define RECT_HPP

#include <cassert>
#include <algorithm>  // std::min
#include "shape.hpp"


namespace fake {
    /// Абстрактный базовый класс для прямоугольника и квадрата.
    template<typename P>
    class basic_rect: public shape<P> {
    public:

        // Получить координаты первого угла.
        virtual point2d<P> get_begin() const = 0;
        // Получить координаты второго угла.
        virtual point2d<P> get_end() const = 0;

        // Переместить первый из двух противоположных углов.
        virtual void set_begin(P x, P y) = 0;
        // Переместить второй из двух противоположных углов.
        virtual void set_end(P x, P y) = 0;

        /// Вычислить ширину.
        virtual P get_width() const = 0;
        /// Вычислить высоту.
        virtual P get_height() const = 0;

        /// Вычислить площадь.
        virtual P get_area() const {
            return get_width() * get_height();
        }

        /// Вычислить периметр.
        virtual P get_perimeter() const {
            return (get_width() + get_height()) * 2;
        }
    };


    /// Прямоугольник.
    template<typename P>
    class rect: public basic_rect<P> {
    // protected:
        /// Два противоположных угла.
        point2d<P> begin, end;

        /// Упорядочить ("нормализовать") противоположные углы.
        void sort_corners() {
            point2d<P> new_begin{
                std::min(begin.x, end.x),
                std::min(begin.y, end.y),
            };

            point2d<P> new_end{
                std::max(begin.x, end.x),
                std::max(begin.y, end.y),
            };

            begin = new_begin;
            end = new_end;
        }

    public:

        rect(point2d<P> begin, point2d<P> end): begin(begin), end(end) {
            sort_corners();
        }

        // делегирующий конструктор
        rect(P bx, P by, P ex, P ey): rect({bx, by}, {ex, ey}) {}

        rect(P x, P y): rect(0, 0, x, y) {}

        // Получить координаты первого угла.
        point2d<P> get_begin() const override {
            return begin;
        }

        /// Получить правый нижний угол.
        point2d<P> get_end() const override {
            return end;
        }

        // TODO: check begin <= end ?
        
        // /// Установить верхний левый угол.
        // virtual void set_corner_ul(P x, P y) {
        //     begin = {x, y};
        // }

        /// Переместить первый из двух противоположных углов.
        void set_begin(P x, P y) override {
            begin = {x, y};
            sort_corners();
        }

        /// Переместить второй из двух противоположных углов.
        void set_end(P x, P y) override {
            end = {x, y};
            sort_corners();
        }

        /// Вычислить ширину.
        P get_width() const override {
            // return std::abs(end.x - begin.x);
            auto result = end.x - begin.x;
            assert(result >= 0);
            return result;
        }

        /// Вычислить высоту.
        P get_height() const override {
            // return std::abs(end.y - begin.y);
            auto result = end.y - begin.y;
            assert(result >= 0);
            return result;
        }

        /// Переместить на указанное смещение.
        void move_relative(P x, P y) override {
            begin.x += x;
            begin.y += y;

            end.x += x;
            end.y += y;
        }
    };
}

#endif  // RECT_HPP

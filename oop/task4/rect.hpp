#ifndef RECT_HPP
#define RECT_HPP

#include <cmath>
#include "shape.hpp"

namespace fake {
    /// Прямоугольник.
    template<typename P>
    class rect: public shape<P> {
    protected:
        /// Два противоположных угла.
        point2d<P> begin, end;

    public:

        rect(point2d<P> begin, point2d<P> end): begin(begin), end(end) {}

        rect(P bx, P by, P ex, P ey): rect({bx, by}, {ex, ey}) {}

        rect(P x, P y): rect(0, 0, x, y) {}

        /// Получить верхний левый угол.
        point2d<P> get_corner_ul() const {
            return begin;
        }

        /// Получить правый нижний угол.
        point2d<P> get_corner_br() const {
            return end;
        }

        // TODO: check begin <= end ?
        
        /// Установить верхний левый угол.
        virtual void set_corner_ul(P x, P y) {
            begin = {x, y};
        }

        /// Установить правый нижний угол.
        virtual void set_corner_br(P x, P y) {
            end = {x, y};
        }

        /// Вычислить ширину.
        P get_width() const {
            return std::abs(end.x - begin.x);
        }

        /// Вычислить высоту.
        P get_height() const {
            return std::abs(end.y - begin.y);
        }

        /// Переместить фигуру на указанное смещение.
        void move_relative(P x, P y) {
            begin.x += x;
            begin.y += y;

            end.x += x;
            end.y += y;
        }

        /// Вычислить площадь.
        P get_area() const override {
            return get_width() * get_height();
        }

        /// Вычислить периметр.
        P get_perimeter() const override {
            return (get_width() + get_height()) * 2;
        }
    };
}

#endif  // RECT_HPP

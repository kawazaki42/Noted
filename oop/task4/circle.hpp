#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <stdexcept>
#include <numbers>
#include "shape.hpp"


namespace fake {
    /// Круг.
    template<typename P>
    class circle: public shape<P> {
        /// Радиус.
        P radius;

    public:

        /// Центр.
        point2d<P> center;

        /// Инициализировать объект.
        ///
        /// @param radius радиус
        /// @param center центр
        circle(P radius, point2d<P> center): center(center) {
            set_radius(radius);
        }

        /// Инициализировать объект.
        ///
        /// @param radius радиус
        /// @param x, y координаты центра
        circle(P radius, P x, P y): circle(radius, {x, y}) {}

        /// Инициализировать окружность в центре координат.
        ///
        /// @param radius радиус
        circle(P radius): circle(radius, {0, 0}) {}

        /// Получить радиус.
        P get_radius() const {
            return radius;
        }

        /// Изменить радиус.
        ///
        /// @throws std::invalid_argument если радиус отрицателен.
        void set_radius(P new_radius) {
            if(new_radius < 0)
                throw std::invalid_argument("radius cannot be negative");

            radius = new_radius;
        }

        /// Переместить фигуру на указанное смещение.
        void move_relative(P x, P y) override {
            center.x += x;
            center.y += y;
        }

        /// Вычислить площадь.
        P get_area() const override {
            return radius * radius * std::numbers::pi_v<P>;
        }

        /// Вычислить периметр.
        P get_perimeter() const override {
            return radius * 2 * std::numbers::pi_v<P>;
        }
    };
}


#endif  // CIRCLE_HPP

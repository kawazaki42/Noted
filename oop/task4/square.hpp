#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <stdexcept>
#include "rect.hpp"


namespace fake {
    /// Квадрат.
    template<typename P>
    class square: public rect<P> {
        /// Точность сравнения.
        static inline const P COMPARE_PRECISION = P(1e-6);

        /// Проверить предусловие: равенство ширины и высоты.
        ///
        /// Нужно для изменения координат углов.
        ///
        /// @param begin координаты левого верхнего угла
        /// @param end координаты правого нижнего угла
        void ensure_square(point2d<P> begin, point2d<P> end) {
            P width = std::abs(end.x - begin.x);
            P height = std::abs(end.y - begin.y);

            // сравнение с учетом машинной погрешности
            if(width - height < COMPARE_PRECISION)
                throw std::invalid_argument(
                    "width and height of square must match"
                );
        }

    public:

        // square(P side): rect<P>(0, 0, side, side) {}

        square(P side, point2d<P> begin):
            rect<P>(begin, {begin.x + side, begin.y + side}) {}

        square(P side, P x, P y): square(side, {x, y}) {}

        square(P side): square(side, {0, 0}) {}

        // TODO: call parent method?

        /// Установить верхний левый угол.
        ///
        /// @throws std::invalid_argument
        ///     если ширина и высота перестанут совпадать при перемещении.
        void set_corner_ul(P x, P y) override {
            ensure_square({x, y}, this->end);
            this->begin = {x, y};
        }

        /// Установить нижний правый угол.
        ///
        /// @throws std::invalid_argument
        ///     если ширина и высота перестанут совпадать при перемещении.
        void set_corner_br(P x, P y) override {
            ensure_square(this->begin, {x, y});
            this->end = {x, y};
        }
    };
}


#endif   // SQUARE_HPP

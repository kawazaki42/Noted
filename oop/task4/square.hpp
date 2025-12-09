#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <stdexcept>
#include "rect.hpp"
#include "shape.hpp"


namespace fake {
    /// Квадрат.
    template<typename P>
    // class square: public rect<P> {
    class square: public basic_rect<P> {
        // Один из углов.
        point2d<P> begin;
        // Сторона.
        P size;

        /// Точность сравнения.
        static inline const P COMPARE_PRECISION = P(1e-6);

        /// NOTE: 1e-6 преобразуется в 0 для целочисленных типов!

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
            if(std::abs(width - height) > COMPARE_PRECISION)
                throw std::invalid_argument(
                    "width and height of square must match"
                );
        }

    public:

        // square(P side): rect<P>(0, 0, side, side) {}

        square(P side, point2d<P> begin):
            // rect<P>(begin, {begin.x + side, begin.y + side}) {}
            begin(begin), size(side) {}

        square(P side, P x, P y): square(side, {x, y}) {}

        square(P side): square(side, {0, 0}) {}

        // // TODO: call parent method?

        // /// Установить верхний левый угол.
        // ///
        // /// @throws std::invalid_argument
        // ///     если ширина и высота перестанут совпадать при перемещении.
        // void set_corner_ul(P x, P y) override {
        //     ensure_square({x, y}, this->end);
        //     this->begin = {x, y};
        // }

        /// Получить координаты первого угла.
        point2d<P> get_begin() const override {
            return begin;
        }

        /// Получить координаты второго угла.
        point2d<P> get_end() const override {
            return {begin.x + size, begin.y + size};
        }

        /// Переместить первый из двух противоположных углов.
        ///
        /// @throws std::invalid_argument
        ///     если ширина и высота перестанут совпадать при перемещении.
        void set_begin(P x, P y) override {
            ensure_square({x, y}, get_end());
            size = get_end().x - x;
            begin = {x, y};
        }


        /// Установить верхний левый угол.
        ///
        /// @throws std::invalid_argument
        ///     если ширина и высота перестанут совпадать при перемещении.

        /// Переместить второй из двух противоположных углов.
        ///
        /// @throws std::invalid_argument
        ///     если ширина и высота перестанут совпадать при перемещении.
        void set_end(P x, P y) override {
            ensure_square(begin, {x, y});
            // this->end = {x, y};
            size = x - begin.x;
            // assert(std::abs((y - begin.y) - size) < COMPARE_PRECISION);
        }

        /// Вычислить ширину.
        P get_width() const override {
            return size;
        }

        /// Вычислить высоту.
        P get_height() const override {
            return size;
        }

        void move_relative(P x, P y) override {
            begin.x += x;
            begin.y += y;
        }
    };
}


#endif   // SQUARE_HPP

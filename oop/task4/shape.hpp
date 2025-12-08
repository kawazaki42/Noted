#ifndef SHAPE_HPP
#define SHAPE_HPP

// #include <cmath>
// #include <numbers>
// #include <stdexcept>


namespace fake {


    /// Точка на двухмерном пространстве.
    template<typename P>
    struct point2d {
        P x, y;
    };


    /// Абстрактный класс геометрической фигуры.
    template<typename P>
    class shape {
    public:
        /// Вычислить площадь.
        virtual P get_area() const = 0;
        /// Вычислить периметр.
        virtual P get_perimeter() const = 0;
    };


}


#endif  // SHAPE_HPP

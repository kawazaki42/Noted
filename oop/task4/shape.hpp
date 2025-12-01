#include <cmath>
#include <numbers>
#include <stdexcept>


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
        void move_relative(P x, P y) {
            center += x;
            center += y;
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

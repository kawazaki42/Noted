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
        virtual get_area() const = 0;
        /// Вычислить периметр.
        virtual get_perimeter() const = 0;
    };

    /// Прямоугольник.
    template<typename P>
    class rect: public shape {
    protected:
        /// Два противоположных угла.
        point2d<P> begin, end;

    public:

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
    class square: public rect {
        /// Точность сравнения.
        static const P COMPARE_PRECISION = P(1e-6);

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

        // TODO: call parent method?

        /// Установить верхний левый угол.
        ///
        /// @throws std::invalid_argument
        ///     если ширина и высота перестанут совпадать при перемещении.
        void set_corner_ul(P x, P y) override {
            ensure_square({x, y}, end);
            begin = {x, y};
        }

        /// Установить нижний правый угол.
        ///
        /// @throws std::invalid_argument
        ///     если ширина и высота перестанут совпадать при перемещении.
        void set_corner_br(P x, P y) override {
            ensure_square(begin, {x, y});
            end = {x, y};
        }
    };

    /// Круг.
    template<typename P>
    class circle: public shape {
        /// Радиус.
        P radius;

    public:

        /// Центр.
        point2d<P> center;

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

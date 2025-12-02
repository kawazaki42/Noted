namespace dumb {
    struct complex {
        double real, imag;

        complex();
        complex(double real, double imag = 0);

        complex operator +(const complex &other) const;
        complex operator -(const complex &other) const;
        complex operator *(const complex &other) const;
        double arg() const;
        double abs() const;
    };
}

#include <cstddef>
#include <iostream>

using std::cout, std::endl, std::vector;


struct Inventory {
    // TODO: массив из вещей
    double weight;
    std::size_t count;

    // без static хранится в каждом объекте (неэффективно)
    // а со static принадлежит классу а не объекту
    // static const size_t max_count = 1024;
    static const size_t max_count{1024};

    static size_t objcount;

    static Inventory create_random_inventory() {
        Inventory result{rand()%1000/10.0+1, static_cast<size_t>(1+ rand()%100)};
        return result;
    }

    // списки инициализации. присваивают полям указанные значения.
    Inventory(): weight(0), count(0) {}

    // делает то же, что и:

    // Inventory() {
    //     weight = 0;
    //     count = 0;
    // }

    // но возможно даже быстрее
    
    Inventory( size_t n ): count(n), weight(1 * n) {
        objcount++;
    }
    
    // но также не забываем про сеттеры!
    // Inventory(float x, size_t n): count(n) {
    //     set_weight(x);  // он делает проверку
    // }

    Inventory(double x, size_t n): weight(x), count(n) {
        objcount++;
    }

    void add(const Inventory &inv2) {
        this->weight += inv2.weight;
        this->count += inv2.count;
    }

    std::string to_string() const {
        return std::format("weight: {:.2f}, count: {}", weight, count);
    }
};


size_t Inventory::objcount{0};


Inventory merge(const Inventory &i1, const Inventory &i2) {
    return Inventory(i1.weight + i2.weight, i1.count + i2.count);
}


Inventory operator +(const Inventory &i1, const Inventory &i2) {
    return Inventory(i1.weight + i2.weight, i1.count + i2.count);
}


class Array {
public:
    int id;
    int *arr;
    std::size_t n;
public:

    // конструктор
    Array(): n(0), arr(nullptr) {
        id = std::rand() % 100;
        cout << "Default constructor" << id << endl;
        // cout << "конструктор" << endl;

        // n = 100;
        // arr = new int[100];
    }

    // автоматически нам дают конструктор
    // A() {}

    // компилятор нам создаст такой конструктор (копирования)
    // но он тоже плохой
    // Array(const Array &a): n(a.n), arr(a.arr) {}

    Array(const Array &rhs) {
        this->n = rhs.n;
        if(arr != nullptr)
            delete[] arr;

        // this->arr = rhs.arr;
        this->arr = new int[this->n];

        for(size_t i{0}; i < this->n; i++)
            this->arr[i] = rhs.arr[i];

        // return *this;
    }

    Array(size_t n): n(n) {
        arr = new int[n];
    }

    // если у нас есть конструктор с параметрами,
    // то автоматического конструктора не будет
    Array(int id1, std::size_t size) {
        id = id1;
        cout << "constructor 2 " << id << endl;
        n = size;
        arr = new int[size];
    }

    // правило: если есть деструктор, подумайте о том чтоб сделать operator=

    // кстати о нем удобно думать как об операторе перезаписи

    // аргумент - правая часть оператора присвоения
    Array &operator =(const Array &rhs) {
        this->n = rhs.n;
        if(arr != nullptr)
            delete[] arr;

        // this->arr = rhs.arr;
        this->arr = new int[this->n];

        for(size_t i{0}; i < this->n; i++)
            this->arr[i] = rhs.arr[i];

        return *this;
    }

    // деструктор
    // он кстати отказывается принимать параметры
    // а значит неперегрузимый
    ~Array() {
        // cout << "деструктор" << endl;
        cout << "destructor " << id << endl;

        if(arr != nullptr)
            delete[] arr;
    }
};


int main() {
    // A a1;       // c
    // A *a2;      // -
    // A aaa1[3];  // ccc
    // cout << endl;

    // A *aaa2[3]; // -
    // aaa2[0] = new A(100);  // c

    // vector<A> vec1;       // -
    // vector<A> vec2(3);  // ccc

    // delete aaa2[0];  // d

    // Array a;
    // Array a(1, 1000);

    Inventory i1(7, 15), i2(1, 2);

    // работает благодаря 1-аргументному конструктору
    Inventory i3 = 24;
    Inventory i33(24);
    Inventory i333 = Inventory(24);

    cout << i1.to_string() << endl;
    cout << i2.to_string() << endl;

    // i1.add(i2);

    cout << i1.to_string() << endl;
    cout << endl;

    // Inventory i4 = merge(i1, i2);
    Inventory i4 = i1 + i2;
    cout << i4.to_string() << endl;

    Array a1(10);
    Array a2(a1);  // вызывается конструктор копирования
    Array a3 = a1; // тоже
    a2 = a1; // вызывается оператор присвоения, потому что a2 уже существует

    // правило трех: деструктор, operator =, конструктор копирования
    // т.н. deepcopy

    // если бы мы не перегрузили, то был бы shallow copy

    // правило пяти: (то же, но с перемещением) сами конспект

    // оператор присвоения!
    a2 = a1;

    a1.arr[0] = 123;
    cout << "arr[0] = " << a2.arr[0];  // 123
    // это потому что мы скопировали указатель, а не весь массив!
    // переписываем реалицацию `operator =`!

    Inventory i5(12, 4);
    
    Inventory i6(2, 1);

    cout << "max_count = " << i5.max_count << endl;
    // так можно благодаря static
    cout << "max_count = " << Inventory::max_count << endl;

    // работает, но нам не нужно
    // Inventory::objcount = 100;

    Inventory i7 = Inventory::create_random_inventory();

    // тоже можно, но нечитаемо
    Inventory i8 = i7.create_random_inventory();
}
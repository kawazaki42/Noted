#include <iostream>

using std::cout, std::endl, std::vector;


struct Inventory {
    // TODO: массив из вещей
    float weight;
    std::size_t count;

    Inventory(float x, size_t n): weight(x), count(n) {}

    void add(const Inventory &inv2) {
        this->weight += inv2.weight;
        this->count += inv2.count;
    }

    std::string to_string() const {
        return std::format("weight: {:.2f}, count: {}", weight, count);
    }
};


Inventory merge(const Inventory &i1, const Inventory &i2) {
    return Inventory(i1.weight + i2.weight, i1.count + i2.count);
}


Inventory operator +(const Inventory &i1, const Inventory &i2) {
    return Inventory(i1.weight + i2.weight, i1.count + i2.count);
}


class Array {
    int id;
    int *arr;
    std::size_t n;
public:

    // конструктор
    Array() {
        id = std::rand() % 100;
        cout << "Default constructor" << id << endl;
        // cout << "конструктор" << endl;

        n = 100;
        arr = new int[100];
    }

    // автоматически нам дают конструктор
    // A() {}

    // если у нас есть конструктор с параметрами,
    // то автоматического конструктора не будет
    Array(int id1, std::size_t size) {
        id = id1;
        cout << "constructor 2 " << id << endl;
        n = size;
        arr = new int[size];
    }

    // деструктор
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

    cout << i1.to_string() << endl;
    cout << i2.to_string() << endl;

    // i1.add(i2);

    cout << i1.to_string() << endl;
    cout << endl;

    // Inventory i4 = merge(i1, i2);
    Inventory i4 = i1 + i2;
    cout << i4.to_string() << endl;
}
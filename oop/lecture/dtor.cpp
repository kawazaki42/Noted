#include <cassert>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// если кто не понял читайте учебник!
// (а вы и не поймете...)

using std::cout, std::cerr, std::string, std::endl, std::vector;


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


class Quest {
public:
    std::string description;

    Quest(std::string desc): description{desc} {}
};


class Biography {
    // ...
};


/// базовый класс
class Weapon {
    private:
        float damage;
    public:
        std::string name;

    Weapon(): damage(1) {}
    Weapon(std::string name, float damage) {
        this->name = name;
        set_damage(damage);
    }

    void set_damage(float d) {
        if(d > 0)
            this->damage = d;
        else
            throw std::invalid_argument("?");
    }

    float get_damage() const {
        return this->damage;
    }

    // virtual отвечает за динамический полиморфизм
    // для реализаций to_string у потомков
    virtual std::string to_string() const {
        return format("<Weapon {}\ndamage={}>", name, damage);
    }
};


class Axe: public Weapon {
public:
    bool can_break_armor;

    Axe(std::string name1, float damage1, bool can_break_armor):
        Weapon(name1, damage1), can_break_armor(can_break_armor) {}

    // а лучше родительский вызвать просто!
    std::string to_string() const override {
        return format("<Weapon {}\ndamage={} break_armor={}>",
                      name, get_damage(), can_break_armor);
    }

};


///
class Bow: public Weapon {
    float distance;

    public:
        // дополнительно автоматически вызовется
        // конструктор без параметров базового класса
        Bow(): distance{1} {}

        ///
        Bow(std::string name1, float damage1, float distance1):
            Weapon(name1, damage1) {
                set_distance(distance1);
        }

        float get_distance() const {
            return distance;
        }

        void set_distance(float distance1) {
            if(distance1 >= 0)
                distance = distance1;
        }

        // переопределение метода (override)
        std::string to_string() const;
};


// реализация
std::string Bow::to_string() const {
    // вызовет метод базового класса
    return Weapon::to_string()
        + std::format("\ndistance: {:.1f}", distance);
}


float f1(int x) {return     sqrt(x); }
float f2(int x) {return 1.0/sqrt(x); }

// тип указателя на фцию
using FPointer1 = float (int);
using FPointer2 = float(*)(int);

using MPointer1 = float(Bow::*)() const;


class GameCharacter {
    public:
        Inventory inventory;   // композиция с Inventory
        vector<Quest> quests;  // агрегация с Quest
        Biography bio;         // композиция с Biography
        Weapon *hand;          // агрегация с Weapon

    GameCharacter() {
        hand = nullptr;
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
    // // A a1;       // c
    // // A *a2;      // -
    // // A aaa1[3];  // ccc
    // // cout << endl;

    // // A *aaa2[3]; // -
    // // aaa2[0] = new A(100);  // c

    // // vector<A> vec1;       // -
    // // vector<A> vec2(3);  // ccc

    // // delete aaa2[0];  // d

    // // Array a;
    // // Array a(1, 1000);

    // Inventory i1(7, 15), i2(1, 2);

    // // работает благодаря 1-аргументному конструктору
    // Inventory i3 = 24;
    // Inventory i33(24);
    // Inventory i333 = Inventory(24);

    // cout << i1.to_string() << endl;
    // cout << i2.to_string() << endl;

    // // i1.add(i2);

    // cout << i1.to_string() << endl;
    // cout << endl;

    // // Inventory i4 = merge(i1, i2);
    // Inventory i4 = i1 + i2;
    // cout << i4.to_string() << endl;

    // Array a1(10);
    // Array a2(a1);  // вызывается конструктор копирования
    // Array a3 = a1; // тоже
    // a2 = a1; // вызывается оператор присвоения, потому что a2 уже существует

    // // правило трех: деструктор, operator =, конструктор копирования
    // // т.н. deepcopy

    // // если бы мы не перегрузили, то был бы shallow copy

    // // правило пяти: (то же, но с перемещением) сами конспект

    // // оператор присвоения!
    // a2 = a1;

    // a1.arr[0] = 123;
    // cout << "arr[0] = " << a2.arr[0];  // 123
    // // это потому что мы скопировали указатель, а не весь массив!
    // // переписываем реалицацию `operator =`!

    // Inventory i5(12, 4);
    
    // Inventory i6(2, 1);

    // cout << "max_count = " << i5.max_count << endl;
    // // так можно благодаря static
    // cout << "max_count = " << Inventory::max_count << endl;

    // // работает, но нам не нужно
    // // Inventory::objcount = 100;

    // Inventory i7 = Inventory::create_random_inventory();

    // // тоже можно, но нечитаемо
    // Inventory i8 = i7.create_random_inventory();

    GameCharacter Steve;

    Weapon *sword = new Weapon();

    Steve.hand = sword;

    Quest kill_dragon("Убить дракона");

    Steve.quests.push_back(kill_dragon);

    delete sword;

    Weapon w("Меч", 20);

    cout << w.to_string() << endl;

    Axe a("Базовый топор", 4, false);

    // унаследовали метод to_string
    cout << a.to_string() << endl;

    Bow bow("Простой лук", 2, 5);

    cout << bow.to_string() << endl;

    // вызов родительского метода вне класса (но зачем)
    cout << bow.Weapon::to_string() << endl;

    // Weapon *bow = new Weapon();

    // delete bow;

    w = a;  // записать можно, но пропадет доп. поле can_break_armor

    // воду перелили, грубо говоря, и пролили

    // родительский метод (тот который в Weapon)
    cout << w.to_string() << endl;

    // w.can_break_armor = true  // ошибка: его больше нет

    // a = w;  // ошибка

    Axe *axe2 = new Axe("Bloody Hell Axe of Pain", 40, false);
    cout << axe2->to_string() << endl;

    Weapon *w2 = axe2;  // тут тоже преобразование
    cout << w2->to_string() << endl;  // поле can_break_armor не отображается!
    
    // а с virtual - без преобразования
    // после virtual - отображается

    // virtual "отключает" приведение типов при указателях

    Axe axe3 = Axe("Базовый топор", 4, false);
    Weapon w3 = a;  // преобразование
    cout << w3.to_string() << endl;  // поле can_break_armor не отображается!

    // чтоб работал динамический полиморфизм:
    // - используем указатели
    // - нужны virtual методы
    //   - virtual делаем все что предназначено для переопределения

    // еще можно ключевое слово override указать, для самопроверки

    // w2->can_break_armor = false;  // нету такого поля

    // придется кастовать!

    // C-style cast
    int x = (int)33.22;

    // тоже, но кринж! осуждаем. почему?
    ( (Axe *)w2 )->can_break_armor = false;  // работает вроде
    // потому что компилятор пропускает такую ерунду:
    ( (std::string *)w2 )[0] = 'O';

    cout << w2->to_string() << endl;

    // надо вот так!
    Axe *axe22 = dynamic_cast<Axe *>(w2);
    if(axe22 == nullptr)
        // не удалось преобразовать
        cerr << "каст не проканал :(" << endl;
    else {
        axe22->can_break_armor = false;
        cout << axe22->to_string() << endl;
    }

    string *axe33 = dynamic_cast<string *>(w2);  // дает nullptr
    if(axe33 == nullptr)
        // не удалось преобразовать
        cerr << "каст не проканал :(ну и правильно)" << endl;
    else {
        axe33[0] = '?';
        // cout << axe22->to_string() << endl;
        cerr << "WTF??" << endl;
    }

    // если бы w2 был не Axe, а просто Weapon, то dynamic_cast провалится

    srand(time(0));

    Weapon *w4;

    if(rand() % 2 == 0) {
        w4 = new Bow("чеснок", 5, 10);
    } else {
        w4 = new Axe("дезодорант", 10, 1);
    }

    // если убрать virtual, спец. поля не будут выводиться
    w4->to_string();

    // В Weapon нету set_distance!
    // Даже если у нас 100% Bow, то не скомпилируется!
    // w4->set_distance(10);

    // если мы уверены что там Bow *, можем сделать так
    dynamic_cast<Bow *>(w4)->set_distance(10);
    // делает то же самое но это небезопасно!
    // но если мы прям очень увертены м
    ((Bow *)w4)->set_distance(10);

    // переопределенный метод
    dynamic_cast<Bow *>(w4)->to_string();
    // то же самое, потому что virtual метод
    w4->to_string();

    Bow *b = new Bow("чеснок", 5, 10);
    dynamic_cast<Weapon *>(b)->to_string();

    Weapon *w5 = dynamic_cast<Weapon *>(b);
    w5->to_string();

    // если очень надо вызвать именно родительский
    w5->Weapon::to_string();

    Bow *b2 = dynamic_cast<Bow *>(w4);
    if ( b2 != nullptr)
        b2->set_distance(10);

    // показать полиморфизм:
    // - dynamic_cast
    // - и без dynamic_cast

    delete w4;
    delete b;

    {
        // пример для юниттестов
        Bow b("Лук1", 5, 10);

        assert( b.get_distance() == 10 );
        assert( b.get_damage() == 5 );
        assert( b.name == "Лук1" );
    }

    {
        Bow b;
        assert( b.get_distance() == 1 );
        assert( b.get_damage() == 1 );
    }

    {
        Bow b;
        b.set_distance(8);
        assert( b.get_distance() == 8 );
    }

    {
        Bow b;
        try {
            b.set_distance(-1);

            // мы не должны дойти сюда.

            // используем заведомо ложные условия
            assert( ("Исключение не брошено!", false) );
            assert( "Исключение не брошено!" == "!" );
        } catch (const std::invalid_argument &e) {
            // исключение брошено - тест пройден
        }
        // assert( b.get_distance() == 8 );
    }

    // c-style cast
    int y = (int) 3.14;
    char *c = (char *) y;
    // string s = (string) x;  // даже не работает
    vector<int> v;
    // string s = (string) v;  // тоже

    // static_cast
    int y2 = static_cast<int>(3.14);

    // dynamic_cast - на этапе выполнения (runtime)
    Weapon *wb = new Bow;

    // кайф, он знает что он на самом деле Bow
    // каст не требуется
    cout << wb->to_string() << endl;

    // не знает такой метод!
    // w->set_distance(42);

    Bow *bw = dynamic_cast<Bow *>(wb);

    if(bw == nullptr)
        cerr << "каст не проканал" << endl;
    else
        bw->set_distance(42);

    // reinterpret_cast - читает двоичное представление "по-другому"

    // динамический массив из байт для записи в файл
    char *bytes = reinterpret_cast<char *>(bw);
    sizeof(*bw);  // размер массива
    sizeof(Bow);  // делает то же самое

    Bow b1("Лук1", 5, 10);
    Bow b12("Лук1", 5, 10);

    // надо перегрузить оператор сравнения
    // равенство: если компоненты равны
    // bool is_equal = b1 == b12;  // по идее true

    // идентичность: если хранятся в одной ячейки памяти
    Bow &b3 = b1;  // идентичны
    Bow *b4 = &b1; // *b4 и b1 идентичны

    FPointer2 fp = f1;
    // FPointer1 fp2;
    // float f = 3.14;
    // fp2 = &f;
    fp(90);  // вызовет f1
    fp = f2;
    fp(90);  // вызовет f2

    const MPointer1 p = &Bow::get_distance;
    // b.*p();  // TODO
}

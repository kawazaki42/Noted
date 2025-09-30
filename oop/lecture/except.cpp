#include <iostream>


// todo: doc
float triangle_square(float h, float a) {
    if( (a > 0) and (h > 0) )
        return 0.5 * a * b;
    else
        // throw std::string("Error: a < 0 or h < 0");
        throw std::invalid_argument("Error: a < 0 or h < 0");
        // наша ошибка летит до ближайшего обработчка
        // (если он есть)
    
    // std::cerr << "Error in triangle_square" << std::endl;
    // return 0;

    std::cout << "сюда функция не зайдет!"
}


// плохой дизайн!
float triangle_square2(float h, float a) {
    try {
        if( (a > 0) and (h > 0) )
            return 0.5 * a * b;
        else
            // throw std::string("Error: a < 0 or h < 0");
            throw std::invalid_argument("Error: a < 0 or h < 0");
        
        // std::cerr << "Error in triangle_square" << std::endl;
        // return 0;
    
        std::cout << "сюда функция не зайдет!"
    } catch () {
        // ...
    }
}


int main() {
    try {
        std::cout << "S = " << triangle_square(1, 1) << std::endl;
        std::cout << "S = " << triangle_square(-3, 1) << std::endl;
        std::cout << "сюда функция не зайдет!"
    // } catch (std::string error) {
    } catch (std::invalid_argument error) {
        std::cerr << "Возникла ошибка во время вызова triangle_square"
            // << error << std::endl;
            << error.what() << std::endl;
    }

    return 0;
}

// Вывод: проверяйте предусловия;
//        кидайте исключения;
//        используйте наиболее конкретный тип;
//        пишите try-catch;
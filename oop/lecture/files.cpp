#include <fstream>

std::ifstream i;  // input filestream
std::ofstream o;  // output filestream
std::fstream io;  // input-output filestream



using namespace std;

ofstream f("myfile.txt");

if ( f.is_open() ) {
    f << "qwerty";
    f << 123;
    f << 3.14;
    f << "\n";
    f << 42.5;
    f.close();
}


std::ifstream myfile;
myfile.open("example.bin", ios::out | ios::app | ios::binary);

// ios::app - для дописывания в конец
// ios::in - readonly (по умолчанию в ifstream)
// ios::out - writeonly (по умолчанию в ofstream)
// ios::trunc - перезапись
// ios::ate - указатель в конец

// Текстовый: пишем 42
// {'4', '2'}  // 2 байта

// Двоичный: пишем 42
// {42}  // 1 байт

// Двоичные обычно более экономны, но нечитаемы без программ

// Флаги (условно):
// ios::in  = 1000
// ios::out = 0100
// ios::app = 0010
// делаем побитовое И
// 1110

// f << 
// f >>

// std::stod

// getline - вместе с пробелами
// возвращает boolean
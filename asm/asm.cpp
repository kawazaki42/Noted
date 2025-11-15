// проверено на g++ x86-64

#include <iostream>
#include <cstdint>

using namespace std;


int main() {
    int32_t input, output;

    cin >> input;

    asm(R"(
        // наш привычный синтаксис ассемблера
        .intel_syntax noprefix

        // второй (входной) регистр из списков
        mov eax, %1

        add eax, 42

        // первый (выходной) регистр из списков
        mov %0, eax

        // ломается, если не вернуть
        // родной синтаксис для GNU Assembler
        .att_syntax
    )"
    // перезаписывает регистр переменной output
    : "=r"(output)
    // берет на вход регистр переменной input
    : "r"(input)
    // изменяет регистр eax, флаги
    : "eax", "cc");

    cout << output << endl;
}
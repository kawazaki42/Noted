int main(int argc, char argv[][]) {
    // argc - кол-во аргументов
    // argv - аргументы
    // 0-й аргумент - это имя программы
    
    // т.е.
    // ```
    // $ .\main.exe
    // ```
    // дает
    // argc = 1
    // argv = {".\main.exe"}

    // ```
    // $ .\main.exe input.txt output.txt
    // ```
    // дает
    // argc = 3
    // argv = {".\main.exe", "input.txt", "output.txt"}

    // ```
    // $ .\main.exe 10 20
    // ```
    // дает
    // argc = 3
    // argv = {".\main.exe", "10", "20"}
}

// C:\>main.exe input.txt output.txt
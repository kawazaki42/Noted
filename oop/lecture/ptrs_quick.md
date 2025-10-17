```c++
int x = 100;  // x [100] <- pointer, pointer2, ref, ref2

int *pointer;  // указатель - хранит адрес
int *pointer2 = &x;

pointer = &x;  // взятие адреса

x = 1001;

*pointer = 1002;  // `*` -  разыменование

*pointer2 = 1004;
```

```c++
int &ref = x;  // тоже хранит адрес, но удобнее

ref = 1003;    // попадет в `x`

// ref = &y    // ошибка

// int &ref2 = &1003;  // ошибка

int &ref2 = ref;  // тот же самый адрес
```
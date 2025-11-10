1a) f = (01101011)
1b) f = (01100001)

| x_1 | x_2 | x_3 | f   |
| --- | --- | --- | --- |
| 0   | 0   | 0   | 0   |
| 0   | 0   | 1   | 1   |
| 0   | 1   | 0   | 1   |
| 0   | 1   | 1   | 0   |
| 1   | 0   | 0   | 1   |
| 1   | 0   | 1   | 0   |
| 1   | 1   | 0   | 1   |
| 1   | 1   | 1   | 1   |

###### система уравнений

```math
P(x;y;z) = a_0
\oplus a_1 x_1
\oplus a_2 x_2
\oplus a_3 x_3
\oplus a_4 x_1 x_2
\oplus a_5 x_1 x_3
\oplus a_6 x_2 x_3
\oplus a_7 x_1 x_2 x_3
```

P(x_1; x_2; x_3)

```math
P(0; 0; 0) = a_0
\oplus a_1 \cdot 0
\oplus a_2 \cdot 0
\oplus a_3 \cdot 0
\oplus a_4 \cdot 0 \cdot 0
\oplus a_5 \cdot 0 \cdot 0
\oplus a_6 \cdot 0 \cdot 0
\oplus a_7 \cdot 0 \cdot 0 \cdot 0
= 0
```

```math
P(0; 0; 1) = a_0
\oplus a_1 \cdot 0
\oplus a_2 \cdot 0
\oplus a_3 \cdot 1
\oplus a_4 \cdot 0 \cdot 0
\oplus a_5 \cdot 0 \cdot 1
\oplus a_6 \cdot 0 \cdot 1
\oplus a_7 \cdot 0 \cdot 0 \cdot 1
= 1
```

```math
P(0; 1; 0) = a_0
\oplus a_1 \cdot 0
\oplus a_2 \cdot 1
\oplus a_3 \cdot 0
\oplus a_4 \cdot 0 \cdot 1
\oplus a_5 \cdot 0 \cdot 0
\oplus a_6 \cdot 1 \cdot 0
\oplus a_7 \cdot 0 \cdot 1 \cdot 0
= 1
```

```math
P(0; 1; 1) = a_0
\oplus a_1 \cdot 0
\oplus a_2 \cdot 1
\oplus a_3 \cdot 1
\oplus a_4 \cdot 0 \cdot 1
\oplus a_5 \cdot 0 \cdot 1
\oplus a_6 \cdot 1 \cdot 1
\oplus a_7 \cdot 0 \cdot 1 \cdot 1
= 0
```

```math
P(1; 0; 0) = a_0
\oplus a_1 \cdot 1
\oplus a_2 \cdot 0
\oplus a_3 \cdot 0
\oplus a_4 \cdot 1 \cdot 0
\oplus a_5 \cdot 1 \cdot 0
\oplus a_6 \cdot 0 \cdot 0
\oplus a_7 \cdot 1 \cdot 0 \cdot 0
= 1
```

```math
P(1; 0; 1) = a_0
\oplus a_1 \cdot 1
\oplus a_2 \cdot 0
\oplus a_3 \cdot 1
\oplus a_4 \cdot 1 \cdot 0
\oplus a_5 \cdot 1 \cdot 1
\oplus a_6 \cdot 0 \cdot 1
\oplus a_7 \cdot 1 \cdot 0 \cdot 1
= 0
```

```math
P(1; 1; 0) = a_0
\oplus a_1 \cdot 1
\oplus a_2 \cdot 1
\oplus a_3 \cdot 0
\oplus a_4 \cdot 1 \cdot 1
\oplus a_5 \cdot 1 \cdot 0
\oplus a_6 \cdot 1 \cdot 0
\oplus a_7 \cdot 1 \cdot 1 \cdot 0
= 1
```

```math
P(1; 1; 1) = a_0
\oplus a_1 \cdot 1
\oplus a_2 \cdot 1
\oplus a_3 \cdot 1
\oplus a_4 \cdot 1 \cdot 1
\oplus a_5 \cdot 1 \cdot 1
\oplus a_6 \cdot 1 \cdot 1
\oplus a_7 \cdot 1 \cdot 1 \cdot 1
= 1
```

---

$$a_0 \oplus 0 = 0$$

$$a_0 = 0$$

$$0 \oplus a_3 = 1$$

$$a_3 = 1$$

$$a_2 \oplus 0 = 1$$

$$a_2 = 1$$

$$a_2 \oplus a_3 \oplus a_6 = 0$$

$$1 \oplus 1 \oplus a_6 = 0$$

$$0 \oplus a_6 = 0$$

$$a_6 = 0$$

$$a_1 = 1$$

$$a_1 \oplus a_3 \oplus a_5 = 0$$

$$1 \oplus 1 \oplus a_5 = 0$$

$$0 \oplus a_5 = 0$$

$$a_5 = 0$$

$$a_1 \oplus a_2 \oplus a_4 = 1$$

$$1 \oplus 1 \oplus a_4 = 1$$

$$0 \oplus a_4 = 1$$

$$a_4 = 1$$

$$0 \oplus 1 \oplus 1 \oplus 1 \oplus 1 \oplus 0 \oplus 0 \oplus a_7 = 1$$

$$a_7 = 1$$

---

$$x_1 \oplus x_2 \oplus x_3 \oplus x_1 x_2 \oplus x_1 x_2 x_3$$

## треугольник паскаля

| x_1 | x_2 | x_3 | f   |
| --- | --- | --- | --- |
| 0   | 0   | 0   | 0   | 0 1 1 0 1 0 1 1
| 0   | 0   | 1   | 1   |  1 0 1 1 1 1 0   x_3
| 0   | 1   | 0   | 1   |   1 1 0 0 0 1    x_2
| 0   | 1   | 1   | 0   |    0 1 0 0 1
| 1   | 0   | 0   | 1   |     1 1 0 1      x_1
| 1   | 0   | 1   | 0   |      0 1 1
| 1   | 1   | 0   | 1   |       1 0        x_1 x_2
| 1   | 1   | 1   | 1   |        1         x_1 x_2 x_3

$$x_1 \oplus x_2 \oplus x_3 \oplus x_1 x_2 \oplus x_1 x_2 x_3$$

|     |        | x_2    | x_2    |        |     |     |     |     |
| --- | ------ | ------ | ------ | ------ | --- | --- | --- | --- |
| x_1 | 100: 1 | 110: 1 | 111: 1 | 101    |     |     |     |     |
|     | 000    | 010: 1 | 011    | 001: 1 |     |     |     |     |
|     |        |        | x_3    | x_3    |     |     |     |     |

|              | notX1notX2X3 | notX1X2notX3 | X1notX2notX3 | X1X2notX3 | X1X2X3 |
| ------------ | ------------ | ------------ | ------------ | --------- | ------ |
| X1notX3      |              |              | O            | O         |        |
| X1X2         |              |              |              | O         | O      |
| X2notX3      |              | O            |              | O         |        |
| notX1notX2X3 | O            |              |              |           |        |

$$\overline x = 1 \oplus x$$


---


$$x1(1 \oplus x3)$$
$$x1x2$$
$$x2(1 \oplus x2)$$
$$x3(1 \oplus x1)(1 \oplus x2)$$

---

$$x1 \oplus x1x3$$
$$x1x2$$
$$x2 \oplus x_2x2$$
$$(x3 \oplus x1x3)(1 \oplus x2)$$

$$(x3 \oplus x1x3) \oplus (x2x3 \oplus x1x2x3)$$

---

not(not(X1notX3) and not(X1X2) and not(X2notX3) and not(notX1notX2X3))

x1 | x1x3 | x1x2x3 | x1x3 | x1x2x3 | x1x2

x1x3 | x1x3 | x1x2x3 | x1x3 | x1x2x3 | x1x2x3

x1x2x3 x6

---

x1 | x1x2x3 | x1x2x3 | x1x2

x1x3 | x1x2x3 | x1x2x3 | x1x2x3

---

x1 | x1x2

x1x3 | x1x2x3 | 

> все фигня переделать

## 2 проверить на полноту

$$f=\{x \oplus y; x \lor y; 1\}$$

|            | T_0 | T_1 | S   | M   | L   |
| ---------- | --- | --- | --- | --- | --- |
| x \oplus y | +   | -   | -   | -   | +   |
| x \lor y   | +   | +   | -   | +   | -   |
| 1          | -   | +   | -   | +   | +   |

| x   | y   | x \oplus y | x \lor y | 1   |
| --- | --- | ---------- | -------- | --- |
| 0   | 0   | 0          | 0        | 1   |
| 0   | 1   | 1          | 1        | 1   |
| 1   | 0   | 1          | 1        | 1   |
| 1   | 1   | 0          | 1        | 1   |

> ответ: система является полной

### b

f={x->y; ~x and y; 0}

| x   | y   | x -> y | ~x and y | 0   |
| --- | --- | ------ | -------- | --- |
| 0   | 0   | 1      | 0        | 0   |
| 0   | 1   | 1      | 1        | 0   |
| 1   | 0   | 0      | 0        | 0   |
| 1   | 1   | 1      | 0        | 0   |

notX or Y = (1 oplus x) or y

notX and Y = (1 oplus x) and y
notX and Y = (y oplus xy)

|          | T_0 | T_1 | S   | M   | L   |
| -------- | --- | --- | --- | --- | --- |
| x -> y   | -   | +   | -   | -   | ?   |
| ~x and y | +   | -   | -   | -   | -   |
| 0        | +   | -   | -   | +   | +   |

макласки квайн и карно,

бонусно коэффицентами

> будут домашку проверять
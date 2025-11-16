## найти полином зажигалкина

1b) f = (01100001)

> ЭТО ДОМАШКА

| x_1 | x_2 | x_3 | f   |
| --- | --- | --- | --- |
| 0   | 0   | 0   | 0   |
| 0   | 0   | 1   | 1   |
| 0   | 1   | 0   | 1   |
| 0   | 1   | 1   | 0   |
| 1   | 0   | 0   | 0   |
| 1   | 0   | 1   | 0   |
| 1   | 1   | 0   | 0   |
| 1   | 1   | 1   | 1   |

### система уравнений

```math
P(x;y;z) = a_0
\oplus a_1 x_1
\oplus a_2 x_2
\oplus a_3 x_3
\oplus a_{12} x_1 x_2
\oplus a_{13} x_1 x_3
\oplus a_{23} x_2 x_3
\oplus a_{123} x_1 x_2 x_3
```
<!-- 
```math
P(x_1;x_2;x_3) = a_0
\oplus a_1 \cdot x_1
\oplus a_2 \cdot x_2
\oplus a_3 \cdot x_3
\oplus a_{12} \cdot x_1 \cdot x_2
\oplus a_{13} \cdot x_1 \cdot x_3
\oplus a_{23} \cdot x_2 \cdot x_3
\oplus a_{123} \cdot x_1 \cdot x_2 \cdot x_3
```
-->

---

```math
P(0;0;0) = a_0
\oplus a_1 \cdot 0
\oplus a_2 \cdot 0
\oplus a_3 \cdot 0
\oplus a_{12} \cdot 0 \cdot 0
\oplus a_{13} \cdot 0 \cdot 0
\oplus a_{23} \cdot 0 \cdot 0
\oplus a_{123} \cdot 0 \cdot 0 \cdot 0
```

```math
P(0;0;1) = a_0
\oplus a_1 \cdot 0
\oplus a_2 \cdot 0
\oplus a_3 \cdot 1
\oplus a_{12} \cdot 0 \cdot 0
\oplus a_{13} \cdot 0 \cdot 1
\oplus a_{23} \cdot 0 \cdot 1
\oplus a_{123} \cdot 0 \cdot 0 \cdot 1
```

```math
P(0;1;0) = a_0
\oplus a_1 \cdot 0
\oplus a_2 \cdot 1
\oplus a_3 \cdot 0
\oplus a_{12} \cdot 0 \cdot 1
\oplus a_{13} \cdot 0 \cdot 0
\oplus a_{23} \cdot 1 \cdot 0
\oplus a_{123} \cdot 0 \cdot 1 \cdot 0
```

```math
P(0;1;1) = a_0
\oplus a_1 \cdot 0
\oplus a_2 \cdot 1
\oplus a_3 \cdot 1
\oplus a_{12} \cdot 0 \cdot 1
\oplus a_{13} \cdot 0 \cdot 1
\oplus a_{23} \cdot 1 \cdot 1
\oplus a_{123} \cdot 0 \cdot 1 \cdot 1
```

```math
P(1;0;0) = a_0
\oplus a_1 \cdot 1
\oplus a_2 \cdot 0
\oplus a_3 \cdot 0
\oplus a_{12} \cdot 1 \cdot 0
\oplus a_{13} \cdot 1 \cdot 0
\oplus a_{23} \cdot 0 \cdot 0
\oplus a_{123} \cdot 1 \cdot 0 \cdot 0
```

```math
P(1;0;1) = a_0
\oplus a_1 \cdot 1
\oplus a_2 \cdot 0
\oplus a_3 \cdot 1
\oplus a_{12} \cdot 1 \cdot 0
\oplus a_{13} \cdot 1 \cdot 1
\oplus a_{23} \cdot 0 \cdot 1
\oplus a_{123} \cdot 1 \cdot 0 \cdot 1
```

```math
P(1;1;0) = a_0
\oplus a_1 \cdot 1
\oplus a_2 \cdot 1
\oplus a_3 \cdot 0
\oplus a_{12} \cdot 1 \cdot 1
\oplus a_{13} \cdot 1 \cdot 0
\oplus a_{23} \cdot 1 \cdot 0
\oplus a_{123} \cdot 1 \cdot 1 \cdot 0
```

```math
P(1;1;1) = a_0
\oplus a_1 \cdot 1
\oplus a_2 \cdot 1
\oplus a_3 \cdot 1
\oplus a_{12} \cdot 1 \cdot 1
\oplus a_{13} \cdot 1 \cdot 1
\oplus a_{23} \cdot 1 \cdot 1
\oplus a_{123} \cdot 1 \cdot 1 \cdot 1
```

---

```math
P(0;0;0) = a_0
% \oplus a_1 \cdot 0
% \oplus a_2 \cdot 0
% \oplus a_3 \cdot 0
% \oplus a_{12} \cdot 0 \cdot 0
% \oplus a_{13} \cdot 0 \cdot 0
% \oplus a_{23} \cdot 0 \cdot 0
% \oplus a_{123} \cdot 0 \cdot 0 \cdot 0
= 0
```

```math
P(0;0;1) = a_0
% \oplus a_1 \cdot 0
% \oplus a_2 \cdot 0
\oplus a_3 % \cdot 1
% \oplus a_{12} \cdot 0 \cdot 0
% \oplus a_{13} \cdot 0 \cdot 1
% \oplus a_{23} \cdot 0 \cdot 1
% \oplus a_{123} \cdot 0 \cdot 0 \cdot 1
= a_3 = 1
```

```math
P(0;1;0) = a_0
% \oplus a_1 \cdot 0
\oplus a_2 % \cdot 1
% \oplus a_3 \cdot 0
% \oplus a_{12} \cdot 0 \cdot 1
% \oplus a_{13} \cdot 0 \cdot 0
% \oplus a_{23} \cdot 1 \cdot 0
% \oplus a_{123} \cdot 0 \cdot 1 \cdot 0
= a_2 = 1
```

```math
P(0;1;1) = a_0
% \oplus a_1 \cdot 0
\oplus a_2 % \cdot 1
\oplus a_3 % \cdot 1
% \oplus a_{12} \cdot 0 % \cdot 1
% \oplus a_{13} \cdot 0 % \cdot 1
\oplus a_{23} % \cdot 1 \cdot 1
% \oplus a_{123} \cdot 0 \cdot 1 \cdot 1
= 0 \oplus 1 \oplus 1 \oplus a_{23} = 0
```

```math
P(1;0;0) = a_0
\oplus a_1 %\cdot 1
% \oplus a_2 \cdot 0
% \oplus a_3 \cdot 0
% \oplus a_{12} \cdot 1 \cdot 0
% \oplus a_{13} \cdot 1 \cdot 0
% \oplus a_{23} \cdot 0 \cdot 0
% \oplus a_{123} \cdot 1 \cdot 0 \cdot 0
= a_1 = 0
```

```math
P(1;0;1) = a_0
\oplus a_1 % \cdot 1
% \oplus a_2 \cdot 0
\oplus a_3 % \cdot 1
% \oplus a_{12} % \cdot 1 \cdot 0
\oplus a_{13} % \cdot 1 \cdot 1
% \oplus a_{23} \cdot 0 \cdot 1
% \oplus a_{123} \cdot 1 \cdot 0 \cdot 1
= 0 \oplus 1 \oplus a_{13} = 0
```

$$a_{13} = 1$$

```math
P(1;1;0) = a_0
\oplus a_1 % \cdot 1
\oplus a_2 % \cdot 1
% \oplus a_3 \cdot 0
\oplus a_{12} % \cdot 1 \cdot 1
% \oplus a_{13} \cdot 1 \cdot 0
% \oplus a_{23} \cdot 1 \cdot 0
% \oplus a_{123} \cdot 1 \cdot 1 \cdot 0
= 1 \oplus a_{12} = 0
```

$$a_{12} = 1$$

```math
P(1;1;1) = a_0
\oplus a_1 % \cdot 1
\oplus a_2 % \cdot 1
\oplus a_3 % \cdot 1
\oplus a_{12} % \cdot 1 % \cdot 1
\oplus a_{13} % \cdot 1 % \cdot 1
\oplus a_{23} % \cdot 1 % \cdot 1
\oplus a_{123} % \cdot 1 \cdot 1 \cdot 1
```

```math
P(1;1;1) = 0
\oplus 0
\oplus 1
\oplus 1
\oplus 1
\oplus 1
\oplus 0
\oplus a_{123}
= a_{123} = 1
```

---

```math
P(x;y;z) = 0
\oplus 0 x_1
\oplus 1 x_2
\oplus 1 x_3
\oplus 1 x_1 x_2
\oplus 1 x_1 x_3
\oplus 0 x_2 x_3
\oplus 1 x_1 x_2 x_3
```

#### ответ

```math
P(x;y;z) =
% \oplus 0 x_1
x_2
\oplus x_3
\oplus x_1 x_2
\oplus x_1 x_3
% \oplus 0 x_2 x_3
\oplus x_1 x_2 x_3
```

### треугольник паскаля

f = (01100001)

| x_1 | x_2 | x_3 |                 |             |
| --- | --- | --- | :-------------: | ----------- |
| 0   | 0   | 0   | 0 1 1 0 0 0 0 1 |             |
| 0   | 0   | 1   |  1 0 1 0 0 0 1  | x_3         |
| 0   | 1   | 0   |   1 1 1 0 0 1   | x_2         |
| 0   | 1   | 1   |    0 0 1 0 1    |             |
| 1   | 0   | 0   |     0 1 1 1     |             |
| 1   | 0   | 1   |      1 0 0      | x_1 x_3     |
| 1   | 1   | 0   |       1 0       | x_1 x_2     |
| 1   | 1   | 1   |        1        | x_1 x_2 x_3 |

#### ответ

$$x_2 \oplus x_3 \oplus x_1 x_2 \oplus x_1 x_3 \oplus x_1 x_2 x_3$$

### через сднф

| x_1 | x_2 | x_3 | f   |
| --- | --- | --- | --- |
| 0   | 0   | 0   | 0   |
| 0   | 0   | 1   | 1   |
| 0   | 1   | 0   | 1   |
| 0   | 1   | 1   | 0   |
| 1   | 0   | 0   | 0   |
| 1   | 0   | 1   | 0   |
| 1   | 1   | 0   | 0   |
| 1   | 1   | 1   | 1   |

notXnotYZ or notXYnotZ or XYZ

|     | 00  | 01  | 11  | 10  |
| --- | --- | --- | --- | --- |
| 0   |     | 1   |     | 1   |
| 1   |     |     | 1   |     |

это мднф!

notXnotYZ or notXYnotZ or XYZ

1 xor ((1 xor notXnotYZ) and (1 xor notXYnotZ) and (1 xor XYZ))

1 xor (((1 xor notXnotYZ) xor notXYnotZ(1 xor notXnotYZ)) and (1 xor XYZ))

1 xor ((1 xor notXnotYZ xor notXYnotZ(1 xor notXnotYZ)) and (1 xor XYZ))

1 xor ((1 xor notXnotYZ xor (notXYnotZ xor notXnotYZnotXYnotZ)) and (1 xor XYZ))

1 xor ((1 xor notXnotYZ xor (notXYnotZ xor notXnotYZYnotZ)) and (1 xor XYZ))

1 xor ((1 xor notXnotYZ xor (notXYnotZ xor 0)) and (1 xor XYZ))

1 xor ((1 xor notXnotYZ xor notXYnotZ) and (1 xor XYZ))

1 xor (((1 xor notXnotYZ xor notXYnotZ) xor XYZ(1 xor notXnotYZ xor notXYnotZ)))

1 xor 1 xor notXnotYZ xor notXYnotZ xor XYZ(1 xor notXnotYZ xor notXYnotZ)

notXnotYZ xor notXYnotZ xor XYZ(1 xor notXnotYZ xor notXYnotZ)

notXnotYZ xor notXYnotZ xor (XYZ xor notXnotYZXYZ xor notXYnotZXYZ)

notXnotYZ xor notXYnotZ xor (XYZ)

(1 xor x)(1 xor y)z xor y(1 xor x)(1 xor z) xor xyz

(1 xor x)(z xor yz) xor (y xor xy)(1 xor z) xor xyz

((z xor yz) xor x(z xor yz)) xor ((y xor xy) xor z(y xor xy)) xor xyz

z xor yz xor x(z xor yz) xor y xor xy xor z(y xor xy) xor xyz

z xor yz xor (xz xor xyz) xor y xor xy xor (yz xor xyz) xor xyz

z xor yz xor xz xor xyz xor y xor xy xor yz xor xyz xor xyz

yz (2):

z xor xz xor xyz xor y xor xy xor xyz xor xyz

xyz (3):

z xor xz xor y xor xy xor xyz

$$x_2 \oplus x_3 \oplus x_1 x_2 \oplus x_1 x_3 \oplus x_1 x_2 x_3$$

---

1a) f = (01101011)

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

### треугольник паскаля

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

| x   | y   | x -> y | notX and Y | 0   |
| --- | --- | ------ | ---------- | --- |
| 0   | 0   | 1      | 0          | 0   |
| 0   | 1   | 1      | 1          | 0   |
| 1   | 0   | 0      | 0          | 0   |
| 1   | 1   | 1      | 0          | 0   |

| notX | notY | not(notX -> notY) | not(X and notY) | not 0() |
| ---- | ---- | ----------------- | --------------- | ------- |
| 1    | 1    | 0                 | 1               | 1       |
| 1    | 0    | 1                 | 1               | 1       |
| 0    | 1    | 0                 | 0               | 1       |
| 0    | 0    | 0                 | 1               | 1       |

---

<!-- a xor (b and c) = notABC or Anot(BC)

a xor (b and c) = notABC or A and (notB or notC)

a xor (b and c) = notABC or AnotB or AnotC -->

A & (B xor C)

A & (notBC or BnotC)

AnotBC or ABnotC

---

AB xor AC = not(AB)&AC or ABnot(AC)

(notA or notB)&AC or AB(notA or notC)

notAAC or notBAC or notAAB or ABnotC

AnotBC or ABnotC

---

notX or Y = (1 (+) x) or y

| x   | y   | x -> y |          |     |
| --- | --- | ------ | :------: | --- |
| 0   | 0   | 1      | `1\|101` | 1   |
| 0   | 1   | 1      | `0\|11`  |     |
| 1   | 0   | 0      |  `1\|0`  | x   |
| 1   | 1   | 1      |  `1\|`   | xy  |

x -> y = 1 xor x xor xy

notX and Y = (1 oplus x) and y
notX and Y = (y oplus xy)

|          | T_0 | T_1 | S   | M   | L   |
| -------- | --- | --- | --- | --- | --- |
| x -> y   | -   | +   | -   | -   | -   |
| ~x and y | +   | -   | -   | -   | -   |
| 0        | +   | -   | -   | +   | +   |

- $T_0$ - сохраняет 0
  - т.е. $f(0;0) = 0$
- $T_1$ - сохраняет 1
  - т.е. $f(1;1) = 1$
- $S$ - самодвойственно
  - т.е. $f^*(x;y;z) = f(x;y;z)$
  - где $f^*(x;y;z) = \overline{f(\overline x; \overline y; \overline z)}$
- $M$ - монотонная
  - т.е. с "ростом" каждого аргумента фция не убывает
- $L$ - линейная
  - т.е. в полиноме (за)Жегалкина нету попарных конъюнкций
  - какой ужас!

> Вывод: эта система тоже полная

макласки квайн и карно,

бонусно коэффицентами

> будут домашку проверять
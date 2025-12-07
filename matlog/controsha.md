
68

последняя 8

предпоследняя 6

Вариант 3

---

<!-- $$S \lor O$$

$$S \rarr N$$

$$O \rarr W$$

$$\rArr N \lor W$$ -->

$$S \lor O, S \rarr N, O \rarr W \rightarrowtail N \lor W$$


4
===

$$M = \{ 1, 2, 3, ..., 20 \}$$

- $A(x)$: "x не делится на 5"
- $B(x)$: "x - четное число"
- $C(x)$: "x - простое число"
- $D(x)$: "x кратно 3"

a
---

$$C(x) \rarr A(x)$$

$$\overline {C(x)} \lor A(x)$$

"x - не простое число, либо оно не делится на 5"

$$\overline {C(x) \land \overline {A(x)}}$$

"x - не является простым числом, делящимся на 5"

в множестве M только 5 - одновременно и простое число и делящееся на 5

тогда множество истинности:

> $R = M \setminus \{5\}$

<!-- простые числа:
- 2
- 3
- 5
- 7
- 11
- 13
- 17
- 19

не простые числа:
- 1
- 4
- 6

- 8
- 9
- 10

- 12
- 14
- 15
- 16
- 18
- 20

делятся на 5:
- 5
- 10
- 15
- 20

не делятся:

- 1-4
- 6-9
- 11-14
- 16-19

----

объединение множеств:

- 1-4
- 6-9
- 10
- 11-14
- 15
- 16-19
- 20 -->

b
---

$$D(x) \rarr \overline C(x)$$

$$\overline D(x) \lor \overline C(x)$$

$$\overline {D(x) \land C(x)}$$

"x не является простым числом, кратным 3"

простое число, делящееся на 3 - это 3

тогда множество истинности:

> $R = M \setminus \{3\}$

с
---

$$(A(x) \land C(x)) \rarr \overline D(x)$$

"если x - простое число, не делящееся на 5, то оно не кратно 3"

$$\overline {A(x) \land C(x)} \lor \overline D(x)$$

$$\overline {A(x) \land C(x) \land D(x)}$$

"x не является простым числом, которое делится на 3, но не на 5"

простые числа, которые не делятся на 5:
- 2
- 3
<!-- - 5 -->
- 7
- 11
- 13
- 17
- 19

если оно еще и делится на 3, то это точно 3.

тогда множество истинности:

> $R = M \setminus \{3\}$

5
===

a
---

```math
\forall x (A(x) \rarr B(y)) \& \forall y (A(x) \rarr (B(y) \rarr C(z))) \rarr \exists z (A(x) \rarr C(z))
```

```math
\forall x (\overline A(x) \lor B(y)) \& \forall y (A(x) \rarr (\overline B(y) \lor C(z))) \rarr \exists z (\overline A(x) \lor C(z))
```

```math
\forall x (\overline A(x) \lor B(y)) \& \forall y (\overline A(x) \lor \overline B(y) \lor C(z)) \rarr \exists z (\overline A(x) \lor C(z))
```

```math
\overline {\forall x (\overline A(x) \lor B(y)) \&\forall y (\overline A(x) \lor \overline B(y) \lor C(z))} \lor \exists z (\overline A(x) \lor C(z))
```

```math
\overline {\forall x (\overline A(x) \lor B(y))} \lor \overline{\forall y (\overline A(x) \lor \overline B(y) \lor C(z))} \lor \exists z (\overline A(x) \lor C(z))
```

```math
\exist x \overline {(\overline A(x) \lor B(y))}
\lor \exist y \overline{(\overline A(x) \lor \overline B(y) \lor C(z))}
\lor \exists z (\overline A(x) \lor C(z))
```

```math
\exist x (A(x) \land \overline B(y))
\lor \exist y (\overline{\overline A(x) \lor \overline B(y)} \land \overline C(z))
\lor \exists z (\overline A(x) \lor C(z))
```

```math
\exist x (A(x) \land \overline B(y))
\lor \exist y (A(x) \land B(y) \land \overline C(z))
\lor \exists z (\overline A(x) \lor C(z))
```

```math
\exist x A(x) \land \overline B(y)
\lor \exist y B(y) \land A(x) \land \overline C(z)
\lor \overline A(x) \lor \exists z C(z)
```

b
---

$$\forall x(\lnot A(x) \rarr \exists x (\lnot C(x) )) \rarr \forall x ((C(x) \rarr A(x))$$

$$\forall x(\overline {\lnot A(x)} \lor \exists x (\lnot C(x) )) \rarr \forall x (\overline C(x) \lor A(x))$$

$$\overline {\forall x (A(x) \lor \exists x (\lnot C(x) ))} \lor \forall x (\overline C(x) \lor A(x))$$

$$\overline {\forall x A(x)} \land \overline{\exists x (\lnot C(x) )} \lor \forall x (\overline C(x) \lor A(x))$$

$$\exists x \overline {A(x)} \land \forall x \overline{(\lnot C(x) )} \lor \forall x (\overline C(x) \lor A(x))$$

$$\exists x \overline {A(x)} \land \forall x C(x) \lor \forall x (\overline C(x) \lor A(x))$$

c
---

$$(\exists x (\lnot A(x)) \rarr \forall x (\lnot B(x))) \rarr (\lnot B(x) \lor A(x))$$

$$(\overline{\forall x A(x)} \rarr \overline{\exist x B(x)}) \rarr (\lnot B(x) \lor A(x))$$

$$(\forall x A(x) \lor \overline{\exist x B(x)}) \rarr (\lnot B(x) \lor A(x))$$

$$\overline {\forall x A(x) \lor \overline{\exist x B(x)}} \lor (\lnot B(x) \lor A(x))$$

$$\overline {\forall x A(x)} \land {\exist x B(x)} \lor \overline B(x) \lor A(x)$$

$$\exists x \overline {A(x)} \land {\exist x B(x)} \lor \overline B(x) \lor A(x)$$

6
===

a
---

$$(\exists x (\lnot A(x)) \rarr \forall x (\lnot B(x))) \rarr (\lnot B(x) \lor A(x))$$

$$(\overline{\exists x (\lnot A(x))} \lor \forall x (\lnot B(x))) \rarr (\lnot B(x) \lor A(x))$$

$$(\forall x A(x) \lor \forall x (\lnot B(x))) \rarr (\lnot B(x) \lor A(x))$$

$$\overline{(\forall x A(x) \lor \forall x (\lnot B(x)))} \lor (\lnot B(x) \lor A(x))$$

$$\overline{\forall x A(x)} \land \overline{\forall x (\lnot B(x))} \lor (\lnot B(x) \lor A(x))$$

$$\exist x \overline{A(x)} \land \exist x B(x) \lor \overline B(x) \lor A(x)$$

$$\exist y \overline{A(y)} \land \exist z B(z) \lor \overline B(x) \lor A(x)$$

$$\exist y (\overline{A(y)} \land \exist z B(z)) \lor \overline B(x) \lor A(x)$$

$$\exist y (\exist z B(z) \land \overline{A(y)}) \lor \overline B(x) \lor A(x)$$

$$\exist y (\exist z (B(z) \land \overline{A(y)})) \lor \overline B(x) \lor A(x)$$

$$\exist y \exist z (B(z) \land \overline{A(y)} \lor \overline B(x) \lor A(x))$$

b
---

$$(\forall x (A(x) \rarr \forall y (B(y) \rarr C(z)))) \, \& \, (\lnot \forall y (D(x;y) \rarr F(z)))$$

$$(\forall x (A(x) \rarr \forall y (\overline B(y) \lor C(z)))) \, \& \, (\lnot \forall y (D(x;y) \rarr F(z)))$$

$$(\forall x (A(x) \rarr (\forall y \overline B(y) \lor C(z)))) \, \& \, (\lnot \forall y (D(x;y) \rarr F(z)))$$

$$(\forall x (\overline A(x) \lor (\forall y \overline B(y) \lor C(z)))) \, \& \, (\exist y \lnot (D(x;y) \rarr F(z)))$$

$$(\forall x \overline A(x) \lor (\forall y \overline B(y) \lor C(z))) \, \& \, (\exist y \lnot (\overline D(x;y) \lor F(z)))$$

$$(\forall x \overline A(x) \lor (\forall y \overline B(y) \lor C(z))) \, \& \, (\exist y (D(x;y) \land \overline F(z)))$$

$$(\forall x \overline A(x) \lor \forall y \overline B(y) \lor C(z)) \land \exist y D(x;y) \land \overline F(z)$$

$$(\forall u \overline A(u) \lor \forall t \overline B(t) \lor C(z)) \land \exist y D(x;y) \land \overline F(z)$$


$$\exists y (D(x;y) \land \overline F(z) \land (\forall u \overline A(u) \lor \forall t \overline B(t) \lor C(z)))$$

$$\exists y (D(x;y) \land \overline F(z) \land (\forall u (\overline A(u) \lor \forall t \overline B(t) \lor C(z))))$$

$$\exists y (D(x;y) \land \overline F(z) \land (\forall u (\forall t \overline B(t) \lor \overline A(u) \lor C(z))))$$

$$\exists y (\forall u \forall t (D(x;y) \land \overline F(z) \land (\overline B(t) \lor \overline A(u) \lor C(z))))$$

$$\exists y \forall u \forall t (D(x;y) \land \overline F(z) \land (\overline B(t) \lor \overline A(u) \lor C(z)))$$

c
---

$$(\forall x (B(x) \rarr \exists y (A(y)))) \land \exists y (A(x) \rarr C(y)) \rarr \lnot C(y) \land B(x)$$

$$\overline {(\forall x (\overline B(x) \lor \exists y (A(y)))) \land \exists y (\overline A(x) \lor C(y))} \lor \lnot C(y) \land B(x)$$

$$\overline {(\forall x \overline B(x) \lor \exists y A(y)) \land (\exists y C(y) \lor \overline A(x)) } \lor \overline C(y) \land B(x)$$

$$\overline {(\forall x \overline B(x) \lor \exists y A(y))} \lor \overline{ (\exists y C(y) \lor \overline A(x)) } \lor \overline C(y) \land B(x)$$

$$\overline {\forall x \overline B(x)} \land \overline { \exists y A(y)} \lor \overline{ \exists y C(y)} \land A(x) \lor \overline C(y) \land B(x)$$

$$\exists x B(x) \land  \forall y \overline {A(y)} \lor \forall y \overline{C(y)} \land A(x) \lor \overline C(y) \land B(x)$$

$$\exists x \forall y (B(x) \land   \overline {A(y)}) \lor \forall y (\overline{C(y)} \land A(x)) \lor (\overline C(y) \land B(x))$$

$$\exists x \forall y (B(x) \land   \overline {A(y)}) \lor \forall t (\overline{C(t)} \land A(x)) \lor (\overline C(y) \land B(x))$$

$$\exists x \forall y (B(x) \land   \overline {A(y)}) \lor \forall t (\overline{C(t)} \land A(x) \lor (\overline C(y) \land B(x)))$$

$$\exists u \forall v \forall t (B(u) \land   \overline {A(v)} \lor (\overline{C(t)} \land A(x) \lor (\overline C(y) \land B(x))))$$

> i'm really sorry...

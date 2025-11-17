# 17.11.2025 г. Лекция 6. Логические исчисления

## План лекции

### 6.1. Исчисление высказываний (_ИВ_)
### 6.2. Критерий выводимости в ИВ
### 6.3. Непротиворечивость ИВ

---

для формальных языков и ИИ тоже

---

## 6.1. Исчисление высказываний (_ИВ_)

### Основные определения

ИВ - некоторое множество {L(язык ИВ); Ax(аксиомы ИВ); Reg(правила вывода ИВ)}

это благодаря происходит процесс

без правил вывода все это невозможно

L = {A(алфавит); V(слова); F(формулы)}

A - конечное множество

```math
A = \{A; B; ...; X; Y; Z; A1; ...; Z1; ...; An; ...; Zn\}
\cup \{\&; \lor; \lnot; (; )\}
```

все символы входного языка


V - счетное множество

> __словом__ в алфавите (над алфавите) называется последовательность
> состоящая из символов входного алфавита 

> формальная последовательность слов - это конечная последовательность _слов_
> и высказываний
>
> $$U_1; U_2; ...; U_n$$
>
> если она имеет следующий формат:
>
> ```math
> V_k =
> \begin{cases}
> v_i - \text{символ переменной}  \\
> v_i = (u_i \lor u_j); u_{i,j} - \text{подслова}; i, j < k  \\
> v_i = (u_i \& u_j); u_{i,j} - \text{подслова}; i, j < k  \\
> v_i = (\lnot u_i); u_i - \text{подслова}; i < k  \\
> v_i = (u_i \rightarrow u_j); u_{i,j} - \text{подслова}; i,j < k  \\
> %   \\
> \end{cases}
> ```

> F - формулой ИВ называется любое слово,
> входящее в формальную последовательность слов

#### Пример

$$(\lnot (\lnot (A2025 \rightarrow A))) = F$$

- $U_1 = A2025$
- $U_2 = A$
- $U_3 = A2025 \rightarrow A$
- $U_4 = \lnot (A2025 \rightarrow A)$
- $U_5 = \lnot (\lnot (A2025 \rightarrow A))$

> __Аксиома__ - специальное выделенное подмножество формулы,
> не требующее доказательств
>
> (аксиомы Клини)
>
> $$Ax \subseteq F$$

1) $(A \rightarrow (B \rightarrow A))$
2) $(A \rightarrow (B \rightarrow C)) \rightarrow ((A \rightarrow B) \rightarrow (A \rightarrow C))$
3) $((A \land B) \rightarrow A)$
3) $((A \land B) \rightarrow B)$
4) $((A \rightarrow B) \rightarrow ((A \rightarrow C) \rightarrow (A \rightarrow (B \land C))))$
5) $(A \rightarrow (A \lor B))$
5) $(B \rightarrow (A \lor B))$
6) $((A \rightarrow C) \rightarrow ((B \rightarrow C) \rightarrow ((A \lor B) \rightarrow C)))$
7) $(A \rightarrow (\overline{\overline A}))$
7) $(\overline{\overline A} \rightarrow A)$
8) $((A \rightarrow B) \rightarrow (\lnot B \rightarrow \lnot A))$

Reg (правила вывода ИВ) - правила преобразования одного слова в другое

a - символ переменной из алфавита

$$a \in A$$

$\psi$ - произвольное слово в ИВ

Отображение:

$$S_\psi ^a : V \rightarrow V$$

на месте каждого вхождения символа $a$ записывается слово $\psi$

#### Пример:

$$V = ABBAC$$

$$a = B$$

$$\psi = AB$$

$$S_\psi ^a : (ABBAC) \rightarrow (A\boxed{AB}\boxed{AB}AC)$$

---

#### Правило вывода

> modus ponens (m.p.)

$$V^2 \rightarrow V$$

$$(\varphi, (\varphi \rightarrow x)) = x$$

$$\frac{\varphi, (\varphi \rightarrow x)}{x}$$

#### Формальный вывод (простейшая модель доказательства теорем)

Последовательность формлул ИВ называется __формальным выводом__,
если каждая формула этой последовательности имеет следующий вид:

```math
U_k =
\begin{cases}
\in Ax \text{(аксиома)}  \\
S _\psi ^a(u_{ij}); & i,j < k  \\
m.p. (u_i; u_j); & i,j < k  \\
%   \\
\end{cases}
```

__выводимой формулой__ (__теоремой__) ИВ называется любая формула,
входящая в какой-либо формальный вывод

$$\rightarrowtail \varphi$$

- знак выводимости

##### Пример

$$\rightarrowtail (A \rightarrow A)$$

1) $(A -> (B -> A)); Ax(1)$
2) $(A \rightarrow (B \rightarrow C)) \rightarrow ((A \rightarrow B) \rightarrow (A \rightarrow C)); Ax(2)$

$$\frac{\varphi, (\varphi \rightarrow x)}{x}$$

$$S ^C _A (2)$$

3) $(A \rightarrow (B \rightarrow \boxed{A})) \rightarrow ((A \rightarrow B) \rightarrow (A \rightarrow \boxed{A})); Ax(2)$

$$(A \rightarrow (B \rightarrow \boxed{A})) = \varphi$$

4) $((A \rightarrow B) \rightarrow (A \rightarrow \boxed{A})) = x$;  m.p. (1-3)

5) $((A \rightarrow \boxed{B -> A}) \rightarrow (A \rightarrow A))$; $S ^B _{B -> A}$ (4)

   $\varphi = (A \rightarrow \boxed{B -> A})$

   $x = (A \rightarrow A)$

6) A -> A чтд; m.p (1-5)

#### Правило одновременной подстановки

Замечание если $\rightarrowtail \varphi$, то $\rightarrowtail S ^a _\psi (\varphi)$

формальноая последовательность вывода:

$$\varphi; u_1; u_2; ...; u_n$$

$$u_{n+1} = S^a _\psi (\varphi)$$

если $\rightarrowtail \varphi$, то если  $\rightarrowtail \varphi -> \psi$,

то $\rightarrowtail \psi$

### Теорема 6.1

Если $\rightarrowtail \varphi$, то $\rightarrowtail S ^{a_1; a_2; ...; a_n} _{\psi _1; \psi _2; ...; \psi _n} (a_1; a_2; ...; a_n)$

### Формальный вывод из гипотез

Определение: $\psi _1; \psi _2; ...; \psi _n$ (формулы)

такая последовательность слов: $u_1; u_2; ...; u_N$

каждая из которых удовлетворяет условию

```math
U_k =
\begin{cases}
\rightarrowtail U_k (вывод из a)  \\
= \psi _i; i = \overline{1, n}  \\
m.p. (u_i; u_j), i, j < k  \\
%   \\
\end{cases}
```

вывод из гипотез существует если формулу фи можно включить в некоторый
формальный вывод из гипотез

$$\psi _1; \psi _2; ...; \psi _n \rightarrowtail \varphi$$

### Лемма 6.1.

$$\psi _1; \psi _2; ...; \psi _n \rightarrowtail \varphi$$

$$\psi _1; \psi _2; ...; \psi _n \rightarrowtail (\varphi -> \psi)$$


$$\rArr \psi _1; \psi _2; ...; \psi _n \rightarrowtail \psi$$

### Теорема 6.2. (дедукции)

если из $\psi _1; \psi _2; ...; \psi _n \rightarrowtail \psi$

то тогда можно двигать формулу за знак выводимости

$\psi _1; \psi _2; ...; \psi _{n-1} \rightarrowtail (\psi _n \rarr \psi)$

$\rightarrowtail (\psi _1 \rarr (\psi _2 \rarr (\psi _3 \rarr (\varphi))))$

$$(A \rarr (B \rarr C)); A; B \rightarrowtail C$$

тоесть доказать C из гипотез слева

#### I способ. Система формального вывода.

1) $A \rarr (B \rarr C)$
2) $A$
3) $B$

4) $B \rarr C$; m.p.(2; 1)
5) $C$; m.p. (3; 4)

#### II способ. Теорема дедукции

$$(A \rarr (B \rarr C)); A; B \rightarrowtail C =$$

$$(A \rarr (B \rarr C)); A \rightarrowtail (B \rarr C) =$$

$$(A \rarr (B \rarr C)) \rightarrowtail (A \rarr (B \rarr C)) =$$

$$\rightarrowtail (A \rarr (B \rarr C)) \rarr (A \rarr (B \rarr C)) =$$

#### III резулятивный

1) формула стоящая в правой части формального вывода переносится влево
   за знак выводимости с инверсией
2) все гипотезы записываются в виде операций and; or; not
3) знак and заменяется на запятую
4) строится множество дизъюнктов из полученных гипотез
5) доказывается непротиворечивость множества дизъюнкций

мн-во непротиворечиво
если резулятивный вывод по всем входящим переменным заканчивается 0

вывод существует, если непротиворечиво

$$(A \rarr (B \rarr C)); A; B \rightarrowtail C$$

$$(A \rarr (B \rarr C)); A; B \overline{C} \rightarrowtail$$

$$(A \rarr (B \rarr C)) = (\overline A \lor (\overline B \lor C))$$

$$(\overline A \lor (\overline B \lor C)); A; B \overline{C} \rightarrowtail$$

S = \{ \overline A \lor \overline B \lor C; A; B; \overline C \}

$$res_A \{\overline A \lor \overline B \lor C; A\} = \overline B \lor C$$

$$res_B \{\overline B \lor C; B\} = C$$

$$res_C \{\overline C; C\} = 0$$

непротиворечиво, значит выводимость существует

## 6.2. Критерий ИВ

$\rightarrowtail \varphi \lrArr \varphi = 1$

при любой интерпретации алфавита

### интерпретация

$(A \rarr (B \rarr A))$ - слово

$(A \rarr (B \rarr A)) \rightarrowtail (x_1 \rarr (x_2 \rarr x_1))$

x_1 - буква

(x_1 \rarr (x_2 \rarr x_1)) - фция

---

$$\rightarrowtail \{x_1; x_2; ...; x_n\}$$

проекция 1ой переменной на другую

## 6.3. Непротиворечивость ИВ.

Определение:

1) ИВ непротиворечиво, если $\rightarrowtail A; A \in алфавиту$
2) $\forall \varphi \in F \rightarrowtail \varphi \rArr$ ИВ непротиворечиво
3) $\exist \varphi \in F: \, \rightarrowtail \varphi$, то $\rightarrowtail \overline \varphi$

если не является противоречивым

### Теорема 6.3.

ИВ является непротиворечивым по отношению к любому из указанных определений

### Формальные исчисления

Алфавит - конечное или счетное множество символов, возможно разбитых на группы.

должен быть упорядоченным множеством

Слово - конечная упорядоченная последовательность символов алфавита,
в т.ч. пустое слово
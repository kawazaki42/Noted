> вариант 9

## задача 4

Является ли рассуждение логически правильным

- A - почтальон будет приносить газеты вовремя
- B - люди будут покупать газеты в киоске
- C - люди будут слушать радио
- D - тираж будет уменьшен

$$\overline A \rarr (B \lor C)$$

$$\overline B \rarr D$$

$$D \land \overline A \rarr \overline C$$

следовательно

$$B$$

---

$$\overline A \rarr (B \lor C), \overline B \rarr D, D \land \overline A \rarr \overline C \rightarrowtail B$$

<!-- $$(\overline A \rarr (B \lor C))(\overline B \rarr D)(D \land \overline A \rarr \overline C) \rightarrow B$$

$$(A \lor (B \lor C))(B \lor D)(\overline{D \land \overline A} \lor \overline C) \rightarrow B$$

$$(A \lor B \lor C)(B \lor D)(\overline{D \land \overline A} \lor \overline C) \rightarrow B$$

$$(B(A \lor B \lor C) \lor D(A \lor B \lor C))(\overline D \lor A \lor \overline C) \rightarrow B$$

<!-- $$(AB \lor BB \lor BC) \lor (AD \lor BD \lor CD))(\overline D \lor A \lor \overline C) \rightarrow B$$ ->

$$(A \lor B \lor C)(B \lor D)(\overline D \lor A \lor \overline C) \rightarrow B$$

$$(A \lor B \lor C)(B(\overline D \lor A \lor \overline C) \lor D(\overline D \lor A \lor \overline C)) \rightarrow B$$

$$(A \lor B \lor C)((B \overline D \lor AB \lor B \overline C) \lor (\cancel{D \overline D} \lor AD \lor \overline CD)) \rightarrow B$$

$$(A \lor B \lor C)(B \overline D \lor AB \lor B \overline C \lor AD \lor \overline CD) \rightarrow B$$

$$(A(B \overline D \lor AB \lor B \overline C \lor AD \lor \overline CD) \lor B(B \overline D \lor AB \lor B \overline C \lor AD \lor \overline CD) \lor C(B \overline D \lor AB \lor B \overline C \lor AD \lor \overline CD)) \rightarrow B$$

$$((AB \overline D \lor AAB \lor AB \overline C \lor AAD \lor A\overline CD) \lor (BB \overline D \lor ABB \lor BB \overline C \lor ABD \lor B\overline CD) \lor (BC \overline D \lor ABC \lor \cancel{BC \overline C} \lor ACD \lor \cancel{\overline CCD})) \rightarrow B$$

$$(AB\overline D \lor AB \lor AB\overline C \lor AD \lor A\overline CD \lor B\overline D \lor AB \lor B\overline C \lor ABD \lor B\overline CD \lor BC\overline D \lor ABC \lor \cancel{BC\overline C} \lor ACD \lor \cancel{\overline CCD}) \rightarrow B$$

$$(AB\overline D \lor AB \lor AB\overline C \lor AD \lor A\overline CD \lor B\overline D \lor AB \lor B\overline C \lor ABD \lor B\overline CD \lor BC\overline D \lor ABC \lor ACD) \rightarrow B$$

$$(AB \lor AD \lor B\overline D \lor B\overline C \lor BC\overline D \lor ACD) \rightarrow B$$

$$(AB \lor AD \lor B\overline D \lor B\overline C) \rightarrow B$$

$$B(A \lor \overline D \lor \overline C) \lor AD \rightarrow B$$

<!-- $$\overline{AB \lor AD \lor B\overline D \lor B\overline C} \lor B$$ ->

$$\overline{B(A \lor \overline D \lor \overline C) \lor AD} \lor B$$

$$\overline{B(A \lor \overline D \lor \overline C)} \land \overline{AD} \lor B$$

$$(\overline B \lor \overline{A \lor \overline D \lor \overline C}) \land \overline A \lor \overline D \lor B$$

$$(\overline B \lor \overline ADC) \land \overline A \lor \overline D \lor B$$

$$(\overline A \, \overline B \lor \overline ADC) \lor \overline D \lor B$$ -->

резулятивный вывод

$$\overline A \rarr (B \lor C), \overline B \rarr D, D \land \overline A \rarr \overline C, \overline B \rightarrowtail$$

$$A \lor (B \lor C), B \lor D, \overline{D \land \overline A} \lor \overline C, \overline B \rightarrowtail$$

$$A \lor B \lor C, B \lor D, \overline D \lor A \lor \overline C, \overline B \rightarrowtail$$

$$S = \{ A \lor B \lor C, B \lor D, \overline D \lor A \lor \overline C, \overline B \}$$

<!-- $$res _A \{ A \lor B \lor C, \overline D \lor A \lor \overline C \}$$ -->

$$res_B \{ A \lor B \lor C, B \lor D, \overline B \}$$

$$res_B \{ A \lor B \lor C, \overline B D \}$$

$$res_B \{ \overline B D A \lor \overline B D B \lor \overline B D C \}$$

$$res_B \{ \overline B D A \lor \overline B D C \} = DA \lor DC = D(A \lor C)$$

$$res _D \{ D(A \lor C), \overline D \lor A \lor \overline C\}$$

$$res _D \{ A D(A \lor C) \lor \overline C D(A \lor C)\}$$

$$res _D \{ A D \lor CAD \lor \overline C D A \lor \overline C D C\}$$

$$res _D \{ A D \lor CAD \lor \overline C D A \} = A$$

> противоречие не доказано, следовательно формула не выводима

<!-- $$res _D \{ B \lor D, \overline D \lor A \lor \overline C \}$$

$$res _D \{ (B \lor D) \overline D \lor A (B \lor D) \lor \overline C (B \lor D) \}$$

```math
res _D \{ B \overline D \lor A B \lor AD \lor \overline C B \lor \overline C D \}
= A B \lor A \lor \overline C B \lor \overline C \lor B
= A \lor \overline C \lor B
```

$$res _B \{ \}$$ -->

### 2 способ: теорема дедукции и таблица истинности

$$(\overline A \rarr (B \lor C))(\overline B \rarr D)(D \land \overline A \rarr \overline C) \rightarrow B$$

пусть $S = (\overline A \rarr (B \lor C))(\overline B \rarr D)(D \land \overline A \rarr \overline C)$


|  A  |  B  |  C  |  D  | $\overline A \rarr (B \lor C)$ | $\overline B \rarr D$ | $D \land \overline A \rarr \overline C$  | $S \rarr B$  |
| :-: | :-: | :-: | :-: | :----------------------------: | :-------------------: | :-: | :-: |
|  0  |  0  |  0  |  0  |               0                |           0           |  1  |  1  |
|  0  |  0  |  0  |  1  |               0                |           1           |  1  |  1  |
|  0  |  0  |  1  |  0  |               1                |           0           |  1  |  1  |
|  0  |  0  |  1  |  1  |               1                |           1           |  0  |  1  |
|  0  |  1  |  0  |  0  |               1                |           1           |  1  |  1  |
|  0  |  1  |  0  |  1  |               1                |           1           |  1  |  1  |
|  0  |  1  |  1  |  0  |               1                |           1           |  1  |  1  |
|  0  |  1  |  1  |  1  |               1                |           1           |  0  |  1  |
|  1  |  0  |  0  |  0  |               1                |           0           |  1  |  1  |
|  1  |  0  |  0  |  1  |               1                |           1           |  1  |  0  |
|  1  |  0  |  1  |  0  |               1                |           0           |  1  |  1  |
|  1  |  0  |  1  |  1  |               1                |           1           |  1  |  0  |
|  1  |  1  |  0  |  0  |               1                |           1           |  1  |  1  |
|  1  |  1  |  0  |  1  |               1                |           1           |  1  |  1  |
|  1  |  1  |  1  |  0  |               1                |           1           |  1  |  1  |
|  1  |  1  |  1  |  1  |               1                |           1           |  1  |  1  |

|  A  |  B  |  C  |  D  | $\overline A \rarr (B \lor C)$ | $\overline B \rarr D$ | $D \land \overline A \rarr \overline C$  | $S \rarr B$  |
| :-: | :-: | :-: | :-: | :----------------------------: | :-------------------: | :-: | :-: |
|  0  |  1  |  0  |  0  |               1                |           1           |  1  |  1  |
|  0  |  1  |  0  |  1  |               1                |           1           |  1  |  1  |
|  0  |  1  |  1  |  0  |               1                |           1           |  1  |  1  |
|  1  |  0  |  0  |  1  |               1                |           1           |  1  |  0  |
|  1  |  0  |  1  |  1  |               1                |           1           |  1  |  0  |
|  1  |  1  |  0  |  0  |               1                |           1           |  1  |  1  |
|  1  |  1  |  0  |  1  |               1                |           1           |  1  |  1  |
|  1  |  1  |  1  |  0  |               1                |           1           |  1  |  1  |
|  1  |  1  |  1  |  1  |               1                |           1           |  1  |  1  |

> невозможно доказать тождественность импликации $S \rarr B$,
> следовательно формула не выводима

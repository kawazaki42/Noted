- $\rightarrowtail \varphi$ - теорема
- $\Gamma \rightarrowtail$ - множество противоречий
- $T$ о полноте: $\rightarrowtail \varphi \lrArr \varphi = 1$
- $T$ дедукции:
  - $\Gamma, \varphi \rightarrowtail \psi \rArr \Gamma \rightarrowtail \varphi \rarr \psi$
  - $\Gamma, \varphi \rightarrowtail \psi \rArr \Gamma, \varphi, \psi \rightarrowtail$
- $S \rightarrowtail$ - множество дизъюнктов
  - $A \land B \rightarrowtail \varphi = A, B \rightarrowtail \varphi$

# №1 Схема аксиом

- A1) $f \rarr (g \rarr f)$
- A2) $((f \rarr (g \rarr h)) \rarr ((f \rarr g) \rarr (f \rarr h)))$
- A3) ($(\overline g \rarr \overline f) \rarr ((\overline g \rarr f) \rarr g)$)

доказать то что есть вот такая вот выводимость

$$f \rarr g, g \rarr h \rightarrowtail f \rarr h$$

## I способ

1) $S^g_f(1); S^f_{g \rarr h}(1): \ (g \rarr h) \rarr (f \rarr (g \rarr h))$ - аксиома
2) $\rightarrowtail g \rarr h$ - по условию
3) пусть $\varphi = (g \rarr h)$; $x = (f \rarr (g \rarr h))$

   $m.p.(\varphi; \varphi \rarr x) = x: (f \rarr (g \rarr h))$ - выводима

4) $m.p.(A2,3) \rightarrowtail (f \rarr g) \rarr (f \rarr h)$

5) $m.p.(5;4) \rightarrowtail f \rarr h$

## II способ. резулятивный вывод

$$f \rarr h, g \rarr h \rightarrowtail f \rarr h$$

$$f \rarr h, g \rarr h, \overline{f \rarr h}\rightarrowtail$$

$$f \rarr h, g \rarr h, \overline{\overline f \lor h}\rightarrowtail$$

$$f \rarr h, g \rarr h, f \land \overline h \rightarrowtail$$

$$f \rarr h, g \rarr h, f, \overline h \rightarrowtail$$

$$S = \{\overline f \lor g, \overline g \lor h, f, \overline h\}$$

$$res_f\{ \overline f \lor g, f \} = g$$

$$res_f\{ g, \overline{g} \lor h \} = h$$

$$res_f\{ h, \overline{h} \} = 0$$

вывод: т.к. S непротиворечиво $\rArr \rightarrowtail f \rarr h$

## III способ: Теорема о полноте

$$((f \rarr g) \land (g \rarr h)) \rarr (f \rarr h)$$

$$\overline{((\overline f \lor g) \land (\overline g \lor h))} \lor (\overline f \lor h)$$

$$\overline{\overline f \lor g} \lor \overline{\overline g \lor h} \lor \overline f \lor h$$

$$f \overline g \lor g \overline h \lor \overline f \lor h$$

$$\overline g \lor g \overline h \lor h$$

$$\overline h \lor h$$

$$1$$

$$\text{кайф}$$

> вариант 9

---

являести

известно что петр и иван братья

или они однокурсники.

если петр и иван братья то сергей и иван не братья

если петри и иван однокурсники то иван и михаил тоже однокурсники

следовательно или сергей и иван братья или иван и михаил однокурсники

A: петр и иван братья

B: петр и иван однокурсники

C: сергей и иван братья

D: иван и михаил однокурсники

$A \lor B, A \rarr \overline C, B \rarr D \rightarrowtail C \lor D$

- резулятивный
- теорема о полноте
- можно одним??

$A \lor B, \overline A \lor \overline C, \overline B \lor D, \overline C, \overline D\rightarrowtail$


$$res_A \{ A \lor B, \overline A \lor \overline C \} = B \lor \overline C$$

$$res_B \{ A \lor B, B \lor \overline C \}$$

- тут уже не пойдут потому что B обе без инверсии
> вариант 9

## задача 4

Является ли рассуждение логически правильным

A - почтальон будет приносить газеты вовремя

B - люди будут покупать газеты в киоске

C - люди будут слушать радио

$$\overline A \rarr (B \lor C)$$

D - тираж будет уменьшен

$$\overline B \rarr D$$

$$D \land \overline A \rarr \overline C$$

следовательно

$$B$$

---

$$\overline A \rarr (B \lor C), \overline B \rarr D, D \land \overline A \rarr \overline C \rightarrowtail B$$

$$(\overline A \rarr (B \lor C))(\overline B \rarr D)(D \land \overline A \rarr \overline C) \rightarrow B$$

$$(A \lor (B \lor C))(B \lor D)(\overline{D \land \overline A} \lor \overline C) \rightarrow B$$

$$(A \lor B \lor C)(B \lor D)(\overline{D \land \overline A} \lor \overline C) \rightarrow B$$

$$(B(A \lor B \lor C) \lor D(A \lor B \lor C))(\overline D \lor A \lor \overline C) \rightarrow B$$

$$(AB \lor BB \lor BC) \lor (AD \lor BD \lor CD))(\overline D \lor A \lor \overline C) \rightarrow B$$

$$(A \lor B \lor C)(B \lor D)(\overline D \lor A \lor \overline C) \rightarrow B$$

$$(A \lor B \lor C)(B(\overline D \lor A \lor \overline C) \lor D(\overline D \lor A \lor \overline C)) \rightarrow B$$

$$(A \lor B \lor C)((B \overline D \lor AB \lor B \overline C) \lor (D \overline D \lor AD \lor \overline CD)) \rightarrow B$$

$$(A \lor B \lor C)(B \overline D \lor AB \lor B \overline C \lor AD \lor \overline CD) \rightarrow B$$

$$(A(B \overline D \lor AB \lor B \overline C \lor AD \lor \overline CD) \lor B(B \overline D \lor AB \lor B \overline C \lor AD \lor \overline CD) \lor C(B \overline D \lor AB \lor B \overline C \lor AD \lor \overline CD)) \rightarrow B$$

$$((AB \overline D \lor AAB \lor AB \overline C \lor AAD \lor A\overline CD) \lor (BB \overline D \lor ABB \lor BB \overline C \lor ABD \lor B\overline CD) \lor (BC \overline D \lor ABC \lor BC \overline C \lor ACD \lor \overline CCD)) \rightarrow B$$

$$(AB\overline D \lor AB \lor AB\overline C \lor AD \lor A\overline CD \lor B\overline D \lor AB \lor B\overline C \lor ABD \lor B\overline CD \lor BC\overline D \lor ABC \lor BC\overline C \lor ACD \lor \overline CCD) \rightarrow B$$

$$(AB\overline D \lor AB \lor AB\overline C \lor AD \lor A\overline CD \lor B\overline D \lor AB \lor B\overline C \lor ABD \lor B\overline CD \lor BC\overline D \lor ABC \lor ACD) \rightarrow B$$

$$(AB \lor AD \lor B\overline D \lor B\overline C \lor BC\overline D \lor ACD) \rightarrow B$$

$$(AB \lor AD \lor B\overline D \lor B\overline C) \rightarrow B$$

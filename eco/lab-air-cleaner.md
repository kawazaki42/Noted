> Вариант __5__

> Цель работы:
> - ознакомиться с принципом работы "Циклона" - аппарата сухой очитски от пыли
> <!-- - выбрать и рассчитать  _циклон_ для заданного источника образования пыли -->
> - на основе рассчетов выбрать аппарат для заданного источника образования пыли

Шахтная мельница

Исходные данные:
- $Q = 0.1\,м^3/с$
  - объем очищаемого газа
- $\rho = 1.29 кг / м^3$ 
  - плотность газа при рабочих условиях
- $\mu = 17.3 \cdot 10^{-6}\,Па \cdot с$
  - вязкость газа при рабочей температуре
- $d_м = 56 \, мкм$
  - медианный размер частиц пыли
- $\lg \delta_4 = 0.97$
  - стандартное отклонение размеров частиц пыли
- $C_{вх} = 100 г/м^3$
  - входная концентрация пыли
- $\rho _ч = 2240\,кг/м^3$
  - плотность частиц пыли
- $\eta = 0.80$
  - требуемая эффективность очистки газа

параметры аппарата:
- $\omega _{оп}$ - скорость движения газа внутри аппарата, м/с
- $d^T _{оп} = d^T _{50}$ - диаметр частиц,
  очищаемых с эффективностью 50%, мкм
  <!-- _освещаемых_ с эффективностью 50%, мкм -->
- $\lg \delta ^T _\eta$ - стандартное отклонение функции распределения
  порциональных коэффицентов очистки

для начала выбираем по условию:

$$d_м > 2d^T _{50}$$

условие выполняется для любых параметров аппарата.

Диаметр аппарата вычисляется по формуле:

```math
\begin{equation}
D = \sqrt{ \frac{4 \cdot Q}{\pi \cdot \omega _{оп}} }
\end{equation}
```

Затем округляется до ближайшего типового значения $D_ц$

Затем вычисляется действительная скорость движения газа (м/с):

```math
\begin{equation}
\omega _Р = \frac{ 4 \cdot Q }{ \pi \cdot D_Ц^2 }
\end{equation}
```

При этом должно соблюдаться условие:

```math
100\% \cdot \left|
  \frac{ \omega _Р - \omega _{оп} }{ \omega _{оп} }
\right| \leqslant 15\%
```

Если же не соблюдается - подбираем аппарат с другими параметрами.

---

### ЦН-24:

- $\omega _{оп} = 4.5\,м/с$
- $d^T _{оп} = d^T _{50} = 8.50 \,мкм$
- $\lg \delta ^T _\eta = 0.308$

```math
% \begin{equation}
D = \sqrt{ \frac{4 \cdot Q}{\pi \cdot \omega _{оп}} }
% \end{equation}
```

```math
% \begin{equation}
D = \sqrt{ \frac{4 \cdot 0.1\,м^3/с}{\pi \cdot 4.5\,м/с} }
% \end{equation}
```

```math
D = \sqrt{ \frac{0.4\,м^2}{\pi \cdot 4.5} }
```

```math
D = 2 \sqrt{ \frac{0.1}{\pi \cdot 4.5} } \,м
```

```math
D \approx 0.1682088348\,м
```

выбираем ближайшее значение в таблице (наименьшее)

$$D_Ц = 0.2\,м$$

```math
% \begin{equation}
\omega _Р = \frac{ 4 \cdot Q }{ \pi \cdot D_Ц^2 }
% \end{equation}
```

```math
% \begin{equation}
\omega _Р = \frac{ 4 \cdot 0.1\,м^3/с }{ \pi \cdot (0.2\,м)^2 }
% \end{equation}
```

```math
\omega _Р = \frac{ 0.4\,м/с }{ \pi \cdot 0.04 }
```

```math
\omega _Р = \frac{ 10 }{ \pi } \,м/с
\approx 3.1830988618 \,м/с
```

```math
100\% \cdot \left|
  \frac{ 3.1830988618\,м/с - 4.5\,м/с }{ 4.5\,м/с }
\right|
\approx 29\%
```

$29\% > 15\%$; условие не выполняется, пробуем другие параметры

### ЦН-15У

- $\omega _{оп} = 3.5\,м/с$
- $d^T _{оп} = d^T _{50} = 6.00 \,мкм$
- $\lg \delta ^T _\eta = 0.283$

```math
% \begin{equation}
D = \sqrt{ \frac{4 \cdot 0.1\,м^3/с}{\pi \cdot 3.5\,м/с} }
% \end{equation}
```

```math
D = \sqrt{ \frac{4 \cdot 0.1\,м^3/с}{\pi \cdot 3.5\,м/с} }
```

$$D \approx 0.1907308908\,м$$

выбираем ближайшее значение в таблице (наименьшее)

$$D_Ц = 0.2\,м$$

- (не изменилось)

```math
\omega _Р
\approx 3.1830988618 \,м/с
```

```math
100\% \cdot \left|
  \frac{ 3.1830988618\,м/с - 3.5\,м/с }{ 3.5\,м/с }
\right|
\approx 9.05\%
```

$9.05\% \leqslant 15\%$; условие выполняется, проверяем дальше

---

Диаметр частиц, реально осаждаемых с эффективностью 50% при рабочих условиях:

```math
\begin{equation}
d_{50} = d_{50} ^T \cdot \sqrt{
  \frac{ D_Ц }{ D_Т }
  % \cdot \frac{ \rho _ч }{ \rho _{чт} }
  \cdot \frac{ \rho _{чт} }{ \rho _ч }
  \cdot \frac{ \mu }{ \mu _T }
  \cdot \frac{ \omega _T }{ \omega _P }
}
\end{equation}
```

- $\omega _T = 3.5\,м/с$
- $D _T = 0.6\,м$
- $\rho _{чт} = 1930\,кг/м^3$
- $\mu _T = 22.2 \cdot 10^{-6}\,Па \cdot с$

```math
\begin{equation}
d_{50} = d_{50} ^T \cdot \sqrt{
  \frac{ D_Ц }{ 0.6\,м }
  % \cdot \frac{ \rho _ч }{ \rho _{чт} }
  \cdot \frac{ 1930\,кг/м^3 }{ \rho _ч }
  \cdot \frac{ \mu }{ 22.2 \cdot 10^{-6}\,Па \cdot с }
  \cdot \frac{ 3.5\,м/с }{ \omega _P }
}
\end{equation}
```


```math
% \begin{equation}
d_{50} \approx 6.00 \,мкм \cdot \sqrt{
  \frac{ 0.2\,м }{ 0.6\,м }
  % \cdot \frac{ \rho _ч }{ \rho _{чт} }
  \cdot \frac{ 1930\,кг/м^3 }{ 2240\,кг/м^3 }
  \cdot \frac{ 17.3 \cdot 10^{-6}\,Па \cdot с }
    { 22.2 \cdot 10^{-6}\,Па \cdot с }
  \cdot \frac{ 3.5\,м/с }{ 3.18 \,м/с }
}
% \end{equation}
```

```math
d_{50} \approx 6 \cdot \sqrt{
  \frac{ 1 }{ 3 }
  % \cdot \frac{ \rho _ч }{ \rho _{чт} }
  \cdot \frac{ 193 }{ 224 }
  \cdot \frac{ 173 }
    { 222 }
  \cdot \frac{ 3.5 }{ 3.18 }
} \,мкм
```

```math
d_{50} \approx \sqrt{
  \frac{ 36 }{ 3 }
  % \cdot \frac{ \rho _ч }{ \rho _{чт} }
  \cdot \frac{ 193 }{ 224 }
  \cdot \frac{ 173 }
    { 222 }
  \cdot \frac{ 3.5 }{ 3.18 }
} \,мкм
```

```math
d_{50} \approx \sqrt{
  12
  % \cdot \frac{ \rho _ч }{ \rho _{чт} }
  \cdot \frac{ 193 }{ 224 }
  \cdot \frac{ 173 }
    { 222 }
  \cdot \frac{ 3.5 }{ 3.18 }
} \,мкм
```

<!-- ```math
d_{50} \approx 8.8679776475 \,мкм
``` -->

<!-- forgot sqrt again! -->

```math
d_{50} \approx 2.9779149832 \,мкм
```

Условие:

$$d_{50} < d_м$$

$$2.9779149832\, мкм < 56 \, мкм$$

выполняется; проверяем дальше

---

```math
\begin{equation}
X = \frac{ \lg(d_M/d_{50}) }{
  \sqrt{ \lg^2 \delta _\eta ^T + \lg^2 \delta _ч }
}
\end{equation}
```

```math
% \begin{equation}
X \approx \frac{ \lg(56\,мкм/2.9779149832\, мкм) }{
  \sqrt{ 0.283^2 + 0.97^2 }
}
% \end{equation}
```

```math
% \begin{equation}
X \approx \frac{ \lg(18.8051036769) }{
  \sqrt{ 0.080089 + 0.9409 }
}
% \end{equation}
```

```math
% \begin{equation}
X \approx \frac{ 1.2742757321 }{
  \sqrt{ 1.020989 }
}
% \end{equation}
```

```math
% \begin{equation}
X \approx \frac{ 1.2742757321 }{
  1.0104400032
}
\approx 1.2611097424
% \end{equation}
```


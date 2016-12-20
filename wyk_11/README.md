# Rekurencja
## O tym jak kompilatory radzą sobie z tłumaczeniem rekurencji

Zamieszczone w tym katalogu pliki w języku C zostały przetłumaczone na język maszynowy (opcja **-S**). 

Dodatkowo polecono kompilatorowi w jak najwyższym stopniu zoptymalizować kod wynikowy (opcja **-O3**).

Aby skompilować przykłady użyj polecenia **make**.

### Przykład f1.c

Funkcja **int f(int)** tyle razy dodaje 2 do 0 ile razy odejmowała 1 od n aż zmalało do 0. Zatem wartością *f(n)* jest *2n.*

Kompilator optymalizując przekład wyliczył wartość funkcji jedną instrukcją **leal**!

> f: leal (%rdi,%rdi), %eax<br>
&nbsp;&nbsp;&nbsp;retq

Wynik działania jest następujący: EAX = RDI + RDI.

### Przykład f2.c


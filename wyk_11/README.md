# Rekurencja
## O tym jak kompilatory radzą sobie z tłumaczeniem rekurencji

Zamieszczone w tym katalogu pliki w języku C zostały przetłumaczone na język maszynowy (opcja **-S**). 

Dodatkowo polecono kompilatorowi w jak najwyższym stopniu zoptymalizować kod wynikowy (opcja **-O3**).

Aby skompilować przykłady użyj polecenia **make**.

### Elementy jezyka assemblera

Opiszemy kilka podstawowych faktow o jezyku assemblera, ktorych znajomosc jest niezbedna do zrozumienia przykladow.

#### Rejestry

#### Adresacja

> displacement(base register, offset register, scalar multiplier)


Ponizsza instrukcja umieszcza w rejestrze eax dluga dana (czterobajtowa) spod adresu ebp + 4 * edx - 8: 
>movl -4(%ebp, %edx, 4), %eax

#### Arytmetyka


### Przykład f1.c

Funkcja **int f(int)** tyle razy dodaje 2 do 0 ile razy odejmowała 1 od n aż zmalało do 0. Zatem wartością *f(n)* jest *2n.*

Kompilator optymalizując przekład wyliczył wartość funkcji jedną instrukcją **leal**!

> f: leal (%rdi,%rdi), %eax<br>
&nbsp;&nbsp;&nbsp;retq

Wynik działania jest następujący: EAX = RDI + RDI.

### Przykład f2.c

Tym razem funkcja **int f(int)** tyle razy dodaje 3 ile odejmuje 1.

Kompilator znowu optymalizując wyliczył wartość funkcji jedną instrukcją **leal**!

> f: leal (%rdi,%rdi,2), %eax<br>
&nbsp;&nbsp;&nbsp;retq

Wynik działania: EAX = RDI + 2 * RDI

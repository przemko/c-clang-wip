with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Text_IO; use Ada.Text_IO;

procedure Sumy is
    Suma_Dodatnich : Integer := 0;
    Suma_Ujemnych  : Integer := 0;
    N              : Integer;
begin
    Put_Line ("Wpisuj liczby całkowite.");
    Put_Line ("Aby zakończyć wpisz liczbę zero.");
    loop
        Get (N);
        exit when N = 0;
        if N > 0 then
            Suma_Dodatnich := Suma_Dodatnich + N;
        else
            Suma_Ujemnych := Suma_Ujemnych + N;
        end if;
    end loop;
    Put_Line ("Suma dodatnich wynosi " & Suma_Dodatnich'Image);
    Put_Line (" Suma ujemnych wynosi " & Suma_Ujemnych'Image);
end Sumy;
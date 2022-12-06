with Ada.Text_IO; use Ada.Text_IO;
with Listy; use Listy;

procedure Main is
    Wsk : Lista;
begin
    Dopisz_Na_Koniec (Wsk, 1);
    Dopisz_Na_Koniec (Wsk, 2);
    Dopisz_Na_Koniec (Wsk, 3);
    Drukuj (Wsk);
    New_Line;
    Usun (Wsk);
    Dopisz_Na_Poczatek (Wsk, 1);
    Dopisz_Na_Poczatek (Wsk, 2);
    Dopisz_Na_Poczatek (Wsk, 3);
    Drukuj (Wsk);
    Usun (Wsk);
end Main;

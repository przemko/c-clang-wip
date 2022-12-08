with Ada.Unchecked_Deallocation;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

package body Listy is

    procedure Dopisz_Na_Poczatek (Wsk : in out Lista; I : Integer) is
        Nowy : Lista;
    begin
        Nowy := new Wezel;
        Nowy.Wartosc := I;
        Nowy.Nastepny := Wsk;
        Wsk := Nowy;
    end Dopisz_Na_Poczatek;
    
    procedure Dopisz_Na_Koniec (Wsk : in out Lista; I : Integer) is
        Nowy, Pomoc : Lista;
    begin
        Nowy := new Wezel;
        Nowy.Wartosc := I;
        if Wsk = null then
            Wsk := Nowy;
        else
            Pomoc := Wsk;
            while Pomoc.Nastepny /= null loop
                Pomoc := Pomoc.Nastepny;
            end loop;
            Pomoc.Nastepny := Nowy;
        end if;
    end Dopisz_Na_Koniec;

    procedure Drukuj (Wsk : in Lista) is
        Pomoc : Lista := Wsk;
    begin
        while Pomoc /= null loop
            Put (Pomoc.Wartosc);
            Pomoc := Pomoc.Nastepny;
        end loop;
    end Drukuj;

    procedure Usun (Wsk : in out Lista) is

        procedure Free is new Ada.Unchecked_Deallocation (Wezel, Lista);

        Pomoc : Lista;
    begin
        while Wsk /= null loop
            Pomoc := Wsk.Nastepny;
            Free (Wsk);
            Wsk := Pomoc;
        end loop;
    end Usun;

end Listy;

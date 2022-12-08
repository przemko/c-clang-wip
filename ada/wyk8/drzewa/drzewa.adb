with Ada.Unchecked_Deallocation;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

package body Drzewa is 

    procedure Wstaw_Uporzadkowane (Wsk : in out Drzewo; I : Integer) is
    begin
        if Wsk = null then
            Wsk := new Wezel;
            Wsk.Wartosc := I;
        elsif I < Wsk.Wartosc then
            Wstaw_Uporzadkowane (Wsk.Lewe, I);
        elsif I > Wsk.Wartosc then
            Wstaw_Uporzadkowane (Wsk.Prawe, I);
        end if;
    end Wstaw_Uporzadkowane;

    procedure Usun (Wsk : in out Drzewo) is

        procedure Free is new Ada.Unchecked_Deallocation (Wezel, Drzewo);

    begin
        if Wsk /= null then
            Usun (Wsk.Lewe);
            Usun (Wsk.Prawe);
            Free (Wsk);
        end if;
    end Usun;

    procedure Drukuj (Wsk : in Drzewo; P : Porzadek := Infiksowo) is
    begin
        if Wsk /= null then
            if P = Prefiksowo then
                Put (Wsk.Wartosc);
            end if;
            Drukuj (Wsk.Lewe, P);
            if P = Infiksowo then
                Put (Wsk.Wartosc);
            end if;
            Drukuj (Wsk.Prawe, P);
            if P = Postfiksowo then
                Put (Wsk.Wartosc);
            end if;
        end if;
    end Drukuj;

end Drzewa;

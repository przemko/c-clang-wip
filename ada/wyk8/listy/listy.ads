package Listy is

    type Wezel;

    type Lista is access Wezel;

    type Wezel is record
        Wartosc : Integer;
        Nastepny : Lista;
    end record;

    procedure Dopisz_Na_Poczatek (Wsk : in out Lista; I : Integer);
    procedure Dopisz_Na_Koniec (Wsk : in out Lista; I : Integer);
    procedure Drukuj (Wsk : in Lista);
    procedure Usun (Wsk : in out Lista);

end Listy;

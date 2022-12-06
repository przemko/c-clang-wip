package Drzewa is

    type Wezel;

    type Drzewo is access Wezel;

    type Wezel is record
        Wartosc : Integer;
        Lewe : Drzewo;
        Prawe : Drzewo;
    end record;

    type Porzadek is (Prefiksowo, Infiksowo, Postfiksowo);

    procedure Wstaw_Uporzadkowane (Wsk : in out Drzewo; I : Integer);
    procedure Usun (Wsk : in out Drzewo);
    procedure Drukuj (Wsk : in Drzewo; P : Porzadek := Infiksowo);

end Drzewa;

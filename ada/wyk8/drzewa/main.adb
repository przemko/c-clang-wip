with Drzewa; use Drzewa;

procedure Main is
    Wsk : Drzewo;
begin
    Wstaw_Uporzadkowane (Wsk, 4);
    Wstaw_Uporzadkowane (Wsk, 2);
    Wstaw_Uporzadkowane (Wsk, 6);
    Wstaw_Uporzadkowane (Wsk, 1);
    Wstaw_Uporzadkowane (Wsk, 3);
    Wstaw_Uporzadkowane (Wsk, 5);
    Wstaw_Uporzadkowane (Wsk, 7);
    Drukuj (Wsk);
    Usun (Wsk);
end Main;
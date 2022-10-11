
with Ada.Text_IO; use Ada.Text_IO;

procedure Zamiana is
    type Modularny is mod 2**64;
    X : Modularny := 13;
    Y : Modularny := 7;
begin
    Put_Line ("X = " & X'Image & ", Y = " & Y'Image);
    X := X xor Y;
    Y := X xor Y;
    X := X xor Y;
    Put_Line ("X = " & X'Image & ", Y = " & Y'Image);
end Zamiana;
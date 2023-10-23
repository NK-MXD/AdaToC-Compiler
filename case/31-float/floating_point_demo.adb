with Ada.Text_IO; use Ada.Text_IO;

procedure Floating_Point_Demo is
    A : constant Float := 2.5;
begin
    Put_Line ("The value of A is "
                & Float'Image (A));
    A := abs (A - 4.5);
    Put_Line ("The value of A is "
              & Float'Image (A));
    A := A ** 2 + 1.0;
    Put_Line ("The value of A is "
              & Float'Image (A));
end Floating_Point_Demo;
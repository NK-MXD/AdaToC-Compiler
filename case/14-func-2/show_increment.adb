with Ada.Text_IO; use Ada.Text_IO;
with Increment;

procedure Show_Increment is
    A, B, C : Integer;
begin
    C := Increment;
   --              ^ Parameterless call,
   --                value of I is 0
   --                and Incr is 1

   Put_Line ("Using defaults for Increment_By is "
             & Integer'Image (C));

   A := 10;
   B := 3;
   C := Increment (A, B);
   --              ^ Regular parameter passing

   Put_Line ("Increment of "
             & Integer'Image (A)
             & " with "
             & Integer'Image (B)
             & " is "
             & Integer'Image (C));

   A := 20;
   B := 5;
   C := Increment (I => A,
                    Incr => B);
    --                ^ Named parameter passing

   Put_Line ("Increment of "
             & Integer'Image (A)
             & " with "
             & Integer'Image (B)
             & " is "
             & Integer'Image (C));
end Show_Increment;
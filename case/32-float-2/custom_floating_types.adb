with Ada.Text_IO; use Ada.Text_IO;

procedure Custom_Floating_Types is
    type T3  is digits 3;
    type T15 is digits 15;
    type T18 is digits 18;
    -- Operations on these custom types will 
    -- then have at least the specified precision

    C1 : constant := 1.0e-4;

    A : constant T3  := 1.0 + C1;
    B : constant T18 := 1.0 + C1;
begin
    Put_Line ("T3  requires "
              & Integer'Image (T3'Size)
              & " bits");
    Put_Line ("T15 requires "
              & Integer'Image (T15'Size)
              & " bits");
    Put_Line ("T18 requires "
              & Integer'Image (T18'Size)
              & " bits");
    Put_Line ("The value of A is "
             & T3'Image (A));
    Put_Line ("The value of B is "
             & T18'Image (B));
    -- 1.00E+00 and 1.00010000000000000E+00
end Custom_Floating_Types;
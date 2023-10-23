with Ada.Text_IO; use Ada.Text_IO;
with Ada.Numerics; use Ada.Numerics;

procedure Floating_Point_Range is
    type T_Norm  is new Float range -1.0 .. 1.0;
    -- for ensuring that variables of this type stay within this range; 
    -- otherwise an exception is raised
    A  : T_Norm;
    type T6_Inv_Trig  is
        digits 6 range -Pi / 2.0 .. Pi / 2.0;
begin
    A := 1.0;
    Put_Line ("The value of A is "
              & T_Norm'Image (A));
end Floating_Point_Range;
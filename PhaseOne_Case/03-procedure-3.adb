procedure case3 (A, B : Integer) is
   procedure case3nest (V : Natural);
   Tmp : Integer;
   procedure case3nest (V : Natural) is
   begin
      V := 1;
   end case2nest;
begin
   Tmp := A;

   --  Error: assignment to "in" mode
   --         parameter not allowed
   A := B;

   --  Error: assignment to "in" mode
   --         parameter not allowed
   B := Tmp;
   case3nest(2);
end case3;
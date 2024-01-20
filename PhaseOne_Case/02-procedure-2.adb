procedure case2 is
   A : Integer := 1;
   B : Integer;
   procedure case2nest is
   C : Integer;
   begin
      C := 1;
   end case2nest;
begin
   B := A + 5;
end case2;
procedure case10 is
   I : Integer := 1;
   M : Integer;
begin
   --  Condition must be a Boolean value
   --  (no Integers).
   --  Operator "<=" returns a Boolean
   while I <= 5 loop
      M := I;
      I := I + 1;
   end loop;
end case10;
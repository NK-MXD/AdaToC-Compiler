procedure case7 is
    N : Integer := 1;
begin
   for I in 1 .. 5 loop
      --  Put_Line is a procedure call
      N := I;
   end loop;
   for I in reverse 1 .. 5 loop
      N := I;
   end loop;
end case7;
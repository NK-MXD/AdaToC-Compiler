procedure case13 is
    B : Boolean;
begin
   for I in 1 .. 10 loop
      B := (case I is
         when 1 | 3 | 5 | 7 | 9  => True,
         when 2 | 4 | 6 | 8 | 10 => False);
   end loop;
end case13;
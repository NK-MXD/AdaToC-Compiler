procedure case13 is
    B : Boolean;
begin
   for I in 1 .. 10 loop
      case I is
         when 1 | 3 | 5 | 7 | 9  =>
            B := True;
         when 2 | 4 | 6 | 8 | 10  =>
            B := False;
      end case;
   end loop;
end case13;



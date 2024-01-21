procedure case12 is
   N : Integer;
begin
   N := -2;
   declare
      S : constant String :=
        (if N > 0
           then " is a positive number"
           else " is not a positive number");
   begin
      null;
   end;
end case12;
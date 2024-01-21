procedure case8 is
   --  Variable declaration:
   I : Integer := 1;
   --  ^ Type
   --             ^ Initial value
   M : Integer;
begin
   loop
      M := I;
      --  Exit statement:
      exit when I = 5;
      --        ^ Boolean condition

      --  Assignment:
      I := I + 1;
      --  There is no I++ short form to
      --  increment a variable
   end loop;
end case8;
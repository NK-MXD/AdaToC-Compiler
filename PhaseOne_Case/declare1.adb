procedure case11 is
begin
   loop

      declare
         Name : Integer := 22;
         --               ^ Call to the
         --                 Get_Line function
      begin
         exit when Name >= 10;

      end;

      --  Name is undefined here
   end loop;
end case11;
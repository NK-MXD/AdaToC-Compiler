procedure case14 is
    I : Integer := 1;
begin
   loop
      declare
         Name : constant String := "Num is: " & Integer'Image (I);
         --               ^ Call to the
         --                 Get_Line function
      begin
         exit when I = 4;

      end;
      I := I + 1;
      --  Name is undefined here
   end loop;
end case14;
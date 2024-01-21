procedure case15 is
   A : Integer := Integer'Last;
   B : Integer;
begin
   B := A - 5;
   --  This operation will overflow, eg. it
   --  will raise an exception at run time.
end case15;
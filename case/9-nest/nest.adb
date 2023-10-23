with Ada.Text_IO;
use Ada.Text_IO;

procedure Nest is
   procedure Nested is
   begin
      Put_Line ("Hello World");
   end Nested;
begin
   Nested;
end Nest;

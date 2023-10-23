with Ada.Text_IO;

procedure Main is
   package TIO renames Ada.Text_IO;
   procedure Say (Something : String)
    renames Ada.Text_IO.Put_Line;
begin
   TIO.Put_Line ("Hello");
   Say ("hello!");
end Main;
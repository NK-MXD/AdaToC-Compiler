with Ada.Text_IO; use Ada.Text_IO;

with Book.Additional_Operations;
use  Book.Additional_Operations;

procedure Main is
begin
   Put_Line (Get_Extended_Title);
   Put_Line (Get_Extended_Author);
   Put_Line (Get_Extended_Title_Other);
   Put_Line (Get_Extended_Author_Other);
end Main;
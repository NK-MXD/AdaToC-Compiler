with Ada.Text_IO;
use Ada.Text_IO;

procedure Show_Image_Renaming is
    function Image (I : Integer) return String 
        renames Integer'Image;
begin
    Put_Line (Img(2));
    Put_Line (Img(3));
end Show_Image_Renaming;
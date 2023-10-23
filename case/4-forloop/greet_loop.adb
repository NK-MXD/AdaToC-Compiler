with Ada.Text_IO;
use Ada.Text_IO;

procedure Greet is
begin
    --  1 .. 5 is a discrete range, from 1 to 5 inclusive.
    for I in 1 .. 5 loop
        Put_Line("hello!" & Integer'Image(I));
        -- & is a symbol to concat strings. 

        -- Integer'Image is a method of Integer used to convert number to string.
        -- That likes Java
    end loop;

    for J in reverse 1 .. 5 loop
        Put_Line("hello!" & Integer'Image(J));
    end loop;
end Greet;


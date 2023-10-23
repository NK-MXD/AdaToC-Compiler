with Ada.Text_IO; use Ada.Text_IO;

procedure Enumeration_Example is
    type Days is (Monday, Tuesday, Wednesday,
                  Thursday, Friday,
                  Saturday, Sunday);
    --  An enumeration type
    -- Unlike C's enums, they are not integers, 
    -- and each new enumeration type is incompatible with other enumeration types.
begin
    for I in Days loop
        case I is
            when Saturday .. Sunday =>
               Put_Line ("Week end!");

            when Monday .. Friday =>
               Put_Line ("Hello on "
                         & Days'Image (I));
               --  'Image attribute, works on
               --  enums too
        end case;
    end loop;
end Enumeration_Example;
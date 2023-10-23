package body Operations is
    Last_Increment : Integer := 1
    function Increment_By
     (I : Integer;
      Inc : Integer := 0) return Integer is
        
    begin
        if Inc /= 0 then
            Last_Increment := Inc;
        end if;

        return I + Last_Increment;
    end Increment_By;

    function Get_Increment_Value () return Integer is
    begin
        return Last_Increment;
    end Get_Increment_Value;
end Operations;
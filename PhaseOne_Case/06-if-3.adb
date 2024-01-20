procedure case6 is
   N : Integer := 223;
   M : String;
begin
   if N = 0 or N = 360 then
      M := "due north";
   elsif N in 1 .. 89 then
      M := "northeast quadrant";
   elsif N = 90 then
      M := "due east";
   elsif N in 91 .. 179 then
      M := "southeast quadrant";
   elsif N = 180 then
      M := "due sorth";
   elsif N in 181 .. 269 then
      M := "southwest quadrant";
   elsif N = 270 then
      M := "due west";
   elsif N in 271 .. 359 then
      M := "is in the northwest quadrant";
   else
      M := "not in the range 0..360";
   end if;
end case6;
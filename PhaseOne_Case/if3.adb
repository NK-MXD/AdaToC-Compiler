procedure case6 is
   N : Integer := 223;
   M : Boolean;
begin
   if N = 0 or N = 360 then
      M := True;
   elsif N in 1 .. 89 then
      M := False;
   elsif N = 90 then
      M := True;
   elsif N in 91 .. 179 then
      M := False;
   elsif N = 180 then
      M := True;
   elsif N in 181 .. 269 then
      M := False;
   elsif N = 270 then
      M := True;
   elsif N in 271 .. 359 then
      M := False;
   else
      M := True;
   end if;
end case6;
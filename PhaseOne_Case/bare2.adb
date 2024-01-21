procedure case9 is
   N : Integer;
   M : Integer;
begin
   loop
      N := 361;
      case N is
         when 0 | 360 =>
            M := N + 23;
         when 1 .. 89 =>
            M := N + 23;
         when 90 =>
            M := N + 23;
         when 91 .. 179 =>
            M := N + 23;
         when 180 =>
            M := N + 23;
         when 181 .. 269 =>
            M := N + 23;
         when 270 =>
            M := N + 23;
         when 271 .. 359 =>
            M := N + 23;
         when others =>
            M := N + 23;
            exit;
      end case;
   end loop;
end case9;
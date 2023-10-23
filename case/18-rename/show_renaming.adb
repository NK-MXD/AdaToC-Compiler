with Ugly_Name;

procedure Show_Renaming is
    procedure Show (S : String) renames Ugly_Name;
begin
    Show("hello!");
end Show_Renaming;
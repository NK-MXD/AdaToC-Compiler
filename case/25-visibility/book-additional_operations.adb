package body Book.Additional_Operations is

    function Get_Extended_Title return String is
    begin
       return "Book Title: " & Title;
    end Get_Extended_Title;

    function Get_Extended_Author return String is
    begin
       --  "Author" string declared in the body
       --  of the Book package is not visible
       --  here. Therefore, we cannot write:
       --
       --  return "Book Author: " & Author;

       return "Book Author: Unknown";
    end Get_Extended_Author;

    function Get_Extended_Title_Other return String is
    begin
       return "Book Title: " & Get_Title;
    end Get_Extended_Title;

    function Get_Extended_Author_Other return String is
    begin
       return "Book Author: " & Get_Author;
    end Get_Extended_Author;

end Book.Additional_Operations;
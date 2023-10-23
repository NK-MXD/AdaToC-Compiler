procedure Recursive is
    -- forward declare of Compute_A
    procedure Compute_A (V : Natural);

    procedure Compute_B (V : Natural) is
    begin
        if V > 5 then 
            Compute_A(V - 1);
        end if;
    end Compute_B;

    procedure Compute_A (V : Natural) is
    begin
        if V > 2 then
            Compute_B(V - 1);
        end if;
    end Compute_A;
begin
    Compute_A(15);
end Recursive;
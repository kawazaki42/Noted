{$asmmode intel}


function IsDivisible(a, b: Int32): Boolean;
label divisible;
begin
    // default
    IsDivisible := False;

    asm
        mov eax, a
        cdq

        // mov ebx, b
        // idiv ebx

        // do it in one step

        idiv b

        cmp edx, 0
        je divisible
    end;
    Exit;

divisible:
    IsDivisible := True;
    Exit;
end;


var
    a, b: Int32;

begin
    Write('Делимое: ');
    Read(a);

    Write('Делитель: ');
    Read(b);

    if IsDivisible(a, b) then
    begin
        WriteLn(a,' делится на ',b);
        if b = 2 then
            WriteLn('т.е. ',a,' четно');
    end else
    begin
        WriteLn(a,' НЕ делится на ',b);
        if b = 2 then
            WriteLn('т.е. ',a,' нечетно');
    end;
end.
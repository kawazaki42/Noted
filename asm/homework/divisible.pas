{$asmmode intel}

function IsDivisible(a, b: Int32): ByteBool;
// label divisible;
begin
    asm
        mov eax, a

        // mov ebx, b
        // idiv ebx

        idiv b

        // cmp edx, 0

        mov @result, dl

        // mov c, 42
    end;
// divisible:

    WriteLn(IsDivisible);

    IsDivisible := not IsDivisible;

end;

// label divisible;

var
    a, b: Int32;
    // c: Boolean;

begin
    Write('Делимое: ');
    ReadLn(a);

    Write('Делитель: ');
    ReadLn(b);

    if IsDivisible(a, b) then
    begin
        WriteLn(a,' делится на ',b);
        if b = 2 then
            WriteLn('т.е. ',a,' нечетно');
    end else
    begin
        WriteLn(a,' НЕ делится на ',b);
        if b = 2 then
            WriteLn('т.е. ',a,' четно');
    end;

    // WriteLn(c);

// not divisible:
//     Exit;

// divisible:
//     Exit;

end.
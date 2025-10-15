{$asmmode intel}
{$goto on}
// {$mode objfpc}
// label divisible;


function IsDivisible(a, b: Int32): Boolean;
// assembler;
// label divisible;
// var
    // r: Byte;
begin
    // Exit;

    asm
        mov eax, a
        cdq

        mov ebx, b
        idiv ebx

        // do it in one step

        // idiv [b]

        cmp edx, 0
        // je divisible

        mov @result, False
        // ret

    // divisible:
        // mov r, 0
        mov @result, True
    end;
    // IsDivisible := False;
    // Exit(False);

// 1:
    // IsDivisible := True;
    // Exit;
    // Exit(True);

    // IsDivisible := Boolean(r);

    // WriteLn(r);
end;


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
            WriteLn('т.е. ',a,' четно');
    end else
    begin
        WriteLn(a,' НЕ делится на ',b);
        if b = 2 then
            WriteLn('т.е. ',a,' нечетно');
    end;

    // WriteLn(c);

// not divisible:
//     Exit;

// divisible:
//     Exit;

end.
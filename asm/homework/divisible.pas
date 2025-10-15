{$asmmode intel}

// function IsDivisible(a, b: Int32): ByteBool;
// begin
//     asm
//     end;
// end;

label divisible;

var
    a, b: Int32;
    // c: Boolean;

begin
    Write('Делимое: ');
    ReadLn(a);

    Write('Делитель: ');
    ReadLn(b);

    asm
        mov eax, a

        // mov ebx, b

        // idiv ebx

        idiv b

        cmp edx, 0

        je divisible

        // mov c, 42
    end;

    // WriteLn(c);

// not divisible:
    WriteLn(a,' НЕ делится на ',b);
    if b = 2 then
        WriteLn('т.е. ',a,' нечетно');
    Exit;

divisible:
    WriteLn(a,' делится на ',b);
    Exit;

end.
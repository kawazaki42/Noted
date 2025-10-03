{$asmmode intel}
{$assertions on}

var
  a, b, c: Int32;
  res: Int32;

function solve(a, b, c: Int32): Int32;
var
  quot, remain: Int32;
begin
// procedure solve(var a, b, c: Int32);
// assembler;
// stdcall;
  asm
    // счетчик
    mov ecx, 0

    // ecx++
    inc cl

    // a *= ecx  // временно используя eax
    mov eax, a
    imul ecx
    mov a, eax

    // ecx++
    inc cl

    // b *= ecx  // временно используя eax
    mov eax, b
    imul ecx
    mov b, eax

    // ecx++
    inc cl

    // c *= ecx  // временно используя eax
    mov eax, c
    imul ecx
    mov c, eax

    // eax = a + b + c
    mov eax, a
    add eax, b
    add eax, c

    // Пусть sum = eax (для псевдокода ниже)

    // очищам старшую часть делимого
    // mov edx, 0  // не учитывает знак!
    cdq  // делает именно то что нам нужно
    mov ebx, 3  // делитель
    idiv ebx    // деление:
    // eax := sum div 3
    // edx := sum mod 3

    // quot   := sum div 3
    mov quot, eax

    // remain := sum mod 3
    mov remain, edx

    // eax = 3 * remain
    mov eax, remain
    mov ebx, 3
    imul ebx

    // ebx = quot
    mov ebx, quot

    // ebx -= eax
    sub ebx, eax

    // res = quot - 3*remain
    mov @result, ebx
    // mov eax, ebx
    // mov [res], ebx
  end;
end;


begin
  if ParamCount = 1 then
    case ParamStr(1) of
      '--test': begin
        Assert(solve(10, 20, 30) = 40);
        Assert(solve(0, 5, 10) = 10);
        Assert(solve(-4, 7, -2) = -2);
        Assert(solve(1, 1, 1) = 2);
        WriteLn('Кайф');
        Exit;
      end;
      '--fail': begin
        WriteLn('Проверка на бдительность: щас программа должна провалить тест.');
        Assert(False);
        WriteLn('ПАНИКА! ТЕСТЫ ОТКЛЮЧЕНЫ!!!');
      end;
  end;

  Write('a = ');
  Read(a);

  Write('b = ');
  Read(b);

  Write('c = ');
  Read(c);

  // solve(a, b, c);
  res := solve(a, b, c);
  writeln(res);
end.
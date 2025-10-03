{$asmmode intel}
{$assertions on}

var
  a, b, c: Int32;
  res: Int32;

// procedure solve(var a, b, c: Int32);
// assembler;
// stdcall;

function solve(a, b, c: Int32): Int32;
var
  quot, remain: Int32;
begin
  asm
    // счетчик
    mov ecx, 0

    // ecx++
    inc ecx

    // ebx = a * ecx
    mov eax, a    // 1ый множитель
    imul ecx      // умножить на ecx
    mov ebx, eax  // результат в ebx

    // ecx++
    inc ecx

    // ebx += b * ecx
    mov eax, b    // 1ый множитель
    imul ecx      // умножить на ecx
    add ebx, eax  // результат прибавить к ebx

    // ecx++
    inc ecx

    // ebx += c * ecx
    mov eax, c    // 1ый множитель
    imul ecx      // умножить на ecx
    add ebx, eax  // результат прибавить к ebx


    mov eax, ebx  // сумма, она же делимое

    // очищам старшую часть делимого
    // mov edx, 0  // не учитывает знак!
    cdq  // делает именно то что нам нужно!
         // (т.е. расширяет EAX до EDX:EAX учитывая знак)

    mov ebx, 3    // делитель
    idiv ebx      // деление:
    // eax := sum div 3
    // edx := sum mod 3

    // сохраним остаток в ebx
    mov ebx, edx

    // ebx *= 3
    imul ebx, 3

    // eax -= ebx
    // где:
    // - eax - частное
    // - ebx - утроенный остаток
    sub eax, ebx

    mov @result, eax
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
        Assert(solve(-4, -7, -2) = -8);
        Assert(solve(-4, -8, -2) = -2);
        Assert(solve(-4, -7, -3) = -9);
        WriteLn('Кайф');
        Exit;
      end;
      '--fail': begin
        WriteLn('Проверка на бдительность: щас программа должна провалить тест.');
        res := solve(1, 1, 1);
        WriteLn('Assert(',res,' <> 2);');
        Assert(res <> 2);
        // Assert(False);
        WriteLn('ПАНИКА! ЗАВЕДОМО ЛОЖНЫЙ ТЕСТ НЕ ПРОВАЛЕН! ТЕСТЫ ОТКЛЮЧЕНЫ!!!');
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
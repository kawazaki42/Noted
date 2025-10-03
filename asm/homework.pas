{$asmmode intel}

var
  a, b, c: Int32;
  quot, remain: Int32;
  res: Int32;

begin
  Write('a = ');
  Read(a);
  Write('b = ');
  Read(b);
  Write('c = ');
  Read(c);
  //read(a, b, c);

  asm
    // счетчик
    mov ecx, 0

    // ecx++
    inc cl

    // a *= ecx  // временно используя eax
    mov eax, [a]
    imul ecx
    mov [a], eax

    // ecx++
    inc cl

    // b *= ecx  // временно используя eax
    mov eax, [b]
    imul ecx
    mov [b], eax

    // ecx++
    inc cl

    // c *= ecx  // временно используя eax
    mov eax, [c]
    imul ecx
    mov [c], eax

    // eax = a + b + c
    mov eax, [a]
    add eax, [b]
    add eax, [c]

    // Пусть sum = eax (для псевдокода ниже)

    mov edx, 0  // очищам старшую часть делимого
    mov ebx, 3  // делитель
    idiv ebx    // деление:
    // eax := sum div 3
    // edx := sum mod 3

    // quot   := sum div 3
    mov [quot], eax

    // remain := sum mod 3
    mov [remain], edx

    // eax = 3 * remain
    mov eax, [remain]
    mov ebx, 3
    imul ebx

    // ebx = quot
    mov ebx, [quot]

    // ebx -= eax
    sub ebx, eax

    // res = quot - 3*remain
    mov [res], ebx
  end;

  writeln(res);

  //writeln(a);
  //writeln(b);
  //writeln(c);
end.
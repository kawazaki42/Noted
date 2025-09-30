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

    // ecx++; a *= ecx
    inc cl
    mov eax, [a]
    imul ecx
    //mul ecx
    mov [a], eax

    // ecx++; b *= ecx
    inc cl
    mov eax, [b]
    imul ecx
    //mul ecx
    mov [b], eax

    // ecx++; c *= ecx
    inc cl
    mov eax, [c]
    imul ecx
    //mul ecx
    mov [c], eax

    // eax = a + b + c
    mov eax, [a]
    add eax, [b]
    add eax, [c]

    // quot   := eax div 3
    // remain := eax mod 3
    mov edx, 0  // очищам старшую часть делимого
    mov ebx, 3
    idiv ebx
    mov [quot], eax
    mov [remain], edx

    mov eax, [remain]
    mov ebx, 3
    imul ebx

    mov ebx, [quot]
    sub ebx, eax

    mov [res], ebx
  end;

  writeln(res);

  //writeln(a);
  //writeln(b);
  //writeln(c);
end.
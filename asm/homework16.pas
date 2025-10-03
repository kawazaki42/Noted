{$asmmode intel}

var
  a, b, c: Int16;
  mula, mulb, mulc: Int32;
  quot, remain: Int16;
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
    mov ax, [a]
    imul cx
    //mul ecx
    mov [mula], dx:ax

    // ecx++; b *= ecx
    inc cl
    mov ax, [b]
    imul cx
    //mul ecx
    mov [mulb], dx:ax

    // ecx++; c *= ecx
    inc cl
    mov ax, [c]
    imul cx
    //mul ecx
    mov [mulc], dx:ax

    // eax = a + b + c
    mov eax, [mula]
    add eax, [mulb]
    add eax, [mulc]

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
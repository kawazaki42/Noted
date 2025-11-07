{$ASMMODE INTEL}

// label l;

var
  res: Int32;

begin
  res := 7;
  asm
    // input
    mov eax, res
    mov ecx, 10

    // main loop
  @loop:
    add eax, 2
    loop @loop
    // dec ecx
    // sub ecx, 1
    // jnz @l

    // output
    mov res, eax
  end;
  WriteLn(res);
end.
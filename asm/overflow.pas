{$asmmode intel}

var
  res: Word;

begin
  asm
    mov AX, 0
    // mov AL, 100
    // mov BL, 58
    mov AH, 255
    add AH, 100
    mov [res], AX
  end;
  writeln(res);
  //writeln('братуха');
end.
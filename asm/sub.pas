{$asmmode intel}

var
  res: Byte;

begin
  asm
    mov AL, 100
    mov BL, 58
    sub AL, BL
    mov [res], AL
  end;
  writeln(res);
  writeln('братуха');
end.
{$asmmode intel}

var
  result: Byte;

begin
  asm
    mov AL, 20
    mov BL, 22
    add AL, BL
    mov [result], AL
  end;
  writeln(result);
  writeln('братуха');
end.
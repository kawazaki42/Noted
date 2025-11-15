{$asmmode intel}

label fake_add;

var
  input, summand: Int32;

begin
  input := 0;

  if ParamCount > 0 then
    ReadStr(ParamStr(1), input);

  summand := 2;

  if ParamCount > 1 then
    ReadStr(ParamStr(2), summand);

  asm
    mov ecx, 10
  @loop:
    push input
    push summand
    call fake_add
    mov input, eax
    loop @loop

    jmp @end_of_asm

  fake_add:
    pop esi
    pop eax
    pop ebx

    add eax, ebx

    push esi
    ret

  @end_of_asm:
  end;

  WriteLn(input);
end.
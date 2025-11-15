library fn_unit;

{$asmmode intel}

procedure fake_add;
cdecl;
assembler;
asm
  pop esi

  pop eax
  pop ebx

  add eax, ebx

  push esi
  ret
end;

begin end.
```asm
mov eax, 0x04  ; в eax записать число
```

```pascal
{$asmmode intel}

var
  a: Byte;

begin
  asm
    mov AL, 42
    mov a, AL
  end;
end.
```

<!-- EAX [                [   AH   |   AL   ]]] -->

EAX - 32 бит
AX - 16 бит
AL, AH - по 8 бит

то же самое для:   
EBX, BX, BH, BL  
ECX, CX, CH, CL
EDX, DX, DH, DL

ESI, EDI, EBP, ESP  
 SI,  DI,  BP,  SP

```
mov AL, 17
mov AX, 300  ; перезапишет! т.к. AX = AH + AL
mov BX, 300  ; норм
```
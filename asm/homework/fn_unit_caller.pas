// uses fn_unit;

// external fake_add; cdecl;
function fake_add(a, b: Int32): Int32; cdecl; external 'fn_unit';

begin
  WriteLn(fake_add(4, 2));
end.
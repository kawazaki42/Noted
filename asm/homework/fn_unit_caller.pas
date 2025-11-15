// uses fn_unit;

// external fake_add; cdecl;
function fake_add(a, b: Int32): Int32; external;

begin
  WriteLn(fake_add(4, 2));
end.
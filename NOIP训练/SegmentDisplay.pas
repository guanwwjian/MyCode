const
hua:array[1..6] of longint=(2,3,4,5,6,7);
shu:array[1..6] of longint=(1,1,1,3,3,1);

var
i,j,k,n:longint;
f:array[0..500000] of longint;
begin
assign(input,'SegmentDisplay.in');reset(input);
assign(output,'SegmentDisplay.out');rewrite(output);
 f[0]:=1;
 readln(n);
 for i:= 1 to n do
  for j:= 1 to 6 do
  begin
  if (i-hua[j])>=0 then
   f[i]:=(f[i]+f[i-hua[j]]*shu[j]) mod 1000000007;
  end;
 writeln(f[n]);
 close(input);
 close(output);
end.

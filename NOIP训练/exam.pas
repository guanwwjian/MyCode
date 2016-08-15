var
i,j,k,n,m:longint;
a,c:array[0..100000,1..5] of double;
f:array[0..100000,1..5] of double;
s:array[0..100000] of double;
tt1,tt2,ans:double;
begin
assign(input,'exam.in');reset(input);
assign(output,'exam.out');rewrite(output);
 readln(n);
 for i:= 1 to n do
  begin
  for j:= 1 to 5 do
   begin
    read(a[i,j]);
   end;
  readln;
  end;
 for i:= 1 to n-1 do
  for j:= 1 to 5 do
   c[i,j]:=a[i+1,j]-a[i,j];

 for i:= 1 to n-1 do
   begin
    tt1:=0;
    for j:= 1 to 5 do
     begin
      f[i,j]:=c[i,j];
      tt1:=tt1+abs(c[i,j]);
     end;
    s[i]:=tt1;
    tt2:=0;
    for j:= 1 to 5 do
     tt2:=tt2+abs(f[i-1,j]+c[i,j]);
    if tt2>tt1 then
     begin
     for j:= 1 to 5 do
      f[i,j]:=f[i-1,j]+c[i,j];
      s[i]:=tt2;
     end;
   end;
 ans:=0;
 for i:= 1 to n-1 do
  begin
   if s[i]>ans then ans:=s[i];
  end;
 writeln(ans:0:2);
close(input);
close(output);
end.

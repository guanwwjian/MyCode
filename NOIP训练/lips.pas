var
ans,i,j,k,n,z:longint;
s:array[1..200] of boolean;
ss:array[1..200] of longint;
f,a:array[0..1000] of longint;
function su(k:longint):boolean;
var
i,j:longint;
 begin
  if k=1 then exit(false);
  if k=2 then exit(true);
  i:=1;
  while ((ss[i]*ss[i])<k) do
   begin
    if (k mod ss[i])=0 then exit(false);
    i:=i+1;
   end;
  exit(true);
 end;
begin
assign(input,'lips.in');reset(input);
assign(output,'lips.out');rewrite(output);
fillchar(s,sizeof(s),true);
s[1]:=false;

for i:= 1 to 200 do
 begin
  if s[i] then
   begin
   j:=1;
    while i*j<=200 do
     begin
      j:=j+1;
      s[i*j]:=false;
     end;
   end;
 end;
 z:=0;
  for i:= 1 to 200 do
   begin
    if s[i] then
     begin
      z:=z+1;
      ss[z]:=i
     end;
   end;

 readln(n);
 for i:= 1 to n do
  read(a[i]);
 readln;
 f[0]:=0;
 ans:=0;
 for i:= 1 to n do
  begin
  for j:= 1 to i-1 do
   begin
    if su(a[i]+a[j])and(f[i]<f[j]+1) then f[i]:=f[j]+1;
   end;
  if ans<f[i] then ans:=f[i];
  end;
 writeln(ans);
close(input);
close(output);
end.

var
i,j,k,n:longint;
b:array[1..12] of longint;
p:array[1..12] of double;
f:array[1..5000] of double;
function ff():double;
var
i,j,l,s,x:longint;
flag,bb:boolean;
tt,tt1:double;
 begin
  tt:=0; bb:=false;
{  for i:= 1 to n do
   if b[i]>1 then
    begin
     bb:=true;
    end;

   if bb then
    begin
    for i:= 1 to n do
     if b[i]>0 then tt:=tt+1;
     exit(tt);
    end;  }
  for i:= 1 to k do
   begin
   s:=0;tt1:=0;
   for j:= 1 to n-i+1 do
    begin
     flag:=true;
     for l:= j to j+i-1 do
      begin
      if b[l]>0 then flag:=false;
      inc(b[l]);
      end;
       if flag  then
        begin
         tt1:=tt1+(ff()*p[i]);
         s:=s+1;
        end;
     for  k:= j to j+i-1 do
      dec(b[l]);
    end;
   if s<>0 then
    tt:=tt+tt1/s
   else
    begin
     for l:= 1 to n do
      x:=0;
      if b[i]>0 then x:=x+1;
     tt:=tt+x*p[i];
    end;
  end;
  exit(tt);
end;

begin
assign(input,'TableSeating.in');reset(input);
assign(output,'TableSeating.out');rewrite(output);
 readln(n,k);
 fillchar(b,sizeof(b),0);
 for i:= 1 to k do
  begin
  read(p[i]);
  p[i]:=p[i]/100;
  end;
 readln;
 writeln(ff:0:2);
close(input);
close(output);
end.

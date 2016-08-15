var
i,j,k,n,m,t,x,y:longint;
chr:char;
f:array[1..30000] of longint;
p,h,o:array[1..30000] of longint;
function find(x:longint):longint;
var
old:longint;
 begin
  if f[x]=x then
   begin
    exit(x);
   end
   else
    begin
     o[x]:=p[f[x]];
     old:=f[x];
     f[x]:=find(x);
     p[x]:=p[x]+p[old]-o[x];
     exit(f[x]);
    end;
 end;
procedure he(x,y:longint);
 begin
  p[find(x)]:=h[find(y)]+1;
  inc(h[find(y)],h[find(x)]);
  f[find(x)]:=find(y);
 end;
begin
assign(input,'galaxy.in');reset(input);
assign(output,'galaxy.out');rewrite(output);
 for i:= 1 to 30000 do
  begin
  f[i]:=i;
  p[i]:=1;
  h[i]:=1;
  end;
 readln(t);
 for i:= 1 to t do
  begin
   read(chr);
   readln(x,y);
   if chr='M' then
    begin
     he(x,y);
    end
   else if chr='C' then
    begin
     if find(x)=find(y) then
      begin
       writeln(abs(p[x]-p[y])-1);
      end
     else writeln(-1);
    end;
  end;
close(input);
close(output);
end.

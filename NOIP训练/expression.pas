const
t:array[1..13] of char=('0','1','2','3','4','5','6','7','8','9','+','-','*');
var
i,j,k,n,m,l,s:longint;
a:array[1..100] of longint;
b,e:array['a'..'z'] of longint;
c,d:array[1..100] of char;
st:string;
begin
assign(input,'expression.in');reset(input);
assign(output,'expression.out');rewrite(output);
 readln(st);
 n:=length(st);
 for i:= 1 to n do
  begin
   if b[st[i]]=0 then
    begin
     inc(s);
     c[s]:=st[i];
     e[st[i]]:=s;
    end;
   a[i]:=e[st[i]];
   inc(b[st[i]]);
  end;
for i:= 1 to s do
 if b[c[i]]=1 then
 begin

 end;
close(input);
close(output);
end.
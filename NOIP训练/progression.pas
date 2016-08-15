var
i,j,k,n,m,a0,q,h:longint;
ans,s,l:double;
a:array[1..100] of longint;
{function zh(x:double):longint;
 begin
  if x>=0 then exit(trunc(x))
   else exit(trunc(x)-1);
 end;}
begin
s:=-maxlongint;
l:=maxlongint;
assign(input,'progression.in');reset(input);
assign(output,'progression.out');rewrite(output);
 readln(a0,n);
 for i:= 1 to n do
  begin
   read(a[i]);
   a[i]:=a[i]-a0;
  end;
 readln;
 for i:= 1 to n do
  begin
   if a[i]/i>s then s:=a[i]/i;
   if (a[i]+1)/i<l then l:=(a[i]+1)/i;
  end;
 if s<l then ans:=s
  else ans:=-1;
 writeln(ans:0:5);


close(input);
close(output);
end.

var
i,j,k,n,m,x,y,ans:longint;
f:array[1..100000,1..2] of longint;
a,s:array[1..100000] of longint;
b:array[1..100000,1..50] of longint;

function ff(x,y,fa:longint):longint;
 var
 i,j,k:longint;
 begin
  if f[x,y]>0 then exit(f[x,y])
   else
    begin
    if y=1 then f[x,y]:=a[x];
     for i:= 1 to s[x] do
      if b[x,i]<>fa then
       begin
       if y=1 then f[x,y]:=f[x,y]+ff(b[x,i],2,x)
        else if ff(b[x,i],1,x)>ff(b[x,i],2,x) then f[x,y]:=f[x,y]+ff(b[x,i],1,x)
         else f[x,y]:=f[x,y]+ff(b[x,i],2,x);
       end;
     exit(f[x,y]);
    end;
 end;
begin
assign(input,'profit.in');reset(input);
assign(output,'profit.out');rewrite(output);
 readln(n);
 for i:= 1 to n do
  begin
   readln(a[i])
  end;
 for i:= 1 to n-1 do
  begin
   readln(x,y);
   inc(s[x]);
   inc(s[y]);
   b[x,s[x]]:=y;
   b[y,s[y]]:=x;
  end;
 ans:=ff(1,1,0);
 if ff(1,2,0)>ans then ans:=ff(1,2,0);
 writeln(ans);


close(input);
close(output);
end.
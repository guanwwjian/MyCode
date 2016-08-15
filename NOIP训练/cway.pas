const
jin=10000;
zero:array[1..4] of longint=(1000,100,10,1);
type
high=record
 a:array[-1..1000] of longint;
 end;
var
i,j,k,n,m,x1:longint;
p:array[1..1000] of high;
tt1,tt2,tt3,ans:high;
procedure add(x,y:high;var z:high);
 var
 i,j,k:longint;
 begin
  for i:=0 to 1000 do
   begin
    z.a[i]:=x.a[i]+y.a[i]+z.a[i-1] div jin;
    z.a[i-1]:=z.a[i-1] mod jin;
   end;
 end;
procedure che(x,y:high;var z:high);
 var
 i,j,k:longint;
 begin
  for i:= 0 to 1000 do
   begin
    z.a[i]:=x.a[i]*y.a[i]+z.a[i-1] div jin;
    z.a[i-1]:=z.a[i-1] mod jin;
   end;
 end;

begin
assign(input,'cway.in');reset(input);
assign(output,'cway.out');rewrite(output);
 readln(n);
  m:=n-2;
  p[1].a[0]:=m;
 for i:= 2 to m do
  begin
  tt1.a[0]:=m-i+1;
  che(p[i-1],tt1,p[i]);
//p[i]:=p[i-1]*(m-i+1);
  end;
 ans.a[0]:=1;
 for i:= 1 to m do
  begin
  add(ans,p[i],ans);
// ans:=ans+p[i];
  end;
  x1:=1000;
 while ans.a[x1]=0 do dec(x1);
 write(ans.a[x1]);
 for i:=x1-1 downto 1 do
  begin
  for j:= 1 to 4 do
   if ((ans.a[i] mod zero[j])=0) then  write(0)
    else
     begin
      write(ans.a[i]);
      break;
     end;
  end;
close(input);
close(output);
end.

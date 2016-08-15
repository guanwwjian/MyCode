const
max=1000000000;
var
i,j,k,n,m,q,i1,i2,i3,i4,a1,a2,a3,a4,b1,b2,b3,b4,x,y,ss:longint;
s:array[0..10000] of longint;
b:array[0..10000] of boolean;
f:array[0..10000]of longint;
v:array[0..10000] of boolean;
function su(x:longint):boolean;
 var
 i,j,k:longint;
 begin

  i:=1;
  while (i<=q)and(s[i]<=sqrt(x)) do
   begin
   if x mod s[i]=0 then exit(false);
   inc(i);
   end;
  exit(true);
 end;
function ff(x,t:longint):longint;
 var
 i,j,k,tt,t1,t2,t3,t4,x1,x2,x3,x4:longint;
 begin
  inc(ss);
  {writeln(ss);}
  tt:=x;
   x1:=x div 1000;
   x2:=x mod 1000 div 100;
   x3:=x mod 100 div 10;
   x4:=x mod 10;
  if f[tt]<>max then exit(f[tt])
   else
    begin
     v[tt]:=true;
     for i:= 0 to 9 do
      begin
       t1:=i*1000+x2*100+x3*10+x4;
       t2:=x1*1000+i*100+x3*10+x4;
       t3:=x1*1000+x2*100+i*10+x4;
       t4:=x1*1000+x2*100+x3*10+i;
       if (i>0)and(b[t1])and not(v[t1]) then
        if ff(t1,t+1)+1<f[tt] then
         f[tt]:=f[t1]+1;
       if b[t2]and not(v[t2]) then
        if ff(t2,t+1)+1<f[tt] then
         f[tt]:=f[t2]+1;
       if b[t3]and not(v[t3]) then
        if ff(t3,t+1)+1<f[tt] then
         f[tt]:=f[t3]+1;
       if b[t4]and not(v[t4]) then
        if ff(t4,t+1)+1<f[tt] then
         f[tt]:=f[t4]+1;
      end;
     v[tt]:=false;
     exit(f[tt]);
    end;
 end;

begin
assign(input,'prime.in');reset(input);
{assign(output,'prime.out');rewrite(output);}
 readln(x,y);

 q:=0;
 b[1]:=false;
 for i:= 2 to 10000 do
  begin
   b[i]:=su(i);
   if b[i] then
    begin
     inc(q);
     s[q]:=i;
    end;
  end;
 for i:= 1 to 10000 do
  f[i]:=max;
 f[x]:=0;
 writeln(ff(y,1));


close(input);
close(output);
end.

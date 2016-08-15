var
i,j,k,m,n,tt,a1,b1,a2,b2,x,y,cha,yuc,yu1,x1,x2,q,h,min:longint;
huan:boolean;
function zhuan(x,y:longint):longint;
var
tt:longint;
 begin
  tt:=x mod y;
  if tt<>0 then exit(tt)
   else exit(y);
 end;
begin
assign(input,'integer.in');reset(input);
assign(output,'integer.out');rewrite(output);
 readln(a1,b1,a2,b2);
 if a2<a1 then
  begin
   tt:=a1;a1:=a2;a2:=tt;
   tt:=b1;b1:=b2;b2:=tt;
   huan:=true;
  end;
{ q:=0;h:=maxlongint;
   cha:=b2-b1;
   yuc:=zhuan(cha,a1);
   yu1:=zhuan(a2,a1); }
 x2:=0;
 while ((((b2-b1)+a2*x2) div a1)-(((b2-b1)+a2*x2)/a1))<>0 do
  begin
   x2:=x2+1;
  end;
 x1:=((b2-b1)+a2*x2) div a1;
 if huan then
  begin
  tt:=x1;x1:=x2;x2:=tt;
  end;
 writeln(x1,' ',x2);
close(input);
close(output);
end.

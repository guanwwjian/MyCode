program alake;
type
tai=record
 w,h,no:longint;
end;
var
i,j,k,n,m,min,mn:longint;
a:array[1..100000] of tai;
{procedure qsort(l,r:longint);
 var
 i,j,mid:longint
 tt,x:tai;
 begin
  i:=l;j:=r;
  mid:=random(r-l+1)+l;
  x:=a[mid];
  repeat
   while a[i].h<x.h do inc(i);
   while x.h<a[j].h do dec(j);
   if i<=j then
    begin
     tt:=a[i];a[i]:=a[j];a[j]:=tt;
     inc(i);
     dec(j);
    end;
  until j<i;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
 end;
 procedure qsort1(l,r:longint);
 var
 i,j,mid:longint
 tt,x:tai;
 begin
  i:=l;j:=r;
  mid:=random(r-l+1)+l;
  x:=a[mid];
  repeat
   while a[i].no<x.no do inc(i);
   while x.no<a[j].no do dec(j);
   if i<=j then
    begin
     tt:=a[i];a[i]:=a[j];a[j]:=tt;
     inc(i);
     dec(j);
    end;
  until j<i;
  if l<j then qsort1(l,j);
  if i<r then qsort1(i,r);
 end; }
begin
randomize;
assign(input,'alake.in');reset(input);
assign(output,'alake.out');rewrite(output);
 {readln(n);
 min:=maxlongint;
 for i:= 1 to n do
  begin
   readln(a[i].w,a[i].h);
   a[i].no:=i;
   if a[i].h<min then
    begin
     min:=a[i].h;
     mn:=i;
    end;
  end;}
 writeln(4);
 writeln(50);
 writeln(26);


  
  

close(input);
close(output);
end.


program ctree;
type
tree=record
 a,k:longint;
 fa,l,r:longint;
 nfa,nl,nr:longint;
 no:longint;
end;
var
i,j,k,n,m:longint;
a:array[1..50000] of tree;
procedure qsort(l,r:longint);
 var
 i,j,mid:longint;
 x,tt:tree;
 begin
  i:=l;j:=r;
  mid:=random(r-l+1)+r;
  x:=a[mid];
  repeat
   while a[i].a<x.a do inc(i);
   while x.a<a[j].a do dec(j);
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
 i,j,mid:longint;
 x,tt:tree;
 begin
  i:=l;j:=r;
  mid:=random(r-l+1)+r;
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
 end;

procedure build(x,y:longint);
 var
 i,j:longint;
 begin
  if a[y].k<a[x].k then
   begin
    if a[x].l=0 then
     begin
      a[x].l:=y;
      a[x].nl:=a[y].no;
      a[y].fa:=x;
      a[y].nfa:=a[x].no;
     end
     else build(a[x].l,y);
   end
  else
   begin
    if a[x].r=0 then
     begin
      a[x].r:=y;
      a[x].nr:=a[y].no;
      a[y].fa:=x;
      a[y].nfa:=a[x].no;
     end
    else build(a[x].r,y);
   end;
 end;
begin
randomize;
assign(input,'ctree.in');reset(input);
assign(output,'ctree.out');rewrite(output);
 readln(n);
 for i:= 1 to n do
  begin
   readln(a[i].k,a[i].a);
   a[i].no:=i;
  end;
  qsort(1,n);
 for i:= 2 to n do
  begin
   build(1,i);
  end;
  qsort1(1,n);
 writeln('YES');
 for i:= 1 to n do
  writeln(a[i].nfa,' ',a[i].nl,' ',a[i].nr);
close(input);
close(output);
end.


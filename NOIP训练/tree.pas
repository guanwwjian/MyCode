type
tree=record
 f,l,r,a:longint;
 left:boolean;
end;
var
i,j,k,n,m,z:longint;
a:array[0..20000] of tree;
flag:boolean;
{t:array[1..20000] of longint;}
procedure find(x,y:longint);
 var
 i,j,k:longint;
 begin
  if a[x].a>a[y].a then
   begin
    a[x].f:=y;
    a[x].left:=false;
    a[y].r:=x;
   end
  else if (a[y].f=0)or((a[x].a>a[a[y].f].a)and not(a[y].left))or((a[x].a<a[a[y].f].a)and a[y].left) then
   begin
    a[x].f:=y;
    a[x].left:=true;
    a[y].l:=x;
   end
  else find(x,a[y].f);
 end;
procedure print(x:longint);
var
i,j,k:longint;
 begin
  if a[x].r<>0 then print(a[x].r);
  if a[x].l<>0 then print(a[x].l);
  if flag then
   begin
    write(a[x].a);
    flag:=false;
   end
   else write(' ',a[x].a);
 end;
begin
assign(input,'tree.in');reset(input);
assign(output,'tree.out');rewrite(output);
 readln(n);
 flag:=true;
 for i:= 1 to n do
  begin
   read(a[i].a);
  end;


 for i:= n-1 downto 1 do
  find(i,i+1);
 print(n);
close(input);
close(output);
end.

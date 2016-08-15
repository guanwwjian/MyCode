const
zhu:array[1..9] of longint=(1,1,1,2,2,2,3,3,3);
var
i,j,k,n,m,tx,ty,max:longint;
a:array[1..10,1..10] of longint;
b:array[1..10,1..10] of boolean;
h,l:array[1..10,0..9] of boolean;
ge:array[1..3,1..3,0..9] of boolean;
procedure che(wei:longint;var x,y:longint);
 begin
  x:=wei mod 9;
  y:=(wei div 9)+1;
  if x=0 then
   begin
    x:=9;
    y:=y-1;
   end;
 end;
{function zhu(x:longint):longint;
 begin
  x:=x mod 3;
  if x=0 then x:=3;
  exit(x);
 end;}
procedure dfs(wei:longint);
var
i,j,k:longint;
x,y,tw:longint;
begin
 tw:=wei;
 che(tw,x,y);
 while not(b[x,y])and(tw<=81) do
  begin
   tw:=tw+1;
   che(tw,x,y);
   if max<tw then max:=tw;
  end;
 if tw>81 then
  begin
   for i:= 1 to 9 do
    begin
     for j:= 1 to 9 do
      write(a[i,j]);
     writeln
    end;
   close(input);
   close(output);
   halt;
  end
 else
  begin
   for i:= 1 to 9 do
    begin
    a[x,y]:=i;
    if h[x,i] and l[y,i] and ge[zhu[x],zhu[y],i] then
     begin
      h[x,i]:=false;
      l[y,i]:=false;
      ge[zhu[x],zhu[y],i]:=false;
      dfs(tw+1);
      h[x,i]:=true;
      l[y,i]:=true;
      ge[zhu[x],zhu[y],i]:=true;
     end;
    end;
  end;
end;
begin
assign(input,'sudoku.in');reset(input);
assign(output,'sudoku.out');rewrite(output);
fillchar(h,sizeof(h),true);
fillchar(l,sizeof(l),true);
fillchar(ge,sizeof(ge),true);
fillchar(b,sizeof(b),true);
 for i:= 1 to 9 do
  begin
   for j:= 1 to 9 do
    begin
     read(a[i,j]);
     if a[i,j]>0 then
      begin
       h[i,a[i,j]]:=false;
       l[j,a[i,j]]:=false;
       ge[zhu[i],zhu[j],a[i,j]]:=false;
       b[i,j]:=false;
      end;
    end;
   readln;
  end;

 dfs(1);
close(input);
close(output);
end.

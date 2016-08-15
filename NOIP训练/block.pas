type
zhan=record
 a:longint;
 b:ansistring;
end;
var
i,j,k,n,m:longint;
zh:array[0..50] of zhan;
ans:ansistring;
function try(x:longint):ansistring;
var
tt1,l:longint;
str:ansistring;
 begin
 str:=zh[x].b;
 zh[x].a:=1;
 for i:= 1 to length(str) do
  begin
   if str='(' then
    begin
     l:=1;
     for j:= i+1 to length(str) do
      begin
       if str[j]='(' then l:=l+1;
       if str[j]=')' then l:=l-1;
       if l=0 then break;
       if (l=1)and(str[j]=',') then tt1:=j;
      end;
     break;
    end;
  end;
  val(copy(str,i+1,tt1-(i+1)),zh[x].a);
  zh[x+1].b:=copy(str,tt1+1,j-(tt1+1));
  zh[x].b:=try(x+1);
  str:=zh[x].b;
  for i:= 2 to zh[x].a do
   str:=str+zh[x].b;
  exit(str);
 end;
begin
assign(input,'block.in');reset(input);
assign(output,'block.out');rewrite(output);
 readln(zh[0].b);
 ans:=try(0);
 writeln(ans);
close(input);
close(output);
end.

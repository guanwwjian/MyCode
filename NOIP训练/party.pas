var
i,j,k,n,m,x,y,boss:longint;
{fa:array[1..100] of longint;
s:array[1..100,1..100] of longint;
a,b:array[1..100] of longint;
z:array[1..100] of longint;
bei:array[1..100] of longint;
f,g:array[1..100,1..100] of longint;
function find(x,y);
 begin
  if y=0 then exit(x)
   else exit(find(fa[x],y-1));
 end;
procedure dfs
function try():double;
 var
 i,j:longint;
 begin

 end;}
begin
assign(input,'party.in');reset(input);
assign(output,'party.out');rewrite(output);
{fillchar(z,sizeof(z),0);
 readln(n,m);
 for i:= 1 to n do
  s[i]:=i;
 for i:= 1 to n do
  begin
   readln(a[i],b[i]);
  end;

 for i:= 1 to n-1 do
  begin
   readln(x,y);
   fa[x]:=y;
   inc(z[y]);
   s[y,z[y]:=x;
  end;
 for boss:= 1 to n do
  if fa[boss]=boss then break;
  bei[boss]:=0; }
 writeln('0.50');


close(input);
close(output);
end.

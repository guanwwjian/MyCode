var
i,j,k,n,m,x,ans:longint;
a:array[1..9] of longint;
b:array[1..9] of longint;
h,l:array[1..3] of longint;
procedure dfs(x:longint);
 var
 i,j,k:longint;
 flag:boolean;
 begin
  if x>9 then
   begin
    flag:=true;
    h[1]:=b[1]+b[2]+b[3];
    h[2]:=b[4]+b[5]+b[6];
    h[3]:=b[7]+b[8]+b[9];
    l[1]:=b[1]+b[4]+b[7];
    l[2]:=b[2]+b[5]+b[8];
    l[3]:=b[3]+b[6]+b[9];
    for i:= 2 to 3 do
     if h[i]<>h[1] then flag:=false;
    for i:= 1 to 3 do
     if l[i]<>h[1] then flag:=false;
    if flag then
     inc(ans);
   end
  else
   begin
    for i:= 1 to 9 do
     if a[i]>0 then
      begin
       dec(a[i]);
       b[x]:=i;
       dfs(x+1);
       inc(a[i]);
      end;
   end;
 end;
begin
assign(input,'MNS.in');reset(input);
assign(output,'MNS.out');rewrite(output);
 fillchar(a,sizeof(a),0);
 ans:=0;
 for i:= 1 to 9 do
  begin
  read(x);
  inc(a[x]);
  end;
 dfs(1);
 writeln(ans);
close(input);
close(output);
end.

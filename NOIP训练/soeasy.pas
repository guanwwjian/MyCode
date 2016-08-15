var
i,j,k,n,m,ans,con:longint;
f,c:array[0..1000,0..1000] of longint;
v,w:array[1..1000] of longint;
begin
assign(input,'soeasy.in');reset(input);
assign(output,'soeasy.out');rewrite(output);
fillchar(f,sizeof(f),130);
 readln(n,m);
 ans:=0;
 for i:= 0 to n do
  begin
  f[i,0]:=0;
  c[i,0]:=1;
  end;
 for i:= 1 to n do
  readln(v[i],w[i]);
 for i:= 1 to n do
  for j:= 1 to m do
   begin
    f[i,j]:=f[i-1,j];
    c[i,j]:=c[i-1,j];
    if (j-v[i]>=0) then
     begin
     if f[i,j]<f[i-1,j-v[i]]+w[i] then
      begin
      f[i,j]:=f[i-1,j-v[i]]+w[i];
      c[i,j]:=c[i-1,j-v[i]];
      end
      else if f[i,j]=f[i-1,j-v[i]]+w[i] then
       begin
        c[i,j]:=c[i,j]+c[i-1,j-v[i]];
       end;
     end;
    if f[i,j]>ans then ans:=ans+1;
   end;
  con:=0;
  for i:= 1 to m do
   begin
    if f[n,i]=ans then con:=con+c[n,i];
   end;
  writeln(ans);
  writeln(con);
 close(input);
 close(output);
end.

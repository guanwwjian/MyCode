const
 jin=10000;
 hl=100;
type
high=array[-1..hl] of longint;
var
i,j,jj,k,ii,kk,n,m,tt,x:longint;
f:array[0..50,0..50,-1..hl] of longint;
ans:array[-1..hl] of longint;
{procedure zhuan(x:high;y:longint;a:high;var z:high);
 var
 i,j:longint;
 begin
  for i:=0 to hl do
   begin
    z[i]:=x[i]*y+a[i]+z[i-1] div jin;
    z[i-1]:=z[i-1] mod jin;
   end;
 end;}
begin
assign(input,'rook.in');reset(input);
assign(output,'rook.out');rewrite(output);
fillchar(f,sizeof(f),0);
 readln(n,k);
 for i:= 0 to n do
  f[i,0,0]:=1;
 if k>n then  writeln(0)
  else
   begin
    for i:= 1 to n do
     for j:= 1 to k do
      begin
         for jj:=0 to hl do
           begin
            f[i,j,jj]:=f[i-1,j-1,jj]*(n-j+1)+f[i-1,j,jj]+f[i,j,jj-1] div jin;
            f[i,j,jj-1]:=f[i,j,jj-1] mod jin;
           end;
       {zhuan(f[i-1,j-1],n-j+1,f[i-1,j],f[i,j])}
       {f[i,j]:=f[i-1,j-1]*(n-j+1)+f[i-1,j];}
      end;
    ans:=f[n,k];
    tt:=hl;
    while ans[tt]=0 do dec(tt);
    write(ans[tt]);
    for ii:=tt-1 downto 0 do
     begin
      x:=jin;
      for kk:= 1 to 3 do
       begin
        x:=x div 10;
        if (ans[ii] div x)=0 then write(0);
       end;
      write(ans[ii]);
     end;
    writeln;
   end;
close(input);
close(output);
end.

var
i,j,k,n,m,k1,k2,k3,t1,t2,t3:longint;
a:array[1..50,1..50] of boolean;
b:array[1..50] of boolean;
s:array[false..true,1..50] of longint;
c:char;
procedure dfs(dep:longint);
var
i,j,kk1,kk2,kk3:longint;
l,t1,t2:boolean;
 begin
  if dep<=m then
   begin
    for l:= false to true do
     begin
      b[dep]:=l;
      if (s[not(l),dep]<=(n-k1))and(s[l,dep]<=(n-k2)) then
       dfs(dep+1);
     end;
   end
   else
   begin
    kk1:=0;kk2:=0;kk3:=0;
    for i:= 1 to n do
     begin
      t1:=true;t2:=true;
      for j:= 1 to m do
       begin
        if a[i,j]=b[j] then t2:=false
         else t1:=false;
       end;
      if t1 then kk1:=kk1+1
       else if t2 then kk2:=kk2+1
        else kk3:=kk3+1;
      if not((kk1<=k1)and(kk2<=k2)and(kk3<=k3)) then exit
       else if (kk1=k1)and(kk2=k2)and(kk3=k3) then
        begin
         for i:= 1 to m do
          if b[i] then write('Y')
           else write('N');
          writeln;
          close(input);
          close(output);
          halt;
        end;
     end;
   end;
 end;


begin
assign(input,'BestJob.in');reset(input);
assign(output,'BestJob.out');rewrite(output);
 readln(n,m,k1,k2);
 k3:=n-k1-k2;
 for i:= 1 to n do
  begin
   for j:= 1 to m do
    begin
     read(c);
     if c='Y' then
       begin
        s[true,j]:=s[true,j]+1;
        a[i,j]:=true;
       end
      else
       begin
        s[false,j]:=s[false,j]+1;
        a[i,j]:=false;
       end;
    end;
   readln;
  end;

  dfs(1);
  writeln(-1);
 close(input);
 close(output);
end.

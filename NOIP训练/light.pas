var
i,j,k,m,n,x:longint;
a:array[1..100,1..100] of longint;
b:array[1..100] of boolean;
d:array[1..100] of longint;
c:array[1..100] of longint;
procedure dfs(wei,x,y:longint);
 var
 i,j,k:longint;
 flag:boolean;
 begin
   if (y-x<m-wei) then
      begin
       b[wei]:=false;
       dfs(wei+1,x,y);
      end;
   if x<y then
      begin
       b[wei]:=true;
       dfs(wei+1,x+1,y)
      end;
   if wei=m then
     begin
      c:=d;
      for i:= 1 to m do
       if b[i] then
        for j:= 1 to n do
        begin
         c[j]:=c[j]+a[i,j];
        end;
       flag:=true;
      for i:= 1 to n do
       begin
        c[i]:=c[i] mod 2;
        if c[i]=0 then flag:=false;
       end;
      if flag then
       begin
        writeln(y);
        for i:= 1 to m do
         if b[i] then
          begin
          if flag then
           begin
            write(i);
            flag:=false;
           end
           else
            begin
             write(' ',i);
            end;
          end;
         close(input);
         close(output);
         halt;
       end;
     end;
 end;
begin
assign(input,'light.in');reset(input);
assign(output,'light.out');rewrite(output);
 readln(n,m);
 for i:= 1 to m do
  begin
  for j:= 1 to n do
   read(a[i,j]);
  readln;
  end;
  for i:= 1 to n do
   begin
    read(d[i]);
   end;

 for i:= 1 to m do
  begin
   dfs(1,0,i)
  end;
close(input);
close(output);
end.

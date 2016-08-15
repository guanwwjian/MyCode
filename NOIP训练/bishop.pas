var
i,j,k,n,m:longint;
ans,s,mu,zi,y:qword;
he:array[2..100] of boolean;
procedure dfs(cha,h:longint);
 var
 i,j:longint;
 begin
 if cha>(n-1) then
  begin
   if h=k then s:=s+1;
  end
 else
  begin
  if (n-1-cha)>=(k-h) then dfs(cha+1,h);
   if h<k then
    begin
      for i:= 1 to n do
       begin
        if ((i+cha)>=1)and((i+cha)<=n) then
        if he[i+i+cha] then
         begin
          he[i+i+cha]:=false;
          dfs(cha+1,h+1);
          he[i+i+cha]:=true;
         end;
       end;
   end;
  end;
 end;
function yue(x,y:qword):qword;
 begin
  if y=0 then exit(x)
   else exit(yue(y,x mod y));
 end;
begin
assign(input,'bishop.in');reset(input);
assign(output,'bishop.out');rewrite(output);
fillchar(he,sizeof(he),true);
 readln(n,k);
 if (k>n*2-1) then ans:=0
  else
   begin
    s:=0;
    dfs(-(n-1),0);
    ans:=s;
    {zi:=1;
    mu:=1;
    for i:= k downto 1 do
     begin
      zi:=zi*(n*2-1-k+i);
      mu:=mu*i;
      y:=yue(zi,mu);
      zi:=zi div y;
      mu:=mu div y;
     end;
    ans:=s* zi div mu;}
   end;
 writeln(ans);

close(input);
close(output);
end.

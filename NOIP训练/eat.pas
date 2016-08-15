var
i,j,k,n,m,ans,d,x,y:longint;
f,e,b:array[0..100000] of longint;
function find(x:longint):longint;
 var
 i,j:longint;
 begin
  if f[x]=x then exit(x)
   else
    begin
     f[x]:=find(f[x]);
     exit(f[x]);
    end;
 end;

begin
assign(input,'eat.in');reset(input);
assign(output,'eat.out');rewrite(output);
 ans:=0;
 readln(n,k);
 for i:= 1 to k do
  f[i]:=i;
 for i:= 1 to k do
  begin
   readln(d,x,y);
   if (x>n)or(y>n)or((d=2)and(y=x)) then ans:=ans+1
   else if d=1 then
    begin
     if ((e[find(x)]=0)and(b[find(x)]=0))or((e[find(y)]=0)and(b[find(y)]=0))or((find(e[find(x)])=find(e[find(y)]))and(find(b[find(x)])=find(b[find(y)]))) then
      begin
       if (e[find(x)]<>0)or(b[find(x)]<>0) then
        begin
         e[find(y)]:=find(e[find(x)]);
         b[find(y)]:=find(b[find(x)]);
        end;
       f[find(x)]:=find(y);
      end
     else ans:=ans+1;
    end
   else if d=2 then
    begin
     if (find(e[find(x)])=find(b[find(x)]))and(find(e[find(x)])<>0)  then ans:=ans+1
      else
      begin
      if (((find(e[find(x)])=find(y))or((e[find(x)]=0)))and((find(x)=find(b[find(y)]))or(b[find(y)]=0))) then
       begin
        e[find(x)]:=find(y);
        b[find(y)]:=find(x);
       end
       else if (find(e[find(y)])=0)and(find(b[find(y)])=0) then
        begin
         f[find(y)]:=find(e[find(x)]);
        end
      else ans:=ans+1;
      end;
    end;
  end;
 writeln(ans);
close(input);
close(output);
end.

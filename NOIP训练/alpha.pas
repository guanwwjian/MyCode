var
i,j,k,n,m,la,lb,lc,s:longint;
x:array['A'..'Z'] of longint;
jin:array[0..26] of longint;
u:array[0..26] of boolean;
a,b,c:string;
ch:char;
procedure dfs(wei:longint);
var
i,j,k:longint;
q,w,e,tt,ci,cj:char;
begin
q:=a[wei];w:=b[wei];e:=c[wei];
if wei>0 then
 begin
if (x[q]=-1)and(x[w]<>-1) then
 begin
  tt:=w;w:=q;q:=tt;
 end;
 if (x[q]=-1)and(x[w]=-1)and(x[e]=-1) then
  begin
   for i:= 0 to n-1 do
    for j:= 0 to n-1 do
     if (i<>j)and(u[i])and(u[j]) then
      begin
       u[i]:=false;
       u[j]:=false;
       x[q]:=i;
       x[w]:=j;
       x[e]:=x[q]+x[w]+jin[wei];
       if u[x[e] mod n] then
       begin
        u[x[e] mod n]:=false;
        jin[wei-1]:=x[e] div n;
        x[e]:=x[e] mod n;
        dfs(wei-1);
        u[x[e] mod n]:=true;
        jin[wei-1]:=0;
       end;
       u[i]:=true;
       u[j]:=true;
       x[q]:=-1;x[w]:=-1;x[e]:=-1;
      end;
  end
  else if (x[q]=-1)and(x[w]=-1)and(x[e]<>1) then
   begin
    for i:= 0 to n-1 do
     if u[i] then
     begin
      x[q]:=i;
      x[w]:=x[e]-jin[wei]-x[q];
      u[i]:=false;
      if u[(x[w]+n) mod n] then
       begin
        if x[w]<0 then
         begin
          x[w]:=x[w]+n;
          jin[wei-1]:=1;
         end;
        u[x[w]]:=false;
        dfs(wei-1);;
        u[x[w]]:=true;
        jin[wei-1]:=0;
       end;
        x[w]:=-1;
        x[q]:=-1
     end;
   end
    else if (x[q]<>-1)and(x[w]=-1)and(x[e]=-1) then
      begin
       for i:= 0 to n-1 do
        if u[i] then
         begin
          u[i]:=false;
          x[w]:=i;
          x[e]:=x[q]+x[w]+jin[wei];
          jin[wei-1]:=x[e] div n;
          x[e]:=x[e] mod n;
          if u[x[e]] then
           begin
            u[x[e]]:=false;
            dfs(wei-1);
            u[x[e]]:=true;
           end;
          jin[wei-1]:=0;
          x[w]:=-1;
          x[e]:=-1;
          u[i]:=true;
         end;
      end
     else if (x[q]<>-1)and(x[w]<>-1)and(x[e]=-1) then
      begin
        x[e]:=x[q]+x[w]+jin[wei];
          jin[wei-1]:=x[e] div n;
          x[e]:=x[e] mod n;
          if u[x[e]] then
           begin
            u[x[e]]:=false;
            dfs(wei-1);
            u[x[e]]:=true;
           end;
          jin[wei-1]:=0;
          x[e]:=-1;
      end
      else if (x[q]<>-1)and(x[w]=-1)and(x[e]<>-1) then
       begin
        x[w]:=x[e]-jin[wei]-x[q];
      if u[(x[w]+n) mod n] then
       begin
        if x[w]<0 then
         begin
          x[w]:=x[w]+n;
          jin[wei-1]:=1;
         end;
        u[x[w]]:=false;
        dfs(wei-1);
        u[x[w]]:=true;
        jin[wei-1]:=0;
       end;
        x[w]:=-1;
      end
      else if (x[q]<>-1)and(x[w]<>-1)and(x[e]<>-1) then
       begin
        if ((x[q]+x[w]+jin[wei]) mod n)=x[e] then
         begin
          jin[wei-1]:=(x[q]+x[w]+jin[wei]) div n;
          dfs(wei-1);
          jin[wei-1]:=0;
         end;
       end;
   end
   else
    begin
     if jin[0]=0 then
      begin
       write(x['A']);
       for ci:= 'B' to chr(ord('A')+n-1) do
        write(' ',x[ci]);
       writeln;
       close(input);
       close(output);
       halt;
      end;
    end;
end;
begin
assign(input,'alpha.in');reset(input);
assign(output,'alpha.out');rewrite(output);
fillchar(u,sizeof(u),true);
 for ch:='A' to 'Z' do
  x[ch]:=-1;

 readln(n);
 readln(a);
 readln(b);
 readln(c);
 la:=length(a);
 lb:=length(b);
 lc:=length(c);
 dfs(la);

close(input);
close(output);
end.

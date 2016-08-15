var
i,j,k,n,m,s,ans,s1,s2,s3,s4:longint;
a,c:array[1..2000] of longint;

begin
assign(input,'road.in');reset(input);
assign(output,'road.out');rewrite(output);
 readln(n);
 ans:=maxlongint;
 for i:= 1 to n do
  begin
   readln(a[i]);
  end;
  s:=0;
 if a[1]>a[2] then
  begin
   s:=s+a[1]-a[2];
  end;
 for i:= 2 to n do
  begin
   if a[i]>a[i+1] then
    begin
     s:=s+a[1]-a[2];
    end;
  end;
 if ans<s then ans:=s;
 s:=0;
{ if a[1]<a[2] then
  begin
   s:=s+a[1]-a[2];
  end;
 for i:= 2 to n do
  if a[i]<a[i+1] then
   begin
    s:=s+a[2]-a[1];
   end;
 if ans<s then ans:=s;

  s:=0;
 if a[n]>a[n-1] then
  begin
   s:=s+a[n]-a[n-1];
  end;
 for i:= n-1 downto 1 do
  if a[i]>a[i-1] then
   begin
    s:=s+a[i]-a[i-1];
   end;
 if ans<s then ans:=s;

  s:=0;
 if a[1]<a[2] then
  begin
   s:=s+a[1]-a[2];
  end;
 for i:= 2 to n do
  if a[i]<a[i+1] then
   begin
    s:=s+a[2]-a[1];
   end;
 if ans<s then ans:=s; }
s1:=0;s2:=0;s3:=0;s4:=0;
 for i:= 1 to n do
  begin
   if i<n then
    begin
     if a[i]<a[i+1] then s1:=s1+a[i+1]-a[i];
     if a[i]>a[i+1] then s2:=s2+a[i]-a[i+1];
    end;
{   if i>1 then
    begin
     if a[i]<a[i-1] then
    end;}
  end;
 ans:=s1;
 if s2<ans then ans:=s2;
 writeln(ans);
close(input);
close(output);
end.

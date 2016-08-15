program card;
{$M 65566000,65566000}
 const
  MXN=10000000;
 var
  a:array[1..MXN] of longint;
  t:array[1..MXN] of boolean;
  fs:array[1..MXN] of longint;
  ii,i,n,m,tn:longint;
 procedure ws();
  var
   i,num,even:longint;
  begin
   num:=1;even:=n>>1;
   while not t[num] do
    begin
     inc(tn);fs[tn]:=num;
     t[num]:=true;
     if odd(num) then
      begin
       num:=(num+1)>>1+even;
      end
     else
      begin
       num:=num>>1;
      end;
    end;
  end;
 begin
  assign(input,'card.in');
  assign(output,'card.out');
  reset(input);rewrite(output);
  readln(n,m);tn:=0;
  ws;
  m:=m mod tn;
  if m=0 then m:=tn;
  writeln(fs[tn-m+1]);
  close(input);close(output);
 end.

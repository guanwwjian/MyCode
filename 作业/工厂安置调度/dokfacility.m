clear all
fid=fopen('test.txt','w');
locs={'cap71.txt','cap72.txt','cap73.txt','cap74.txt','cap101.txt','cap102.txt','cap103.txt','cap104.txt','cap131.txt','cap132.txt'};
ks={15,10,5};
%{
for i=1:10
    out=locs{i}
    fprintf(fid,out);
    for j=1:3
        i
        j
        ta=kfacility(locs{i},ks{j})
        a(i*3+j-3)=ta;
        
    end;
end;
%}
for i=1:10
    out=locs{i}
    fprintf(fid,out);
    for j=1:3
        a(i*3+j-3)=kfacility(locs{i},ks{j});
    end;
    out=['00:p固定 不比较']
    fprintf(fid,out);
    fprintf(fid,'\n\r');
    for j=1:3
        [cost,res]=a(i*3+j-3).multical(1,1,0);
        out=['k=',num2str(ks{j}),'时cost=',num2str(cost)]
        fprintf(fid,out);
        fprintf(fid,'\n\r');
    end;
    ['01:p固定 比较']
    fprintf(fid,out);
    fprintf(fid,'\n\r');
    for j=1:3
        [cost,res]=a(i*3+j-3).multical(1,1,1);
        out=['k=',num2str(ks{j}),'时cost=',num2str(cost)]
        fprintf(fid,out);
        fprintf(fid,'\n\r');
    end;
    ['10:p不固定 不比较']
    fprintf(fid,out);
    fprintf(fid,'\n\r');
    for j=1:3
        [cost,res]=a(i*3+1-3).multical(1,j,0);
        out=['p=',num2str(j),'时cost=',num2str(cost)]
        fprintf(fid,out);
        fprintf(fid,'\n\r');
    end;
    ['11:p不固定 比较']
    fprintf(fid,out);
    fprintf(fid,'\n\r');
    for j=1:3
        [cost,res]=a(i*3+1-3).multical(1,j,1);
        out=['p=',num2str(j),'时cost=',num2str(cost)]
        fprintf(fid,out);
        fprintf(fid,'\n\r');
    end;
end;
fclose(fid); 
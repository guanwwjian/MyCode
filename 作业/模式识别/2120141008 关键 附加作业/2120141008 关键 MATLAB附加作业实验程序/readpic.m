function [ xi ] = readpic( filename )
    pic=imread(filename);
    if (ndims(pic)==3) gray=rgb2gray(pic);
    else gray=pic;
    end;
    dougray=im2double(gray);
    s=size(dougray);
    xi=[];
    for i=1:s(1)
        xi=[xi,dougray(i,:)];
    end;
end


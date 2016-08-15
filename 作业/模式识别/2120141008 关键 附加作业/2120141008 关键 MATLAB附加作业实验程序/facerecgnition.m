function [] = facerecgnition()
    clc;  
    clear;  
    close all; 
    X=[];
    Y=[];
    [X,Y]=addclass(X,Y,'pos','*.jpg',1);
    [X,Y]=addclass(X,Y,'neg','*.jpg',-1);
    rate=testsvm(X,Y,10);   
    ['正确率为：',num2str(rate*100),'%']
end


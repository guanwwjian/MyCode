function rate = testsvm( X,Y,k )
    [row,count]=size(Y);
    correct=0;
    testcount=0;
    for i=1:k
        c=fix(count/k);
        l=1+c*(i-1);
        r=c*i;
        if (r>count) r=count;end;
        trainX=[X(1:l-1,:);X(r+1:count,:)];
        Y1=Y(1:l-1);
        Y2=Y(r+1:count);
        trainY=[Y1,Y2];
        testX=X(l:r,:);
        testY=Y(l:r);
        svm=svmtrain(trainX,trainY,'kernel_function','rbf','RBF_Sigma',5);
        ansY=svmclassify(svm,testX);
        [row,col]=size(testY);
        for j=1:col
            if (ansY(j)==testY(j))
                correct=correct+1;
            end;
            testcount=testcount+1;
        end;
    end;
    rate=correct/testcount;
end


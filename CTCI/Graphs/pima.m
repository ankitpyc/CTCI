addpath('../libsvm-3.22/matlab');
addpath('../libsvm-3.22/matlab/Gridsearch');
dirData = '../libsvm-3.22'; 
addpath(dirData);
[pima_label, pima_inst] = libsvmread(fullfile('../pima'));
[N D] = size(pima_inst);

%  train and test split
trainIndex = zeros(N,1); trainIndex(1:400) = 1;
testIndex = zeros(N,1); testIndex(401:N) = 1;
trainData = pima_inst(trainIndex==1,:);
trainLabel = pima_label(trainIndex==1,:);
testData = pima_inst(testIndex==1,:);
testLabel = pima_label(testIndex==1,:);
% parameters for C and 
C = [0.0001,10.001,0.01,0.1]
%only if the kernel is Gaussian or RBF
G = [0.0001,10.001,0.01,0.1]
[X,Y] = meshgrid(C,G);
[m,n] = size(X);
cg = zeros(m,n);
%% record acc with different c & g,and find the bestacc with the smallest c
bestc = 0;
bestg = 0;
bestacc = 0;
basenum = 1;
for i = 1:m
    for j = 1:n
        cmd = ['-t 2  -v 2',' -c ',num2str(X(i,j) ),' -g ',num2str(Y(i,j) ),' -q -t 0'];
        cg(i,j) = svmtrain(trainLabel, trainData, cmd);

        if cg(i,j) > bestacc
            bestacc = cg(i,j);
            bestc = X(i,j);
            bestg = Y(i,j);
        end
        if ( cg(i,j) == bestacc && bestc > basenum^X(i,j) )
            bestacc = cg(i,j);
            bestc = X(i,j);
            bestg = Y(i,j);
        end

    end
end

fprintf('the best value of c is %i\n', bestc)
fprintf('the best value of g is %i\n', bestg)
fprintf('the best accuracy of  is %i\n', bestacc)
% ================================
% ===== Showing the results ======
% ================================
cmd = ['-t 0 -v 2',' -c ',num2str(bestc),' -g ',num2str(bestg ),' -q -t 0'];
best_model = svmtrain(trainLabel,trainData,cmd);
[predict_label, accuracy, prob_values] = svmpredict(testLabel, testData, best_model, '-b 1'); % run the SVM model on the test data

% Assign color for each class
% colorList = generateColorList(2); % This is my own way to assign the color...don't worry about it
colorList = prism(100);

% true (ground truth) class
trueClassIndex = zeros(N,1);
trueClassIndex(pima_label==1) = 1; 
trueClassIndex(pima_label==-1) = 2;
colorTrueClass = colorList(trueClassIndex,:);
% result Class
resultClassIndex = zeros(length(predict_label),1);
resultClassIndex(predict_label==1) = 1; 
resultClassIndex(predict_label==-1) = 2;
colorResultClass = colorList(resultClassIndex,:);

% Reduce the dimension from 13D to 2D
distanceMatrix = pdist(pima_inst,'euclidean');
newCoor = mdscale(distanceMatrix,2);

% Plot the whole data set
x = newCoor(:,1);
y = newCoor(:,2);
patchSize = 30; %max(prob_values,[],2);
colorTrueClassPlot = colorTrueClass;
figure; scatter(x,y,patchSize,colorTrueClassPlot,'filled');
title('whole data set');

% Plot the test data
x = newCoor(testIndex==1,1);
y = newCoor(testIndex==1,2);
patchSize = 80*max(prob_values,[],2);
colorTrueClassPlot = colorTrueClass(testIndex==1,:);
figure; hold on;
scatter(x,y,2*patchSize,colorTrueClassPlot,'o','filled'); 
scatter(x,y,patchSize,colorResultClass,'o','filled');
% Plot the training set
x = newCoor(trainIndex==1,1);
y = newCoor(trainIndex==1,2);
patchSize = 30;
colorTrueClassPlot = colorTrueClass(trainIndex==1,:);
scatter(x,y,patchSize,colorTrueClassPlot,'o');
title('classification results');
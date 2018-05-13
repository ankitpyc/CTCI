[pima_label, pima_inst] = libsvmread(fullfile(dirData,'pima'));
[N D] = size(pima_inst);

% Determine the train and test index
trainIndex = zeros(N,1); trainIndex(1:400) = 1;
testIndex = zeros(N,1); testIndex(401:N) = 1;
trainData = pima_inst(trainIndex==1,:);
trainLabel = pima_label(trainIndex==1,:);
testData = pima_inst(testIndex==1,:);
testLabel = pima_label(testIndex==1,:);

% Train the SVM
model = svmtrain(trainLabel, [(1:400)' trainData*trainData'], '-c 1 -g 0.07 -b 1');
% Use the SVM model to classify the data
[predict_label, accuracy, prob_values] = svmpredict(testLabel, [(1:70)' testData*trainData'], model, '-b 1'); % run the SVM model on the test data



% ================================
% ===== Showing the results ======
% ================================

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
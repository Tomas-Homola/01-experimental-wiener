%%
a = csvread('test.csv');

figure
plot(a(:,1), a(:,2), '-')
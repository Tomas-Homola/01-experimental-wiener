%%
data100 = readmatrix('data100.csv');
data1000 = readmatrix('data1000.csv');
data10000 = readmatrix('data10000.csv');

% kontrolovat hodnoty pri poziciach 101, 201 a 301
%% 100 trajektorii
[count, ~] = size(data100);
count = count - 1;
figure
hold on
for n = 2:count
	plot(data100(1,:), data100(n,:), '-')
end
hold off

%mean_ = mean(data10000(2:end,2));
%std_ = std(data10000(2:end,2));
%dispersion_ = var(data10000(2:end,2));
%% 1000 trajektorii
[count, ~] = size(data1000);
count = count - 1;
figure
hold on
for n = 2:count
	plot(data1000(1,:), data1000(n,:), '-')
end
hold off

%% 10,000 trajektorii
[count, ~] = size(data10000);
count = count - 1;
figure
hold on
for n = 2:count
	plot(data10000(1,:), data10000(n,:), '-')
end
hold off

%%
sample = readmatrix('dataSample.csv');
sample = sample(1:end-1);
%%
mean_ = mean(sample);
std_ = std(sample);
varience_ = var(sample);
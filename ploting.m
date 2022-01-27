%%
data100 = readmatrix('data100.csv');
data1000 = readmatrix('data1000.csv');
data10000 = readmatrix('data10000.csv');

%% 100 trajektorii
[count, ~] = size(data100);
count = count - 1;
figure
hold on
for n = 2:count
	plot(data100(1,:), data100(n,:), '.-')
end
hold off

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
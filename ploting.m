% W_1 < W_3 && W_3 > W_2
EPSILON = 0.000001;
markerType = '.';
lineType = '-';
colorSuitable = '#00AD33';
colorUnsuitable = '#BBBBBB';
%% Nacitanie dat
data100 = readmatrix('data100.csv');
data1000 = readmatrix('data1000.csv');
data10000 = readmatrix('data10000.csv');

% najdenie W_1, W_2 a W_3 indexov, kedze aj pre data1000 aj data10000 je
% rovnake rozdelenie casovej osi, tak staci tieto hodnoty najst raz na
% zaciatku a potom by mali byt rovnake pre vsetky 3 subory
w1 = find(abs(data100(1,:) - 1.0) < EPSILON, 1);
w2 = find(abs(data100(1,:) - 2.0) < EPSILON, 1);
w3 = find(abs(data100(1,:) - 3.0) < EPSILON, 1);
%% 100 trajektorii
% zistenie poctu trajektorii
[count, ~] = size(data100);
count = count - 1; % minus prvy riadok, kde je ulozena casova os

% najdenie vyhovujucich trajektorii a ich celkovy pocet
suitable = (data100(2:end, w1) < data100(2:end, w3)) ...
	& (data100(2:end, w3) > data100(2:end, w2));
suitableCount = nnz(suitable);

%% Vykreslenie pre 100 trajektorii
figure('Name', '100 trajectories', 'NumberTitle', 'off');
title('100 trajectories of Wiener process', ...
	append('Suitable trajectories: ', int2str(suitableCount), '/', int2str(count), ...
	', Pr = ', num2str(suitableCount/count)));
xlabel('Time', 'FontSize', 20)
ylabel('W(ω,t)', 'FontSize', 20)
hold on
for n = 2:count
	if (suitable(n-1)) % ak ide o vyhovujucu trajektoriu ...
		plot(data100(1, :), data100(n, :), ...
			lineType, 'color', colorSuitable, 'LineWidth', 1);
	else % ... alebo nevyhovujucu trajektoriu
		plot(data100(1, :), data100(n, :), ...
			lineType, 'color', colorUnsuitable, 'LineWidth', 0.1);
	end
end
hold off

%% Vykreslenie nahodneho vektora
figure('Name', '100 trajectories', 'NumberTitle', 'off');
title('Random vector (W_{1}, W_{2})')
xlabel('W(ω,1)', 'FontSize', 20)
ylabel('W(ω,2)', 'FontSize', 20)
grid on
hold on
for n = 2:count
	if (suitable(n-1)) % ak ide o vyhovujucu trajektoriu ...
		plot(data100(n, w1), data100(n, w2), ...
			markerType, 'color', colorSuitable, 'MarkerSize', 25);
	else % ... alebo nevyhovujucu trajektoriu
		plot(data100(n, w1), data100(n, w2), ...
			markerType, 'color', colorUnsuitable, 'MarkerSize', 20);
	end
end
hold off

%% 1000 trajektorii
% zistenie poctu trajektorii
[count, ~] = size(data1000);
count = count - 1; % minus prvy riadok, kde je ulozena casova os

% najdenie vyhovujucich trajektorii a ich celkovy pocet
suitable = (data1000(2:end, w1) < data1000(2:end, w3)) ...
	& (data1000(2:end, w3) > data1000(2:end, w2));
suitableCount = nnz(suitable);

%% Vykreslenie pre 1,000 trajektorii
figure('Name', '1,000 trajectories', 'NumberTitle', 'off');
title('1,000 trajectories of Wiener process', ...
	append('Suitable trajectories: ', int2str(suitableCount), '/', int2str(count), ...
	', Pr = ', num2str(suitableCount/count)));
xlabel('Time', 'FontSize', 20)
ylabel('W(ω,t)', 'FontSize', 20)
hold on
for n = 2:count
	if (suitable(n-1)) % ak ide o vyhovujucu trajektoriu ...
		plot(data1000(1, :), data1000(n, :), ...
			lineType, 'color', colorSuitable, 'LineWidth', 1);
	else % ... alebo nevyhovujucu trajektoriu
		plot(data1000(1, :), data1000(n, :), ...
			lineType, 'color', colorUnsuitable, 'LineWidth', 0.1);
	end
end
hold off

%% Vykreslenie nahodneho vektora
figure('Name', '1,000 trajectories', 'NumberTitle', 'off');
title('Random vector (W_{1}, W_{2})')
xlabel('W(ω,1)', 'FontSize', 20)
ylabel('W(ω,2)', 'FontSize', 20)
grid on
hold on
for n = 2:count
	if (suitable(n-1)) % ak ide o vyhovujucu trajektoriu ...
		plot(data1000(n, w1), data1000(n, w2), ...
			markerType, 'color', colorSuitable, 'MarkerSize', 25);
	else % ... alebo nevyhovujucu trajektoriu
		plot(data1000(n, w1), data1000(n, w2), ...
			markerType, 'color', colorUnsuitable, 'MarkerSize', 20);
	end
end
hold off

%% 10,000 trajektorii
% zistenie poctu trajektorii
[count, ~] = size(data10000);
count = count - 1; % minus prvy riadok, kde je ulozena casova os

% najdenie vyhovujucich trajektorii a ich celkovy pocet
suitable = (data10000(2:end, w1) < data10000(2:end, w3)) ...
	& (data10000(2:end, w3) > data10000(2:end, w2));
suitableCount = nnz(suitable);

%% Vykreslenie pre 10,000 trajektorii
figure('Name', '10,000 trajectories', 'NumberTitle', 'off');
title('10,000 trajectories of Wiener process', ...
	append('Suitable trajectories: ', int2str(suitableCount), '/', int2str(count), ...
	', Pr = ', num2str(suitableCount/count)));
xlabel('Time', 'FontSize', 20)
ylabel('W(ω,t)', 'FontSize', 20)
hold on
for n = 2:count
	if (suitable(n-1)) % ak ide o vyhovujucu trajektoriu ...
		plot(data10000(1, :), data10000(n, :), ...
			lineType, 'color', colorSuitable, 'LineWidth', 1);
	else % ... alebo nevyhovujucu trajektoriu
		plot(data10000(1, :), data10000(n, :), ...
			lineType, 'color', colorUnsuitable, 'LineWidth', 0.1);
	end
end
hold off

%% Vykreslenie nahodneho vektora
figure('Name', '10,000 trajectories', 'NumberTitle', 'off');
title('Random vector (W_{1}, W_{2}')
xlabel('W(ω,1)', 'FontSize', 20)
ylabel('W(ω,2)', 'FontSize', 20)
grid on
hold on
for n = 2:count
	if (suitable(n-1)) % ak ide o vyhovujucu trajektoriu ...
		plot(data10000(n, w1), data10000(n, w2), ...
			markerType, 'color', colorSuitable, 'MarkerSize', 15);
	else % ... alebo nevyhovujucu trajektoriu
		plot(data10000(n, w1), data10000(n, w2), ...
			markerType, 'color', colorUnsuitable, 'MarkerSize', 10);
	end
end
hold off

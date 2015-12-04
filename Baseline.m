
x = load('Akshit_DATA.txt');
y = x-mean(x);

figure
plot(x, 'r');
hold on
plot(y)


fs = 250;
fo = 50;
fn = fs/2;
freqRatio = fo/fn;
notchWidth = 0.1;

f1 = 0.08;
f2 = 0.16;
fil = fir1(21, [f1 f2], 'bandpass');
y_filtered = filter(fil, 1, y);
plot(y_filtered, 'g');
grid on;
legend('original data', 'mean subtraction', 'bandpass');
title('BaseLine Filtered (Akshit DATA)');
xlabel('Sample Number');
ylabel('Amplitude');

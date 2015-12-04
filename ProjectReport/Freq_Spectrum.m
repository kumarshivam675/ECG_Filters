x = load ('RJ_DATA.txt');

fs=250;
original = abs(fft(x));
N = length(x);
bin_vals = [0:N-1];
fax_Hz = bin_vals*fs/N;
N_2 = ceil(N/2);


figure;
subplot(3,1,1);
plot(fax_Hz(1:N_2), original(1:N_2),'b')
title('Frequency Spectrum using RJ DATA');
xlabel('frequency (Hz)');
ylabel('Amplitude');
grid on



x = load ('Akshit_DATA.txt');
original = abs(fft(x));
N = length(x);
bin_vals = [0:N-1];
fax_Hz = bin_vals*fs/N;
N_2 = ceil(N/2);


subplot(3,1,2);
plot(fax_Hz(1:N_2), original(1:N_2),'b')
title('Frequency Spectrum using AKSHIT DATA');
xlabel('frequency (Hz)');
ylabel('Amplitude');
grid on



x = load ('Karan_DATA.txt');
original = abs(fft(x));
N = length(x);
bin_vals = [0:N-1];
fax_Hz = bin_vals*fs/N;
N_2 = ceil(N/2);


subplot(3,1,3);
plot(fax_Hz(1:N_2), original(1:N_2),'b')
title('Frequency Spectrum using KARAN DATA');
xlabel('frequency (Hz)');
ylabel('Amplitude');
grid on

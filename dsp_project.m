
x = load ('RJ_DATA.txt');
% x = load ('samyak_DATA_.txt');
% x = load ('Akshit_DATA.txt');

x = diff(x)*250;        % differentiate
x = diff(x)*250;        % double differentiate

k = 1:175:length(x);
samples = zeros(length(k),1);
for i = 1:length(k)-1
    maximum = max(x(k(i):k(i+1),:));
    if maximum ~= 0
        index = find(x(k(i):k(i+1),:) == maximum);
        index = k(i) + index - 1;
        samples(i) = index(1) - 6;
    end
end
samples(samples == 0) = [];
time = samples ./250;

    

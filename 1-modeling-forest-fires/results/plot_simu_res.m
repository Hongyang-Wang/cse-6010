clear all; clc;

res = importdata('simu_res.txt');
p1 = [res.data(1:101, 2), res.data(1:101, 3)];
p2 = [res.data(102:202, 2), res.data(102:202, 3)];
p3 = [res.data(203:303, 2), res.data(203:303, 3)];

hold on
grid on
plot(p1(:, 1), p1(:, 2), 'r');
plot(p2(:, 1), p2(:, 2), 'g');
plot(p3(:, 1), p3(:, 2), 'b');
h_legend = legend('burn rate=0.01', 'burn rate=0.02', 'burn rate=0.05');
set(h_legend, 'FontSize', 10);
title('Forest Fire Simulation')
xlabel('Growth rate (g)')
ylabel('Average occupied ratio (P)')
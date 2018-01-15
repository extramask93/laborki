function [z1,z2,z3] = symulacja(xc,yc,zc)
r= 13;%1;
x1= 0; % kolumna X
y1= 0;
x2= 0; % kolumna Y
y2= 8;
x3= 4*sqrt(3); % kolumna Z
y3= 4;
z1= zc + sqrt(r^2-(x1-xc)^2-(y1-yc)^2);
z2= zc + sqrt(r^2-(x2-xc)^2-(y2-yc)^2);
z3= zc + sqrt(r^2-(x3-xc)^2-(y3-yc)^2);
end
% 
% z1=zc+sqrt(r^2-(y1-yc)^2-(x1-xc)^2);
% z2=zc+sqrt(r^2-(y2-yc)^2-(x2-xc)^2);
% z3=zc+sqrt(r^2-(y3-yc)^2-(x3-xc)^2);
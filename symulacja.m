function [z1,z2,z3] = symulacja(xc,yc,zc)
r=1;
x1=0;
y1=0.5;
x2=0;
y2=1.5;
x3=1;
y3=1;
z1= zc + sqrt(r^2-(x1-xc)^2-(y1-yc)^2);
z2= zc + sqrt(r^2-(x2-xc)^2-(y2-yc)^2);
z3= zc + sqrt(r^2-(x3-xc)^2-(y3-yc)^2);
end
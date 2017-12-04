x = 0;
y = 1;
z = 0;

x0 = 0;
y0 = 1;
z0 = 0;
s = serial('/dev/ttyUSB4');
set(s,'BaudRate',115200);
fopen(s);

for t=0:0.1:10
    x = sin(t);
    y = cos(t);
    z = t;
    
    a=ceil([x-x0 y-y0 z-z0]*100)   
    str = sprintf('x %d y %d z %d\n',a(1),a(2),a(3))
    fprintf(s, str);
    plot3(x,y,z,'o');
    hold on;
    pause(.7);
    
    x0 = x;
    y0 = y;
    z0 = z;
    
 
end

fclose(s);
delete(s);
clear s;
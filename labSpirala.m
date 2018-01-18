x = 0;
y = 1;
z = 0;

x0 = 0;
y0 = 1;
z0 = 0;
if(exist('s'))
    fclose(s);
end
s = serial('/dev/ttyUSB1');
set(s,'BaudRate',57600);
fopen(s);
str = sprintf('x %d y %d z %d\n',-3500, 1200,-700) %-3300, 1200,-700
while s.BytesAvailable == 0
       
end
fprintf(s, str);
R = 15;
for t=0:0.008:50
    xc = R*sin(t)+((7*sqrt(3))/3);
    yc = R*cos(t)+11;
    zc = t*2;
   [z1,z2,z3] = symulacja(xc,yc,zc);

    if exist('z1stare')
        a=round([z1-z1stare z2-z2stare z3-z3stare]*1000) ; 
    	str = sprintf('x %d y %d z %d\n',a(1),a(2),a(3))
        fprintf(s, str);
        data = fread(s,1);
    end

%     plot3(xc,yc,zc,'o');
%     hold on;
    z1stare = z1;
    z2stare = z2;
    z3stare = z3;
end

fclose(s);
delete(s);
clear s;
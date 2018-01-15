x = 0;
y = 1;
z = 0;

x0 = 0;
y0 = 1;
z0 = 0;
if(exist('s'))
    fclose(s);
end
s = serial('/dev/ttyUSB0');
set(s,'BaudRate',57600);
fopen(s);
str = sprintf('x %d y %d z %d\n',1000,0,0)
 while s.BytesAvailable == 0
      
 end
fprintf(s, str);

for t=0:0.05:50
    xc = sin(t)+2*sqrt(3);
    yc = cos(t)+4;
    zc = 0;
   [z1,z2,z3] = symulacja(xc,yc,zc);
    
    if exist('z1stare')
        a=ceil([z1-z1stare z2-z2stare z3-z3stare]*1000) ; 
    	str = sprintf('x %d y %d z %d\n',a(1),a(2),a(3))
        fprintf(s, str);
        data = fread(s,1);
    end

    plot3(xc,yc,zc,'o');
    hold on;
    z1stare = z1;
    z2stare = z2;
    z3stare = z3;

end

fclose(s);
delete(s);
clear s;
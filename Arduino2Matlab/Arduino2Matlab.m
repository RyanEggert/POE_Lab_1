%%Arduino to MATLAB



%%Import Data
      theta = A(:,1);
        phi = A(:,2);
  rtimesten = A(:,3);
  
  ASize=size(A); %Size of imported matrix
  NumberOfPoints=ASize(1); %The number of data points
  
% %%Variable Preallocation
% x=zeros(NumberOfPoints);
% y=zeros(NumberOfPoints);
% z=zeros(NumberOfPoints);
  
%%Divide rtimesten by ten to get the actual r-value (averaged by arduino)
r2=rtimesten./10;

%%Convert r to centimeters
for i=1:NumberOfPoints
 r(i)=18615.4240./r2(i);
end

%%Spherical to Cartesian Conversion

for i=1:NumberOfPoints
    x(i)=r(i)*cosd(theta(i))*sind(phi(i));
    y(i)=r(i)*sind(theta(i))*sind(phi(i));
    z(i)=r(i)*cosd(phi(i));
end

%%Plot
clf
hold all
scatter3(x,y,z,'k.');
xlabel('X-Axis');
ylabel('Y-Axis');
zlabel('Z-Axis');
axis([-60 60 -60 60 -10 60]);
grid on

figure (2)
clf

hold all
B=[x',y',z'];
plot3k(B,'ColorRange',[20 100],'ColorData',y);
axis([-60 60 0 110 -20 25]);
xlabel('X-Axis')
ylabel('Y-Axis')
zlabel('Z-Axis')

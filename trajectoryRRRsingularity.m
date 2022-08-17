startup_rvc;
clc;
clear all;




%robot setup
L(1)=Link([0 15 0 pi/2 0 -pi/2]);
L(2)=Link([0 0 0 -pi/2 ]);
L(3)=Link([0 20 0 pi/2 ]);
L(4)=Link([0 0 0 -pi/2 0 0]);
L(5)=Link([0 20 0 pi/2]);
L(6)=Link([0 0 0 -pi/2 ]);
L(7)=Link([0 15 0 0 0 pi/2]);



RRR=SerialLink(L, 'name', 'RRR manipulator');


t=0:.04:2;
q0=[0 0 0 0 0 0 0];
q1=[0.5 0.6 0 2.6 0 3 0];


trajec1=jtraj(q0,q1,t); 

hold on
tr1=zeros(4,4);

view(-40,40)
xlim([-50,50])
ylim([-50,50])
zlim([0,80])
for i=1:1:51
    tr1=RRR.fkine(trajec1(i,:));
    atr1=transpose(tr1);
    atrt1(i,:)=atr1(4,1:3);
    atr1=atrt1;
    plot2(atr1(i,:),'r.')
    RRR.plot(trajec1(i,:))
    plot2(atrt1,'b')
end
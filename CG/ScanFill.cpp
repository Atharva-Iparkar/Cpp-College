#include <iostream>
#include<graphics.h>
using namespace std;
class Point
{
public:
int x,y;
};
class Poly
{
private:
Point P[20];
int inter[20],x,y;
int v,Xmin,Xmax,Ymin,Ymax;
public:
int c;
void read();
void calcs();
void display();
void ints(float);
void sort(int);
};
void Poly :: read()
{
int i;
cout<<"Enter number of vertex of the polygon : ";
cin>>v;
if (v>2)
{
for (i=0;i<v;i++)
{
cout<<"Enter the coordinates number "<<i+1<<":";
cout<<"\t x"<<(i+1)<<"=";
cin>>P[i].x;
cout<<"\t y"<<(i+1)<<"=";
cin>>P[i].y;
}
P[i].x=P[0].x;
P[i].y=P[0].y;
Xmin=Xmax=P[0].x;
Ymin=Ymax=P[0].y;
}
else
{
cout<<"--Enter the valid number of the vertices--"<<endl;
exit(0);
}
}
void Poly :: calcs()
{
for (int i=0;i<v;i++)
{
if (Xmin>P[i].x)
Xmin=P[i].x;
if (Xmax<P[i].x)
Xmax=P[i].x;
if (Ymin>P[i].y)
Ymin=P[i].y;
if (Ymax<P[i].y)
Ymax=P[i].y;
}
}
void Poly :: display()
{
int ch1;
char ch='y';
float s;
do
{
cout<<"Enter Menu"<<endl;
cout<<"1. Polygon fill by Scanfill algorithm "<<endl;
cout<<"2. Exit"<<endl;
cout<<"Enter your choice :";
cin>>ch1;
switch (ch1)
{
case 1:
s=Ymin +0.01;
delay(100);
while (s<=Ymax)
{
ints(s);
sort(s);
s++;
}
break;
case 2:
exit(0);
}
cout<<"Do you want to continue ?";
cin>>ch;
}
while (ch=='y' || ch=='Y');
}
void Poly :: ints(float z)
{
int x1, x2, y1, y2, temp;
c=0;
for (int i=0;i<v;i++)
{
x1=P[i].x;
y1=P[i].y;
x2=P[i+1].x;
y2=P[i+1].y;
if(y2<y1)
{
temp=x1;
x1=x2;
x2=temp;
temp=y1;
y1=y2;
y2=temp;
}
if (z<=y2 && z>=y1)
{
if((y1-y2)==0)
x=x1;
else
{
x=((x2-x1)*(z-y1)/(y2-y1));
x=x+x1;
}
if(x<=Xmax && x>= Xmin)
inter[c++]=x;
}
}
}
void Poly :: sort(int z)
{
int temp, i;
for (i=0;i<v;i++)
{
line (P[i].x,P[i].y,P[i+1].x,P[i+1].x);
}
delay(100);
for (i=0;i<c;i+=2)
{
delay(100);
line(inter[i], z, inter [i+1], z);
}
}
int main()
{
int cl;
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
Poly x;
x.read();
x.calcs();
cleardevice();
cout<<"Enter colour you want to fill in the polygon : ";
cin>>cl;
setcolor (cl);
x.display();
closegraph();
return 0;
}



/*
d_comp_pl_ii_11@d-comp-pl-ii-11:~/SE_A2_S211045_Atharva$ g++ ScanFill.cpp -o s -lgraph
d_comp_pl_ii_11@d-comp-pl-ii-11:~/SE_A2_S211045_Atharva$ ./s
Enter number of vertex of the polygon : [xcb] Unknown sequence number while processing queue
[xcb] Most likely this is a multi-threaded client and XInitThreads has not been called
[xcb] Aborting, sorry about that.
s: ../../src/xcb_io.c:260: poll_for_event: Assertion `!xcb_xlib_threads_sequence_lost' failed.
4
Enter the coordinates number 1:	 x1=100
	 y1=100
Enter the coordinates number 2:	 x2=100
	 y2=300
Enter the coordinates number 3:	 x3=300
	 y3=100
Enter the coordinates number 4:	 x4=300
	 y4=300
Enter colour you want to fill in the polygon : 12
Enter Menu
1. Polygon fill by Scanfill algorithm 
2. Exit
Enter your choice :1


*/


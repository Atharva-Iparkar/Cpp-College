#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class poly {
public:
float x=1,y=0.00000,j=0.5,count=0.1;
float r=15;

void draw(int a, int b, int c, int d) {
setcolor(14);
line(a,b,c,d);
sleep(1);
}

void draw() {
for(int k=0;k<=5;k++)
{
for(float i=90;i<270;i+=10)
{
y=cos(((i*22/7)/180))/j;
if(y>0)
y=-y;
x+=5;
setcolor(14);
circle(x,y*100+200,r);
floodfill(x,y*100+200,14);
delay(200);
setcolor(0);
circle(x,y*100+200,r);
floodfill(x,y*100+200,0);
}
j+=count;
}
}
};

int main() {
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
poly p;
p.draw(0,215,650,215);
p.draw();
return 0;
}


/*
d_comp_pl_ii_11@d-comp-pl-ii-11:~/SE_A2_S211045_Atharva$ g++ BouncingBall.cpp -o b -lgraph
d_comp_pl_ii_11@d-comp-pl-ii-11:~/SE_A2_S211045_Atharva$ ./b
[xcb] Unknown sequence number while processing queue
[xcb] Most likely this is a multi-threaded client and XInitThreads has not been called
[xcb] Aborting, sorry about that.
b: ../../src/xcb_io.c:260: poll_for_event: Assertion `!xcb_xlib_threads_sequence_lost' failed.

*/

#include<iostream>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
using namespace std;

void move(int j, int h, int &x, int &y) {
if(j==1)
y=y-h;
else if(j==2)
x+=h;
else if(j==3)
y+=h;
else if(j==4)
x-=h;
lineto(x,y);
}

void hilbert(int r, int d, int l, int u, int i, int h, int &x, int &y) {
if(i>0) {
i--;
hilbert(d,r,u,l,i,h,x,y);
move(r,h,x,y);
hilbert(r,d,l,u,i,h,x,y);
move(d,h,x,y);
hilbert(r,d,l,u,i,h,x,y);
move(l,h,x,y);
hilbert(u,l,d,r,i,h,x,y);
}
}

int main() {
int n,x1,y1;
int x0=50,y0=150,x,y,h=10,r=2,d=3,l=4,u=1;
cout<<"\nGive value of n : ";
cin>>n;
x=x0;
y=y0;
int gm, gd=DETECT;
initgraph(&gd,&gm,NULL);
moveto(x,y);
hilbert(r,d,l,u,n,h,x,y);
delay(20000);
closegraph();
return 0;
}



/*
d_comp_pl_ii_11@d-comp-pl-ii-11:~/SE_A2_S211045_Atharva$ g++ Hilbert.cpp -o h -lgraph
d_comp_pl_ii_11@d-comp-pl-ii-11:~/SE_A2_S211045_Atharva$ ./h

Give value of n : 5
[xcb] Unknown sequence number while processing queue
[xcb] Most likely this is a multi-threaded client and XInitThreads has not been called
[xcb] Aborting, sorry about that.
h: ../../src/xcb_io.c:260: poll_for_event: Assertion `!xcb_xlib_threads_sequence_lost' failed.
d_comp_pl_ii_11@d-comp-pl-ii-11:~/SE_A2_S211045_Atharva$
*/

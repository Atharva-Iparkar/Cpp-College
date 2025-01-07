#include<iostream>
using namespace std;
class point {
public :
float x0, y0;

void accept() {
cin>>x0>>y0;
}

void display() {
cout<<"point is : ("<<x0<<","<<y0<<")"<<endl;
}

void DDALine (float x1, float y1, float x2, float y2) {
float x,y,dx,dy,xinc,yinc,steps;
dx = x2 - x1;
dy = y2 - y1;
x = x1;
y = y1;

while ((x <= x2) && (y <= y2)) {
if (dx > dy) {
steps = dx;
} else {
steps = dy;
}
xinc = dx/steps;
yinc = dy/steps;
x = x + xinc;
y = y + yinc;
cout<<"point is : ("<<x<<","<<y<<")"<<endl;
}
}
};

int main() {
point P1, P2, P3;

cout<<"Enter the start pt. coordinate : ";
P1.accept();
P1.display();
cout<<"Enter the end pt. coordinate : ";
P2.accept();
P2.display();

P3.DDALine(P1.x0, P1.y0, P2.x0, P2.y0);
return 0;

}

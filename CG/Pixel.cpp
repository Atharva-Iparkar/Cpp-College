#include<iostream>
#include<graphics.h>
using namespace std;
class pixel {
public:
int x,y;
void display (int x, int y);
};

void pixel :: display(int, int) {
putpixel(x,y,WHITE);
}

int main() {
pixel P;
int gd= DETECT,gm;
initgraph (&gd,&gm,NULL);
cout<<"Enter the position of pixel : ";
cin>>P.x>>P.y;
P.display(P.x, P.y);
delay(5000000);
return 0;
}

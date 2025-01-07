#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class transform
{
public:
int m,a[20][20],c[20][20];
int i,j,k;
public:
void object();
void accept();
void operator *(float b[20][20]){
for(int i=0;i<m;i++){
for(int j=0;j<m;j++){
c[i][j]=0;
for(int k=0;k<m;k++){
c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
}
}
}
}
};
void transform::object(){
int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,NULL);
line(300,0,300,600);
line(0,300,600,300);
for( i=0;i<m-1;i++){
line(300+a[i][0],300-a[i][1],300+a[i+1][0],300-a[i+1][1]);
}
line(300+a[0][0],300-a[0][1],300+a[i][0],300-a[i][1]);
for( i=0;i<m-1;i++){
line(300+c[i][0],300-c[i][1],300+c[i+1][0],300-c[i+1][1]);
}
line(300+c[0][0],300-c[0][1],300+c[i][0],300-c[i][1]);
int temp;
cout << "Press 1 to continue : ";
cin >> temp;
closegraph();
}
void transform::accept(){
cout<<"\n";
cout<<"Enter the Number Of Edges : ";
cin>>m;
cout<<"\nEnter The Coordinates : ";
cout<<"\n";
for(int i=0;i<m;i++){
for(int j=0;j<3;j++){
if(j>=2)
a[i][j]=1;
else
cin>>a[i][j];
}
}
}
int main(){
int ch,tx,ty,sx,sy;
float deg,theta,b[20][20];
transform t;
t.accept();
cout<<"Enter your choice : ";
cout<<"\n 1.Translation"
"\n 2.Scaling"
"\n 3.Rotation";
cout<<"\n";
cin>>ch;
switch(ch){
case 1: cout<<"\nTRANSLATION OPERATION\n";
cout<<"Enter value of translation parameters (tx and ty) : ";
cout<<"\n";
cin>>tx>>ty;
b[0][0]=b[2][2]=b[1][1]=1;
b[0][1]=b[0][2]=b[1][0]=b[1][2]=0;
b[2][0]=tx;
b[2][1]=ty;
t * b;
t.object();
break;
case 2: cout<<"\nSCALING OPERATION\n";
cout<<"Enter value scaling parameters (tx and ty) : ";
cout<<"\n";
cin>>sx>>sy;
b[0][0]=sx;
b[1][1]=sy;
b[0][1]=b[0][2]=b[1][0]=b[1][2]=0;
b[2][0]=b[2][1]=0;
b[2][2] = 1;
t * b;
t.object();
break;
case 3: cout<<"\nROTATION OPERATION\n";
cout<<"Enter rotation angle : ";
cout<<"\n";
cin>>deg;
theta=deg*(3.14/100);
b[0][0]=b[1][1]=cos(theta);
b[0][1]=sin(theta);
b[1][0]=sin(-theta);
b[0][2]=b[1][2]=b[2][0]=b[2][1]=0;
b[2][2]=1;
t * b;
t.object();
break;
default:
cout<<"\nInvalid choice";
}

getch();
return 0;
}


/*
1. TRANSLATION
d_comp_pl_ii_11@d-comp-pl-ii-11:~/SE_A2_S211045_Atharva$ g++ Transformation.cpp -o t -lgraph
d_comp_pl_ii_11@d-comp-pl-ii-11:~/SE_A2_S211045_Atharva$ ./t

Enter the Number Of Edges : 3

Enter The Coordinates : 
50
50
150
50
60
150
Enter your choice : 
 1.Translation
 2.Scaling
 3.Rotation
1

TRANSLATION OPERATION
Enter value of translation parameters (tx and ty) : 
50
50
Press 1 to continue : [xcb] Unknown sequence number while processing queue
[xcb] Most likely this is a multi-threaded client and XInitThreads has not been called
[xcb] Aborting, sorry about that.
t: ../../src/xcb_io.c:260: poll_for_event: Assertion `!xcb_xlib_threads_sequence_lost' failed.
*/


/*
2. SCALING
d_comp_pl_ii_11@d-comp-pl-ii-11:~/SE_A2_S211045_Atharva$ g++ Transformation.cpp -o t -lgraph
d_comp_pl_ii_11@d-comp-pl-ii-11:~/SE_A2_S211045_Atharva$ ./t

Enter the Number Of Edges : 3

Enter The Coordinates : 
50
50
150
50
60
150
Enter your choice : 
 1.Translation
 2.Scaling
 3.Rotation
2

SCALING OPERATION
Enter value scaling parameters (tx and ty) : 
2
2
Press 1 to continue : [xcb] Unknown sequence number while processing queue
[xcb] Most likely this is a multi-threaded client and XInitThreads has not been called
[xcb] Aborting, sorry about that.
t: ../../src/xcb_io.c:260: poll_for_event: Assertion `!xcb_xlib_threads_sequence_lost' failed.
*/


/*
3. ROTATION
d_comp_pl_ii_11@d-comp-pl-ii-11:~/SE_A2_S211045_Atharva$ g++ Transformation.cpp -o t -lgraph
d_comp_pl_ii_11@d-comp-pl-ii-11:~/SE_A2_S211045_Atharva$ ./t

Enter the Number Of Edges : 3

Enter The Coordinates : 
50
50
150
50
50
150
Enter your choice : 
 1.Translation
 2.Scaling
 3.Rotation
3

ROTATION OPERATION
Enter rotation angle : 
45
Press 1 to continue : [xcb] Unknown sequence number while processing queue
[xcb] Most likely this is a multi-threaded client and XInitThreads has not been called
[xcb] Aborting, sorry about that.
t: ../../src/xcb_io.c:260: poll_for_event: Assertion `!xcb_xlib_threads_sequence_lost' failed.
*/

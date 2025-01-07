#include<iostream>
using namespace std;

class sample {
private :
int pvt;

protected:
int prt;

public :
sample() {
pvt = 10;
prt = 99;
}

friend class F;
};

class F {
public :
void display(sample &t) {
cout<<"The value of pvt : "<<t.pvt<<endl;
cout<<"The value of prt : "<<t.prt<<endl;
}
};

int main() {
sample a;
F Fri;
Fri.display(a);
return 0;
}

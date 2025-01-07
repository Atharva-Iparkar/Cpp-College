//CALCULATOR USINF FUNCTIONS
#include<iostream>
using namespace std;
int a,b;
void add(){
	int add = a+b;
	cout<<"Addition is : "<<add<<endl;
}

void sub(){
	int sub = a-b;
	cout<<"Substraction is : "<<sub<<endl;
}

void multi(){
	int multi = a*b;
	cout<<"Multiplication is : "<<multi<<endl;
}

void div(){
	float div = a/b;
	cout<<"Division is : "<<div<<endl;	
}

void mod(){
	int mod = a%b;
	cout<<"Modulus is : "<<mod<<endl;
}

int main(){

void add();
void sub();
void multi();
void div();
void mod();

cout<<"Enter 1st no. : ";
cin>>a;
cout<<"Enter 2nd no. : ";
cin>>b;

add();
sub();
multi();
div();
mod();

}



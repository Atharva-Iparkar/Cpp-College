//MAKING AN ARRAY OF MARKS
#include <iostream>
using namespace std;
int main(){
int marks[5];
cout<<"Enter marks of  subjects : ";
for (int i=0;i<5;i++){
cin>>marks[i];
}
cout<<"Contents of array are : ";
for (int i=0;i<5;i++){
cout<<marks[i]<<"\t";
}

}

#include <iostream>
using namespace std;

class set {
public:
int size1;
int size2;
int set1[10];
int set2[10];

void insert() {
cout<<"Enter size of set1 : ";
cin>>size1;
for(int i=0; i<size1; i++) {
cout<<"Enter elements of set 1 : ";
cin>>set1[i];
}
cout<<"Enter size of set2 : ";
cin>>size2;
for(int i=0; i<size2; i++) {
cout<<"Enter elements of set 2 : ";
cin>>set2[i];
}
}

void display() {
cout<<"Elements of set 1 : ";
for(int i=0; i<size1; i++) {
cout<<set1[i]<<"\t";
}
cout<<"\nElements of set 2 : ";
for(int i=0; i<size2; i++) {
cout<<set2[i]<<"\t";
}
}

void union_() {
int result[10];
int k = 0;
int count = 0;
int size;

for(int i=0; i<size1; i++) {
result[k++] = set1[i];
for(int j=0; j<size2; j++) {
if(set2[i] != set1[j]) {
result[k++] = set2[i];
break;
}
}
}

size = size1 + count;
cout<<"Union is : ";
for(int i=0; i<=k; i++) {
cout<<result[i]<<"\t";
}
}
};

int main() {
set s;
s.insert();
//s.display();
s.union_();
}

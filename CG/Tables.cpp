#include<iostream>
using namespace std;
int main() {
int n;
int b;
cout<<"Enter a no : ";
cin>>n;
for (int i=1;i<11;i++) {
    for (int j=1; j<=n; j++) {
        b = i * j;
        cout<<b<<"\t";     
        }
    cout<<endl;    
    }
}

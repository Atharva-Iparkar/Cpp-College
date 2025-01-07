

#include<iostream>
#include<fstream>
using namespace std;

class Employee
{
string name;
int ID;
double salary;
public:
void accept()
{
cout<<"Name : ";
cin.ignore();
getline(cin, name);
cout<<"ID : ";
cin>>ID;
cout<<"Salary : ";
cin>>salary;
}
void display()
{
cout<<"\n Name : "<<name;
cout<<"\n ID : "<<ID;
cout<<"\n Salary : "<<salary<<endl;
}
};
int main()
{
Employee o[12];
fstream f;
int i, n;
f.open("Sample.txt",ios::out);
cout<<"Enter the number of Employee's Data to be stored : ";
cin>>n;
for(i=0; i<n; i++)
{
cout<<"\n --Employee Details--"<<endl;
o[i].accept();
f.write((char *)&o[i], sizeof o[i]);
}
f.close();
f.open("Sample.txt",ios::in);
cout<<"\n Employee Information is as Follows"<<endl;
for(i=0; i<n; i++)
{
f.write((char *)&o[i], sizeof o[i]);
o[i].display();
}
f.close();
return 0;
}

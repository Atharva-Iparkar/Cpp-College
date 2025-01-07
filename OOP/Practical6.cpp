#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Item {
public:
char name[10];
int quantity;
int cost,code;
bool operator ==(const Item &i1) {
if(code==i1.code)
return 1;
return 0;
}
bool operator <(const Item &i1) {
if(code<i1.code)
return 1;
return 0;
}
};
vector <Item> o1;
void print(Item &i1);
void display();
void insert();
void search();
void del();
void sort();
bool compare(const Item &i1, const Item &i2) {
return i1.cost<i2.cost;
}
int main() {
int ch;
do {
cout<<"\n 1. Insert \n 2.Display \n 3.Search \n 4.Sort \n 5.Delete \n 6.Exit";
cout<<"\nEnter Your Choice : ";
cin>>ch;
switch (ch) {
case 1:
insert();
break;
case 2:
display();
break;
case 3:
search();
break;
case 4:
sort(o1.begin(),o1.end(),compare);
cout<<"Sorted Array is : "<<endl;
display();
break;
case 5:
del();
break;
case 6:
exit(0);
}
}
while (ch !=7);
return 0;
}
void insert()
{
Item i1;
cout<<"Enter the Product Name : ";
cin>>i1.name;
cout<<"Enter the Product Quantity : ";
cin>>i1.quantity;
cout<<"Enter the Product cost : ";
cin>>i1.cost;
cout<<"Enter the Product Code : ";
cin>>i1.code;
o1.push_back(i1);
}
void display()
{
for_each(o1.begin(),o1.end(),print);
}
void print(Item &i1)
{
cout<<"Item Name : "<<i1.name<<endl;
cout<<"Item Quantity : "<<i1.quantity<<endl;
cout<<"Item Cost : "<<i1.cost<<endl;
cout<<"Item Code : "<<i1.code<<endl<<endl;
}
void search()
{
vector<Item>::iterator p;
Item i1;
cout<<"Enter the Product Code to find : ";
cin>>i1.code;
p=find(o1.begin(),o1.end(),i1);
if (p==o1.end())
{
cout<<"Not Found"<<endl;
}
else
{
cout<<"Found"<<endl;
}
}
void del()
{
vector<Item>::iterator p;
Item i1;
cout<<"Enter the Deletion code :";
cin>>i1.code;
p=find(o1.begin(),o1.end(),i1);
if(p== o1.end())
{
cout<<"Not Found"<<endl;
}
else
{
o1.erase(p);
cout<<"Deleted"<<endl;
}
}

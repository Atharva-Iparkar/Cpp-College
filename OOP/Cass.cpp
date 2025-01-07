#include<iostream>
using namespace std;

class publication {
public :
string title;
float price;
};

class book : public publication {
public :
int pagecount;

void getdata();
void display();
}; 

class tape : public publication {
public :
float time;

void getdata();
void display();
};

void book :: getdata() {
cout<<"Enter the title of book : ";
cin>>title;
cout<<"Enter the price of book: ";
cin>>price;
cout<<"Enter no. of pages : ";
cin>>pagecount;
cout<<"\n";
}

void tape :: getdata() {
cout<<"Enter the title of cassete : ";
cin>>title;
cout<<"Enter the price of casette : ";
cin>>price;
cout<<"Enter time in minutes : ";
cin>>time;
cout<<"\n";
}

void book :: display() {
if(pagecount <= 0 || title == " " || price == 0) {
title = " ";
price = 0;
pagecount = 0;
cout<<"The title of book is : "<<title<<endl;
cout<<"The price of book is : "<<price<<endl;
cout<<"No. of pages : "<<pagecount<<endl<<endl;
} else {
cout<<"The title of book is : "<<title<<endl;
cout<<"The price of book is : "<<price<<endl;
cout<<"No. of pages : "<<pagecount<<endl<<endl;
}
}

void tape :: display() {
if(time <= 0 || title == " " || price == 0) {
title = " ";
price = 0;
time = 0;
cout<<"The title of cassete is : "<<title<<endl;
cout<<"The price of cassete is : "<<price<<endl;
cout<<"Time in minutes : "<<time<<" min"<<endl<<endl;
} else {
cout<<"The title of cassete is : "<<title<<endl;
cout<<"The price of cassete is : "<<price<<endl;
cout<<"Time in minutes : "<<time<<" min"<<endl;
}
}


int main() {
book b;
tape t;
b.getdata();
t.getdata();
b.display();
t.display();
return 0;	
}

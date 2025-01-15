#include <iostream>
using namespace std;

class node {
public: 
string name;
int id;
long int tel;
friend class hashing;

node() {
name = "";
id = 0;
tel = 0;
}
};

class hashing {
public:
node data[10];
int index;
int size = 10;

void create_Record(string n, int i, int tel) {
index = i % size;
for(int j=0; j<size; j++) {
if(data[index].id == 0) {
data[index].name = n;
data[index].id = i;
data[index].tel = tel; 
} else {
index = (index+1) % size;
}
}
}

void getdata_Create() {
string name;
int id;
int tele;
cout<<"Enter name : ";
cin>>name;
cout<<"Enter id : ";
cin>>id;
cout<<"Enter telephone no. : ";
cin>>tele;
create_Record(name, id, tele);
}

void display_Record() {
for(int j=0; j<size; j++) {
cout<<"Name : "<<data[j].name<<endl;
cout<<"Id : "<<data[j].id<<endl;
cout<<"Telephone no. : "<<data[j].tel<<endl;
}
}

void search_Record() {
int i;
cout<<"Enter id of record want to search : ";
cin>>i;
for(int j=0; j<size; j++) {
if() {
cout<<"Name : "<<data[j].name<<endl;
cout<<"Id : "<<data[j].id<<endl;
cout<<"Telephone no. : "<<data[j].tel<<endl;

}
}
}

void delete_Record() {
int i;
int flag = 0;

cout<<"Enter id of record want to delete : ";
cin>>i;

index = i % size;
for(int j=0; j<size; j++) {
if(i == data[index].id) {
flag = 1;
data[index].id = 0;
data[index].name = "";
data[index].tel = 0;
} else {
index = (index+1) % size;
}
}
}
};

int main() {
hashing h;

int ch;
do {
cout<<" 1. Get data\n 2. Delete\n 3. Display\n 4. Search\n";
cout<<"Enter your choice : ";
cin>>ch;

switch(ch) {
case 1:
h.getdata_Create();

case 2:
h.delete_Record();

case 3:
h.display_Record();

case 4:
h.search_Record();
}
} 
while(true);
}

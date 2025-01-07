#include<iostream>
using namespace std;

class studentInfo {
private :
string name;
int roll_no;
string Class;
char div;
string DOB;
string blood_group;
long contact;
string address;
string driving_licensce;
string other;

public :
static int count;
static void display() {
count++;
cout<<"Count is : "<<count<<endl;
}
studentInfo() {
name = " ";
roll_no =0;
Class = " ";
div = ' ';
DOB = " ";
blood_group = " ";
contact = 0;
address = " ";
driving_licensce = " ";
other = " ";
}

~studentInfo() {
cout<<"Destructor is invoked";
}

friend class G;
friend class D;
};

int studentInfo :: count = 0;

class G {
	public :	
		void getdata(studentInfo &r) {
		cout<<"Enter name : ";
		getline(cin,r.name);
		cout<<"Enter roll no : ";
		cin>>r.roll_no;
		cout<<"Enter Class : ";
		cin>>r.Class;
		cout<<"Enter div : ";
		cin>>r.div;
		cout<<"Enter DOB : ";
		cin>>r.DOB;
		cout<<"Enter blood group : ";
		cin>>r.blood_group;
		cout<<"Enter contact : ";
		cin>>r.contact;
		cout<<"Enter address : ";
		cin>>r.address;
		cout<<"Enter driving licensce no : ";
		cin>>r.driving_licensce;
		cout<<"Enter other info : ";
		cin>>r.other;
		}

		void displaydata(studentInfo &t) {
		cout<<"Name is : "<<t.name<<endl;
		cout<<"Roll no is : "<<t.roll_no<<endl;
		cout<<"Class is : "<<t.Class<<endl;
		cout<<"Div is : "<<t.div<<endl;
		cout<<"DOB is : "<<t.DOB<<endl;
		cout<<"Bloog group is : "<<t.blood_group<<endl;
		cout<<"Contact is : "<<t.contact<<endl;
		cout<<"Address is : "<<t.address<<endl;
		cout<<"Driving Licensce no. is : "<<t.driving_licensce<<endl;
		cout<<"other info : "<<t.other<<endl;
		}

};

int main() {

studentInfo s;
G all;
all.getdata(s);
all.displaydata(s);
s.display();
int *age = new int(25);
cout<<"integer age is : "<<*age<<endl;
delete age;

return 0;
}

#include<iostream>
#include<string>
using namespace std;
#define size 10
class node {
	private:
		int id;
		string name;
		long int telephone;
	public:
		node()
		 {
			id = 0;
			telephone = 0;
			name = " ";
			}
		friend class Hashing;
	};
class Hashing
{
	node data[size];
	int index;
	public:
		void insert(int i, string n, long int t) {
		index = i % size;
		for (int j = 0; j < size; j++) 
		{
			if (data[index].id == 0) 
			{
				data[index].id = i;
				data[index].name = n;
				data[index].telephone = t;
				break;
			} 
			else 
			{
				index = (index + 1) % size;
				}
		}
	}
	void del(int i) 
	{
		int index1 = i % size;
		bool flag = false;
		for (int a = 0; a < size; a++) 
		{
			if (data[index1].id == i)
		 	{
				flag = true;
				cout << "\nRecord found & deleted\n";
				cout << "ID: " << data[index1].id << endl;
				cout << "Name: " << data[index1].name << endl;
				cout << "Telephone: " << data[index1].telephone << endl;
				data[index1].id = 0;
				data[index1].name = " ";
				data[index1].telephone = 0;
				break;
			}
			index1 = (index1 + 1) % size;
		}
		if (flag==false) 
		{
		cout << "Record Not Found." << endl;
		}
	}
	void search(int i)
	 {
		int index1 = i % size;
		bool flag = false;
		for (int a = 0; a < size; a++)
		 {
			if (data[index1].id == i) {
			flag = true;
			cout << "\nRecord found\n";
			cout << "ID: " << data[index1].id << endl;
			cout << "Name: " << data[index1].name << endl;
			cout << "Telephone: " << data[index1].telephone << endl;
		}
		index1 = (index1 + 1) % size;
		}
		if (flag==false) 
		{
			cout << "Record Not Found." << endl;
		}
	}
	void display() 
	{
		for (int i = 0; i< size; i++) 
		{
			if (data[i].id != 0)
			 {
				cout << "\nID: " << data[i].id << endl;
				cout << "Name: " << data[i].name << endl;
				cout << "Telephone No: " << data[i].telephone << endl;
			}
			else
			 {
				cout << "No records to display.\n";
			}
		}
	}	
};
int main() 
{
	int i;
	string n;
	long int t;
	int ch;
	Hashing v;
	do 
	{
		cout << "\n----------TELEPHONE DATABASE ---------------\n";
		cout << "1. CREATE RECORD.\n";
		cout << "2. DELETE RECORD.\n";
		cout << "3. SEARCH RECORDS.\n";
		cout << "4. DISPLAY RECORDS.\n";
		cout << "5. EXIT.\n";
		cout << "Enter Your choice: ";
		cin >> ch;
		switch (ch) 
		{
			case 1:
			cout << "Enter ID: ";
			cin >> i;
			cin.ignore();
			cout << "Enter Name: ";
			getline(cin, n);
			cout << "Enter Telephone number: ";
			cin >> t;
			v.insert(i, n, t);
			break;
			case 2:
			cout << "Enter ID to delete: ";
			cin >> i;
			v.del(i);
			break;
			case 3:
			cout<<"Enter ID to Search: ";
			cin>>i;
			v.search(i);
			break;
			case 4:
			v.display();
			break;
			case 5:
			exit(0);
			default:
				cout << "Invalid choice! Try again.\n";
			}
	}	 
	while (ch != 5);
	return 0;
}

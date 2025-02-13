#include<iostream>
#include<vector>
using namespace std;

class set {
	public:
		int size1, size2;
		vector<int> set1, set2;
		
	void insert() {
		cout<<"Enter the size of set 1 : ";
		cin>>size1;
		cout<<"Enter the elements of set 1 "<<endl;
		for(int i=0; i<size1; ++i) {
			int val;
			cin>>val;
			set1.push_back(val);
		}
		
		cout<<"Enter the size of set 2 : ";
		cin>>size2;
		cout<<"Enter the elements of set 2 "<<endl;
		for(int i=0; i<size2; ++i) {
			int val;
			cin>>val;
			set2.push_back(val);
		}
	}
	
	void display() {
		cout<<"\nThe elements of set 1 are : ";
		for(int i=0; i<size1; i++) {
			cout<<set1[i]<<" ";
		}
		
		cout<<"\nThe elements of set 2 are : ";
		for(int i=0; i<size2; i++) {
			cout<<set2[i]<<" ";
		}
	}
	
	void union_() {
		int k = 0;
		vector<int> result;
		for(int i=0; i<size1; ++i) {
			result.push_back(set1[i]);
			k++;
		}
		
		for(int i=0; i<size2; ++i) {
			bool f = false;
			for(int j=0; j<size1; ++j) {
				if(set2[i] == set1[j]) {
					f = true;
				}
			}
			if(f == false) {
				result.push_back(set2[i]);
				k++;
			}
		}
		
		cout<<"\nUnion of the sets is : ";
		for(int i=0; i<k; i++) {
			cout<<result[i]<<" ";
		}
	}
	
	void intersection() {
		int k = 0;
		vector<int> result;
		for(int i=0; i<size1; ++i) {
			for(int j=0; j<size2; ++j) {
				if(set1[i] == set2[j]) {
					result.push_back(set1[i]);
					k++;
				}
			}
		}
		
		cout<<"\nInsersection of the sets is : ";
		for(int i=0; i<k; i++) {
			cout<<result[i]<<" ";
		}
	}
	
	void subset() {
		int k = 0;
		for(int i=0; i<size2; ++i) {
			for(int j=0; j<size1; ++j) {
				if(set2[i] == set1[j]) {
					k++;
				}
			}
		}
		
		if(k == set2.size()) {
			cout<<"\nSet 2 is a subset of set 1";
		} else {
			cout<<"\nSet 2 is not a subset of set 1";
		}
	}
	
	void difference() {
		vector<int> result;
		int k = 0;
		for(int i=0; i<size1; ++i) {
			bool f = false;
			for(int j=0; j<size2; ++j) {
				if(set1[i] == set2[j]) {
					f = true;
				}
			}
			if(!f) {
				k++;
				result.push_back(set1[i]);
			}
		}
		
		cout<<"\nDifference of set 1 & set 2 is : ";
		for(int i=0; i<k; i++) {
			cout<<result[i]<<" ";
		}
	}
	
	void remove_element() {
		int val;
		int ch;
		bool f = false;
		cout<<"From which you want to remove element Set 1 or Set 2 : ";
		cin>>ch;
		if(ch == 1) {
			cout<<"Enter value to be removed : ";
			cin>>val;
			for(int i=0; i<size1; i++) {
				if(set1[i] == val) {
					set1.erase(set1.begin() + i);
					f = true;
					break;
				}
			}
		} else if(ch == 2) {
			cout<<"Enter value to be removed : ";
			cin>>val; 
			for(int i=0; i<size2; i++) {
				if(set2[i] == val) {
					set2.erase(set2.begin() + i);
					f = true;
					break;
				}
			}	
		}

		if(!f) {
			cout<<"Value not found in the set"<<endl;
		} else {
			cout<<"Value "<<val<<" has been removed"<<endl;
		}
	}
};

int main() {
	set s;
	int ch;
	s.insert();
	do {
		cout<<"\n\n1. Union \n2.Intersection \n3. Subset \n4. Difference \n5. Remove Element \n6. Display \n7. Exit \nEnter your choice : ";
		cin>>ch;
		
		switch(ch) {
			case 1:
				s.union_();
				break;
			case 2:
				s.intersection();
				break;
			case 3:
				s.subset();
				break;
			case 4:
				s.difference();
				break;
			case 5:
				s.remove_element();
				break;
			case 6:
				s.display();
				break;
			case 7:
				return 0;
		}
	}	 
	while(ch);
}

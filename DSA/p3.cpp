#include<iostream>
using namespace std;
struct node {
	char label[10];
	int ch_count;
	
	struct node* child[10];
} *root;

class gt {
	gt() {
		root = NULL;		
	}
	
	void create_tree() {
		int books, chapter, i, j, k;
		root = new node();
		cout<<"Enter the name of book : ";
		cin>>root->label;
		cout<<"Enter no. of chapters in the book : ";
		cin>>root->ch_count;
		
		for(int i=0; i<root->ch_count; i++) {
			root->child[i] = new node();
			cout<<"Enter chapter name : ";
			cin>>root->child[i]->label;
			cout<<"Enter no. of section in chapter : ";
			cin>>root->child[i]->ch_count;
			
			for(int j=0; j<root->child[i]->ch_count; j++) {
				root->child[i]->child[j] = new node();
				cout<<"Enter section name : ";
				cin>>root->child[i]->child[j]->label;
				cout<<"Enter no. of sub-section in chapter : ";
				cin>>root->child[i]->child[j]->ch_count;
				
				for(int k=0; k<root->child[i]->child[j]->ch_count; k++) {
					root->child[i]->child[j]->child[k] = new node();
					cout<<"Enter sub-section name : ";
					cin>>root->child[i]->child[j]->child[k]->label;
				}
			}
		}
	}
	
	void display(node *r) {
		
	}
};

int main() {
	
}

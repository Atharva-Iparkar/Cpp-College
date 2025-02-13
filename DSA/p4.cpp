#include<iostream>
using namespace std;

struct node {
    int info;
    struct node* left;
    struct node* right;

    node(int val) {
        info = val;
        left = right = NULL;
    }
};

class BST {
public:
    node* root;

    BST() {
        root = NULL;
    }
   
    void insert(node* &tree, int value) {
        if (tree == NULL) {
            tree = new node(value);  
            cout << "Node with value " << value << " is added!" << endl;
        }
        else if (value < tree->info) {
            insert(tree->left, value);  
        }
        else if (value > tree->info) {
            insert(tree->right, value);  
        }
    }

    void inorder(node* tree) {																																																																																																																																																																																																																											
        if (tree == NULL) return;
        inorder(tree->left);
        cout << tree->info << " ";
        inorder(tree->right);
    }

    void inorder() {
        inorder(root);
    }

    void display(node* tree, int level = 0) {
        if (tree == NULL) return;
        display(tree->right, level + 1);
        for (int i = 0; i < level; i++) {
            cout << "    ";  
        }
        cout << tree->info << endl;
        display(tree->left, level + 1);
    }																																																																																																																																																																																														

    void display() {
        display(root);
    }
};

int main() {
    BST tree;
    int value;
    int ch;
    
    do {
        cout << " 1. Insert\n 2. Print inorder traversal\n 3. Display tree structure\n 4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        
        switch (ch) {
            case 1:
                cout << "Enter a value to insert in the tree: ";
                cin >> value;
                tree.insert(tree.root, value);
                break;
                
            case 2:
                cout << "Inorder Traversal: ";
                tree.inorder();
                cout << endl;
                break;
            
            case 3:
                cout << "Tree Structure:\n";
                tree.display();
                break;

            case 4:
                return 0;
        }
    } while (ch);
}



#include<iostream>
using namespace std;
struct node {
    int info;
    struct node* left;
    struct node* right;
} *root;

class BST {
public:
    node* root;
    BST() {
        root = NULL;
    }

    void insert(node* tree, node* newnode) {
        if (root == NULL) {
            root = newnode;
            root->info = newnode->info;
            root->left = NULL;
            root->right = NULL;
            cout << "Root node is added\n";
            return;
        }

        if (tree->info == newnode->info) {
            cout << "Element already exists\n";
            return;
        }

        if (tree->info > newnode->info) {
            if (tree->left != NULL) {
                insert(tree->left, newnode);
            } 
			else {
                tree->left = newnode;
                tree->left->left = NULL;
                tree->left->right = NULL;
            }
        } else {
            if (tree->right != NULL) {
                insert(tree->right, newnode);
            } else {
                tree->right = newnode;
                tree->right->left = NULL;
                tree->right->right = NULL;
            }
        }
    }

    node* findmin(node* root){
        if(root == NULL){
            return NULL;
        } else {
            while(root->left != NULL) {
                root = root->left;
            }
            return root;
        }
    }
    
    node* findmax(node* root){
        if(root == NULL){
            return NULL;
        } else {
            while(root->right != NULL) {
                root = root->right;
            }
            return root;
        }
    }

   void mirrortree(node* temp) {
	if (temp == NULL)
	return ;
	swap(temp->left,temp->right);
	mirrortree(temp->left);
	mirrortree(temp->right);
	}
	
	void displayer(node* tree, int level) {
        if (tree == NULL) {
            return;
        }
        displayer(tree->right, level + 1);
        for (int i = 0; i < level; i++) {
            cout << "    "; 
        }
        cout << tree->info << endl;
        displayer(tree->left, level + 1);
    }
    
	void display(node* tree) {
        displayer(tree, 0);
    }
	
	int height(node *root) {
		int htleft,htright;
		if(root==NULL) {
			cout<<"Root is empty"<<endl;
			return 0;
		} else if(root->left == NULL && root->right == NULL) {
			return 1;
		}

		htleft = height(root->left);
		htright = height(root->right);
		if(htright>htleft) {
			return htright+1;
		} else {
			return htleft+1;
		}
	}
	
    void preorder(node *root) {
    	if(root != NULL) {
    		cout<<root->info<<" ";
    		preorder(root->left);
    		preorder(root->right);
    	}
    }
    
    
        
};
	
int main() {
    BST bst;
    int h;
    int searchdata;
    node* temp;
    node* minnode; 
    node* maxnode;
    int choice;
    do {
        cout << "************* Binary Tree *************\n";
        cout << "1. Insert elements into the binary tree\n";
        cout << "2. Find Minimum.\n";
        cout << "3. Find Maximum.\n";
        cout << "4. Display elements in the tree\n";
        cout << "5. Mirror Tree.\n";
        cout << "6. Find Height of tree.\n";
        cout << "7. Perform preorder traversal.\n";
        cout << "8. Exit.\n";
	    cout << "Enter your choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
                temp = new node();
                cout << "Enter number to be inserted : ";
                cin >> temp->info;
                temp->left = temp->right = NULL;
                bst.insert(bst.root, temp);
                break;
            
            case 2:
                minnode = bst.findmin(bst.root); 
                if (minnode != NULL) {
                    cout << "Minimum value : " << minnode->info << endl;
                } else {
                    cout << "Empty Tree.\n";
                }
                break;
           
            case 3:
                maxnode = bst.findmax(bst.root); 
                if (maxnode != NULL) {
                    cout << "Maximum value :" << maxnode->info << endl;
                } 
				else {
                    cout << "Empty Tree.\n";
                }
                break;
            
            case 4:
                cout << "Displaying elements in the binary tree:\n";
                bst.display(bst.root);
                cout << endl;
                break;
            
            case 5:
            	bst.mirrortree(bst.root);
            	cout<<"Tree mirrored successfully.\n";
            	break;
            
            case 6:
                h = bst.height(bst.root);
                cout<<"Height of tree is : "<<h<<endl;
                break;
                
            case 7:
                cout<<"Preorder traversal is : ";
                bst.preorder(bst.root);
                cout << endl;
                break;
                        
            case 8:
                cout << "Exiting from the main function.\n";
                return 0;
        }
    } 
	while (choice);
    return 0;
}

	
	
	

	
	

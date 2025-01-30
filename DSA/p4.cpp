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

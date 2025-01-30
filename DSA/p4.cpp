#include<iostream>
using namespace std;

struct node {
    int info;
    struct node *left;
    struct node *right;
};

class BST {
public:
    node *root;

    BST() {
        root = NULL;
    }

    void insert(node *&tree, int value) { 
        if (tree == NULL) {
            tree = new node();
            tree->info = value;
            tree->left = tree->right = NULL;
            cout << "Node " << value << " inserted." << endl;
            return;
        }

        if (tree->info == value) {
            cout << "Element " << value << " already exists." << endl;
            return;
        }

        if (tree->info > value) {
            insert(tree->left, value);
            cout << "Node " << value << " inserted at left." << endl;
        } else {
            insert(tree->right, value);
            cout << "Node " << value << " inserted at right." << endl;
        }
    }
};

int main() {
    BST bst;
    int value;
    int ch;

    do {
        cout << "Menu:\n 1. Insert a node\n 0. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "Enter node to be inserted: ";
                cin >> value;
                bst.insert(bst.root, value);
                break;

            case 0:
                cout << "Exiting the program." << endl;
                return 0;
        }
    } while (true);
}



































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
};


int main() {
    BST tree;

    
    tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    
    cout << "Inorder Traversal: ";
    tree.inorder();
    cout << endl;

    return 0;
}


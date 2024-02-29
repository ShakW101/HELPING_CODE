#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root == NULL){
        return;
    }

    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
}

void traversePreOrder(struct node *root){
    if(root == NULL){
        return;
    }

    cout<<root->key<<" ";
    traversePreOrder(root->left);
    traversePreOrder(root->right);
}

void traversePostOrder(struct node *root){
    if(root == NULL){
        return;
    }


    traversePostOrder(root->left);
    traversePostOrder(root->right);
    cout<<root->key<<" ";
}

// Insert a node
struct node *insertNode(struct node *node, int key) {

    if(node == NULL){
        struct node *toAdd = new struct node;
        toAdd->key = key;
        toAdd->left = nullptr;
        toAdd->right = nullptr;
        return toAdd;
    }

    if(key < node->key){
        node->left = insertNode(node->left, key);
    }else{
        node->right = insertNode(node->right, key);
    }

    return node;
}

struct node *findMin(struct node* root){
    if(root->left == NULL)
        return root;
    root = findMin(root->left);
    return root;
}

// Deleting a node
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if(root == NULL)
        return root;
    else if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        //no child
        if(root->left == NULL && root->right == NULL){
            cout<<"Successfully deleted leaf node "<<root->key<<endl;
            delete root;
            return NULL;
        }
            //one child
        else if (root->left == NULL){
            struct node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            struct node *temp = root;
            root = root->left;
            delete temp;
        }
            //3 kids
        else{
            struct node *temp = findMin(root->right);
            cout << temp->key<<endl;
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}


// Driver code
int main() {
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                cin >> operation;
                break;
            case 2: // delete
                cin >> operand;
                root = deleteNode(root, operand);
                cin >> operation;
                break;
            case 3:
                traverseInOrder(root);
                cout<<endl;
                traversePreOrder(root);
                cout<<endl;
                traversePostOrder(root);
                cin >> operation;
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }
    }
}

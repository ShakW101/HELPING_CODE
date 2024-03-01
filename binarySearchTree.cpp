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
    if (root == NULL)
        return root;

    //search for the node to be deleted
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        //found node!

        //delete node if it only has one or no child
        if (root->left == NULL) {
            //cout<<"GOt here"<<endl;
            struct node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            delete root;
            return temp;
        }

        //for node with two children, get the minimum value in right subtree
        //will use another function to recursively do this
        struct node *temp = findMin(root->right);

        //copy that value to the node
        root->key = temp->key;

        //delete the duplicate node in right subtree
        root->right = deleteNode(root->right, temp->key);
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

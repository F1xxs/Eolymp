#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int x) : data(x), left(NULL), right(NULL) {}
    ~Node() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

Node *insert(Node *root, int val){
    if (!root)
        return root;
    if (root->data == val)
        return root;
    if (val < root->data){
        if (root->left == NULL){
            root->left = new Node(val);
            return root->left;
        }
        else{
            return insert(root->left, val);
        }

    }
    else {
        if (root->right == NULL){
            root->right = new Node(val);
            return root->right;
        }
        else{
            return insert(root->right, val);
        }

    }

        
}

// void preorder(Node *root){
//     if (root == NULL)
//         return;
//     cout << root->data << endl;
//     preorder(root->left);
//     preorder(root->right);
// }

// void inorder(Node *root){
//     if (root == NULL)
//         return;
//     inorder(root->left);
//     cout << root->data << endl;
//     inorder(root->right);
// }

void postorder(Node *root){
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << endl;
}



int main(){
    int n;
    cin >> n;
    Node *root = new Node(n);
    while (cin >> n && n != -1)
         insert(root, n);
    postorder(root);
    return 0;

}

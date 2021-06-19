#include<iostream>
#include "./BT/BST.cpp"
using namespace std;

int getHeight(struct BST *root){
    if(root == NULL)
        return 0;

    return 1+max(getHeight(root->left), getHeight(root->right));
}

// Function to return the diameter of a Binary Tree.
int getDiameter(BST* root) {
    if(!root)
        return 0;
    int complete = getHeight(root->left)+getHeight(root->right)+1;
    int left = getDiameter(root->left);
    int right = getDiameter(root->right);
    
    return max(complete, max(left, right));
}

int main(){
    BST *root = NULL;
    
    // Test Case: 01
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 50);
    insert(root, 1);
    insert(root, 40);
    insert(root, 100);
    // Output: 5

    // Test Case: 02
    // root = insert(root, 5);
    // insert(root, 4);
    // insert(root, 6);
    // insert(root, 3);
    // insert(root, 7);
    // insert(root, 2);
    // Output: 6

    // Test Case: 03
    // root = insert(root, 40);
    // insert(root, 30);
    // insert(root, 60);
    // insert(root, 35);
    // insert(root, 50);
    // insert(root, 45);
    // insert(root, 20);
    // insert(root, 25);
    // Output: 7

    cout<< "\nLongest diameter of tree is: " << getDiameter(root)<< endl;
    
    return 0;
}
#include<iostream>
#include "./BT/BST.cpp"
using namespace std;

int solve(BST *root, int l, int h, int result){
    if(root == NULL)
        return result;
    if(root->data >= l && root->data <= h){
        result += 1;
        // cout<< "["<< root->data<< "] --- "<< result<< endl;
    }

    return (solve(root->left, l, h, result) + solve(root->right, l, h, result))-result;
}


//Function to count number of nodes in BST that lie in the given range.
int getCount(BST *root, int l, int h){   
    int result = 0;
    return solve(root, l, h, result);
}

int main(){
    BST *root = NULL;
    
    // Test Case: 01
    // root = insert(root, 10);
    // insert(root, 5);
    // insert(root, 50);
    // insert(root, 1);
    // insert(root, 40);
    // insert(root, 100);
    // int l = 5, h = 45;
    // Output: 3

    // Test Case: 02
    // root = insert(root, 5);
    // insert(root, 4);
    // insert(root, 6);
    // insert(root, 3);
    // insert(root, 7);
    // int l = 2, h = 8;
    // Output: 5

    // Test Case: 03
    root = insert(root, 5);
    insert(root, 4);
    insert(root, 6);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    int l = 1, h = 5;
    // Output: 4

    cout<< "\nNumber of Nodes In a given Range Are: " << getCount(root, l, h)<< endl;
    
    return 0;
}
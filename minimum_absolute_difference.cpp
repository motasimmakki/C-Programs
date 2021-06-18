#include<iostream>
#include "./BT/BST.cpp"
using namespace std;

int solve(BST *root, int K, int result){
    if(root == NULL)
        return result;

    return min(solve(root->left, K, min(result, abs((root->data)-K))), solve(root->right, K, min(result, abs((root->data)-K))));
}

//Function to find the least absolute difference between any node
//value of the BST and the given integer.
int minDiff(BST *root, int K){   
    int result = abs((root->data)-K);

    return solve(root, K, result);
}

int main(){
    BST *root = NULL;
    
    // Test Case: 01
    // root = insert(root, 10);
    // insert(root, 2);
    // insert(root, 11);
    // insert(root, 1);
    // insert(root, 5);
    // insert(root, 3);
    // insert(root, 6);
    // insert(root, 4);
    // int K = 13;

    // Test Case: 02
    root = insert(root, 8);
    insert(root, 1);
    insert(root, 9);
    insert(root, 4);
    insert(root, 10);
    insert(root, 3);
    int K = 9;

    cout<< "\nMinimum Absolute Difference Is: " << minDiff(root, K)<< endl;
    
    return 0;
}
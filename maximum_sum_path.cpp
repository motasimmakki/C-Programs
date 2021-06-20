#include<iostream>
#include<limits>
#include "./BT/BST.cpp"
using namespace std;

int maxPathSum_helper(BST* root, int &sum){
    if(!root)
        return 0;
    
    int leftSum = INT_MIN, rightSum = INT_MIN;
    
    if(root->left)
        leftSum = maxPathSum_helper(root->left, sum);
    if(root->right)
        rightSum = maxPathSum_helper(root->right, sum);
    
    if(root->left && root->right)
        sum = max(sum, leftSum + rightSum + root->data);
    
    int x = max(leftSum, rightSum);
    if(x == INT_MIN)
        x = 0;
    
    return x + root->data;
}

int maxPathSum(BST* root){   
    if(root){
        int maxSum = numeric_limits<int>::min();
        
        maxPathSum_helper(root, maxSum);
        
        return maxSum;
    }
    return 0;
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
    // Output: 190

    // Test Case: 02
    // root = insert(root, 5);
    // insert(root, 4);
    // insert(root, 6);
    // insert(root, 3);
    // insert(root, 7);
    // insert(root, 2);
    // Output: 27

    // Test Case: 03
    root = insert(root, 40);
    insert(root, 30);
    insert(root, 60);
    insert(root, 35);
    insert(root, 50);
    insert(root, 45);
    insert(root, 20);
    insert(root, 25);
    // Output: 270

    cout<< "\nMiximum Sum Path is: " << maxPathSum(root)<< endl;
    
    return 0;
}
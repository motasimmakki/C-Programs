#include<iostream>
#include<vector>
#include "./BT/BST.cpp"
using namespace std;

void getInorder(BST *root, vector<int> &inorder){
	if(root){
		getInorder(root->left, inorder);
		inorder.push_back(root->data);
		getInorder(root->right, inorder);
	}
}

int isPairPresent(BST *root, int target){
    
    vector<int> inorder;
    getInorder(root, inorder);
    // for(auto x: inorder)
    //     cout<< x<< " ";
        
    int i = 0, j = inorder.size()-1; 
    while(i < j){
        int sum = inorder[i] + inorder[j];
        if(sum == target)
            return 1;
        if(sum > target)
            j--;
        else
            i++;
    }
    
    return 0;
}

int main(){

    BST *root = NULL;
    
    // Test Case: 01
    root = insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    int targetSum = 5;
    // Output: 1

    // Test Case: 02
    // root = insert(root, 6);
    // insert(root, 5);
    // insert(root, 3);
    // insert(root, 1);
    // insert(root, 4);
    // int targetSum = 2;
    // Output: 0

    // Test Case: 03
    // root = insert(root, 15);
    // insert(root, 10);
    // insert(root, 20);
    // insert(root, 8);
    // insert(root, 12);
    // insert(root, 16);
    // insert(root, 25);
    // int targetSum = 33;
    // Output: 1

    cout<< "\nPair Sum Status In BST is: " << isPairPresent(root, targetSum)<< endl;

    return 0;
}
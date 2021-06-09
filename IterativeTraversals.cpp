#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct BinaryTree
{
	int data;
	struct BinaryTree *left;
	struct BinaryTree *right;
}typedef BT;

BT * createNewNode(int data){
	BT *node = (BT*) malloc(sizeof(BT));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

vector<int> preOrderIterative(BT* root){   
    stack<BT*> stack;
    vector<int> result;
    
    stack.push(root);
    
    while(!stack.empty()){
        result.push_back(stack.top()->data);
        BT* current = stack.top();
        stack.pop();
        
        if(current->right)
            stack.push(current->right);
        if(current->left)
            stack.push(current->left);
    }
    
    return result;
}

vector<int> postOrderIterative(BT* root){   
    stack<BT*> stack;
    vector<int> result;
    
    stack.push(root);
    
    while(!stack.empty()){
        result.push_back(stack.top()->data);
        BT* current = stack.top();
        stack.pop();
        
        if(current->left)
            stack.push(current->left);
        if(current->right)
            stack.push(current->right);
    }

    reverse(result.begin(), result.end());
    
    return result;
}

vector<int> inOrderIterative(BT* root) {
        stack<BT*> stack;
        vector<int> result;
    
        BT* current = root;
        
        while(!stack.empty() || current){
            while(current){
                stack.push(current);
                current = current->left;
            }
            current = stack.top();
            stack.pop();    
            result.push_back(current->data);   
            current = current->right;
        }   
        return result;
    }

int main(){
    BT *root = createNewNode(1);
	root->left=createNewNode(2);
	root->right=createNewNode(3);
	root->left->left=createNewNode(4);
	root->left->right=createNewNode(5);

    vector<int> result = preOrderIterative(root);
    cout<< "\nPreOrder Traversal Is : "<< endl;
    for(int i = 0; i < result.size(); i++)
        cout<< result[i]<< "  ";
    
    result = postOrderIterative(root);
    cout<< "\nPostOrder Traversal Is : "<< endl;
    for(int i = 0; i < result.size(); i++)
        cout<< result[i]<< "  ";
    
    result = inOrderIterative(root);
    cout<< "\nInOrder Traversal Is : "<< endl;
    for(int i = 0; i < result.size(); i++)
        cout<< result[i]<< "  ";
}
#include<iostream>
using namespace std;

struct BinaryTree{
	int data;
	struct BinaryTree *left;
	struct BinaryTree *right;
}typedef BT;

BT * createNewNode(int data){
	BT *node = (BT *)malloc(sizeof(BT));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void inorder(BT *root){
	if(root != NULL){
		inorder(root->left);
		cout<< "["<< root->data<< "]\t";
		inorder(root->right);
	}
}

void preorder(BT *root){
	if(root != NULL){
		cout<< "["<< root->data<< "]\t";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(BT *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout<< "["<< root->data<< "]\t";
	}
}

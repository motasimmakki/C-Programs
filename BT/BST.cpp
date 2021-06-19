#include<iostream>
#include<cstdlib>

struct BST{

	int data;
	struct BST *left;
	struct BST *right;
};

struct BST typedef BST;

BST * createBSTNode(int data){
	
	struct BST *node = (BST *)malloc(sizeof(BST));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

BST * insert(BST *root, int data){
	
	BST *head = root;
	BST *node = createBSTNode(data);
	
	if(root == NULL){
		return node;
	}
	
	BST *temp;
	while(root != NULL){
		temp = root;

		if(root->data < data){
			root = root->right;
		}
		else{
			root = root->left;
		}
	}
	if(temp->data < data){
		temp->right = node;
	}
	else{
		temp->left = node;
	}

	return head;
}


void inorder(struct BST *root){
	if(root != NULL){

		inorder(root->left);
		std::cout<< "["<< root->data<< "]\t";
		inorder(root->right);
	}
}


BST *  getMin(BST * root){
	if(root == NULL)
		return root;
	while(root->left != NULL){
		root = root->left;
	}

	return root;
}

BST *  getMax(BST * root){
	if(root == NULL)
		return root;
	while(root->right != NULL){
		root = root->right;
	}
	return root;
}
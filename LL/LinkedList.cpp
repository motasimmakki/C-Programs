#include<iostream>
#include<cstdlib>

typedef struct LinkedList{
	int data;
	struct LinkedList *next;
}LinkedList;

LinkedList * createNode(int data){
		struct LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
		node->data = data;
		node->next = nullptr;
		return node;
}

void insertAtHead(LinkedList **head,int data){
		LinkedList * node = createNode(data);
		
		//Empty List
		if(*head == nullptr){
			*head = node;
		}
		else{
			node->next = *head;
			*head = node;
		}	
}

LinkedList * insertAtTail(LinkedList *head,int data){
		LinkedList * node = createNode(data);
		
		if(head == nullptr){
			head=node;
		}
		else{
			LinkedList * temp=head;
			while(temp->next!=nullptr){
				temp = temp->next;
			}
			temp->next=node; 
		}
		return head;
}

void printList(LinkedList *head){
	while(head != nullptr){
		std::cout<< head->data<< "\t";
		head = head->next;
	}
	std::cout<< std::endl;
}

void printRecursive(LinkedList *head){
	if(head != nullptr){
		printRecursive(head->next);
		std::cout<< head->data<< "\t";
	}
}

LinkedList * reverseList(LinkedList *head){
	LinkedList *temp = head;
	LinkedList *prev = nullptr;
	LinkedList *extra = nullptr;

	while(temp != nullptr){
		extra = prev;
		prev = temp;
		temp = temp->next;
		prev->next = extra;
	}
	return prev;
}

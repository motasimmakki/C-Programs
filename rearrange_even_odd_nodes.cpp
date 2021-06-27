#include<iostream>
#include"./LL/LinkedList.cpp"

void rearrangeEvenOdd(LinkedList *head){
    LinkedList *oddPtr, *evenPtr, *evenStart;
    oddPtr = head;
    evenStart = evenPtr = nullptr;
    
    if(!head)
        return;
    
    if(head->next)
        evenStart = evenPtr = head->next;
    
    while(oddPtr && evenPtr){
        if(oddPtr->next){
            oddPtr->next = oddPtr->next->next;
            if(oddPtr->next)
                oddPtr = oddPtr->next;
            else{
                oddPtr->next = evenStart;
                break;
            }
        }
    
        if(evenPtr->next){
            evenPtr->next = evenPtr->next->next;
            evenPtr = evenPtr->next;
        }

    }

    if(!evenPtr)
        oddPtr->next = evenStart;   
}

int main(){
    LinkedList *list = NULL;
    list = insertAtTail(list,10);
    insertAtTail(list,20);
    insertAtTail(list,30);
    insertAtTail(list,40);
    insertAtTail(list,50);
    insertAtTail(list,60);
    insertAtTail(list,70);
    insertAtTail(list,80);
    insertAtTail(list,90);

    std::cout<< "\nBefore arranging: \n"<< std::endl;
    printList(list);
    rearrangeEvenOdd(list);
    std::cout<< "\nAfter arranging: \n"<< std::endl;
    printList(list);    

    return 0;   
}
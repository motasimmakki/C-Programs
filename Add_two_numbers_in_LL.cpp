// Sample Input:
// 2
// 4 5
// 3
// 3 4 5
// Sample Output:
// 3 9 0

// TC: O(N+M)
// AS: O(max(N, M))

// driver
#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* reverse(struct Node* head){
        Node* curr = head;
        Node* prev = nullptr;
        while(curr){
            Node * temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        l1 = reverse(l1);
        l2 = reverse(l2);
        struct Node *head = NULL, *prev = NULL;
        int carry = 0;
        while (l1 || l2) {
            int v1 = l1? l1->data: 0;
            int v2 = l2? l2->data: 0;
            int tmp = v1 + v2 + carry;
            carry = tmp / 10;
            int val = tmp % 10;
            struct Node* cur = new Node(val);
            if (!head) head = cur;
            if (prev) prev->next = cur;
            prev = cur;
            l1 = l1? l1->next: NULL;
            l2 = l2? l2->next: NULL;
        }
        if (carry > 0) {
            struct Node* l = new Node(carry);
            prev->next = l;
        }
        return reverse(head);
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
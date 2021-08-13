// TC: O(nlogn)
// AS: O(n)

// Test Case 01:
// Input:
// 5
// Output:
// 3

// Test Case 02:
// Input:
// 10
// Output:
// 5

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    typedef struct Node{
        int data = 0;
        struct Node *next = nullptr;
    }Node;
    int find(int N){
        Node* head = (Node *)malloc(sizeof(Node));
        Node* start = head;
        for(int i = 1; i <= N; i++){
            start->data = i;
            if(i == N){
                start->next = head;
                break;
            }
            start->next =  (Node *)malloc(sizeof(Node));
            start = start->next;
        }
        // for(int i = 1; i < N; i++){
        //     cout<< head->data<< " ";
        //     head = head->next;
        // }
        while(head->next){
            head->next = head->next->next;
            head = head->next;
            if(head->next->next == head)
                break;
        }
        return head->data;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.find(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends
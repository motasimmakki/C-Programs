#include<iostream>
#include<stack>
using namespace std;

stack<int> _push(int arr[], int n)
{
   stack<int> stack;
   int minYet = arr[0];
   
   stack.push(arr[0]);
   stack.push(minYet);
   
   for(int i = 1; i < n; i++){
        if(arr[i] < minYet)
            minYet = arr[i];
        
        stack.push(arr[i]);
        stack.push(minYet);
   }
   
   return stack;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int> s)
{
    while(!s.empty()){
        cout<< s.top()<< " ";
        s.pop(); s.pop();   
    }
}

int main(){

    int arr[] = {1, 34, 23, 17, 37, 42, 13, 39, 0, 53, 49, 6, 71} ;
    int size = sizeof(arr)/sizeof(arr[0]);
    
    stack<int> stack = _push(arr, size);

    _getMinAtPop(stack);

    return 0;
}
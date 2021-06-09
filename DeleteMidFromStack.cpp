#include<iostream>
#include<stack>
using namespace std;

void deleteMid(stack<int>&s){
    stack<int> extra;
    int mid = (s.size()/2); 
    
    for(int i = 0; i < mid; i++){ 
        extra.push(s.top());
        s.pop();
    }
    s.pop();
    while(!extra.empty()){
        s.push(extra.top());
        extra.pop();
    }
    
}

void printStack(stack<int> stack){
    while(!stack.empty()){
        cout<< stack.top()<<" ";
        stack.pop();
    }
}

int main(){
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    // stack.push(5);

    cout<< "Initial Stack :"<< endl;
    printStack(stack);
    cout<< "\nAfter Deleting Min :"<< endl;
    deleteMid(stack);
    printStack(stack);

    return 0;
}
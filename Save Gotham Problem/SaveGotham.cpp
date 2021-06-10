#include<iostream>
#include<stack>
using namespace std;

int save_gotham(int data[], int data_size){
    int maxAtRight[data_size] = {0};
    stack<int> stack;

    stack.push(data[data_size-1]);
    maxAtRight[data_size-1] = 0;

    for(int i = data_size-1; i >= 0; i--){
        while(stack.empty()==false && stack.top() <= data[i]){
            stack.pop();
        }
        if(stack.empty())
            maxAtRight[i] = 0;
        else
            maxAtRight[i] = stack.top();
        stack.push(data[i]);
    }
    
    int sum = 0;
    for(auto i: maxAtRight)
        sum += i;
    
    return sum;
}

int main(){
    int data[]= {112, 133, 161, 311, 122, 512, 1212, 0, 19212};
    // int data[]= {5, 9, 7, 6};
    int data_size = sizeof(data)/sizeof(data[0]);

    cout<< save_gotham(data, data_size);

    return 0;
}
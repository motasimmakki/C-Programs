#include<iostream>
#include<stack>
using namespace std;

int main(){
    int data[] = {1, 5, 0, 3, 4, 5};
    int data_size = sizeof(data)/sizeof(data[0]);
    int maxAtleft[data_size] = {0};
    stack<int> stack;

    stack.push(data[0]);
    maxAtleft[0] = -1;

    for(int i = 1; i < data_size; i++){
        while(stack.empty()==false && stack.top() >= data[i]){
            stack.pop();
        }
        if(stack.empty())
            maxAtleft[i] = -1;
        else
            maxAtleft[i] = stack.top();
        stack.push(data[i]);
    }

    for(int i = 0; i < data_size; i++)
        cout<< maxAtleft[i]<< " ";

    return 0;
}

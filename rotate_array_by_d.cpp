#include<iostream>
using namespace std;

void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void reverseArrayInRange(int arr[], int start, int end){
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateArr(int arr[], int d, int n){
    reverseArrayInRange(arr, 0, d-1);
    reverseArrayInRange(arr, d, n-1);
    reverseArrayInRange(arr, 0, n-1);
}

int main(){
    // int arr[] = {1, 2, 3, 4, 5}, D = 2;
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}, D = 3;
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<< "\nArray before rotation is: "<< endl;
    for(int i = 0; i < size; i++)
        cout<< arr[i]<< " ";

    rotateArr(arr, D, size);

    cout<< "\nArray after rotation by "<<D << " is: "<< endl;
    for(int i = 0; i < size; i++)
        cout<< arr[i]<< " ";

    return 0;   
}
#include<iostream>
#include<algorithm>
using namespace std;

bool isTripletSumX(int A[], int n, int X){
    sort(A, A+n);
    int l, r;
    
    for(int i = 0; i < n-2; i++){
        l = i+1; r = n-1;
        
        while(l<r){
            if(A[i]+A[l]+A[r] == X){
                return true;
            }
            if(A[i]+A[l]+A[r] < X)
                l++;
            else
                r-- ;
        }
    }   
    return false;
}

int main(){
    
    // int arr[] = {1, 4, 45, 6 , 10, 8}, X = 13; // {1, 4, 8}
    int arr[] = {1, 2, 4, 3, 6}, X = 10; // {1, 3, 6}
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout<< "\n"<< isTripletSumX(arr, size, X)<<endl;

    return 0;
}
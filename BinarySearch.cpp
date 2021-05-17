#include<iostream>
using namespace std;

int binarySearch(int data, int *arr, int len){
	int low = 0, upper = len-1;

	while(low <= upper){
		int mid = (low + upper)/2; 

		if(arr[mid] == data)
			return mid;
		else{
			if(arr[mid] < data)
				low = mid+1;
			else
				upper = mid-1;
		}
	}

	return -1;
}

int main(){

	int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150};
	// int data = 50				;
	int data = 150;

	cout<< "\nIndex Of Data Is : "<< binarySearch(data, arr, (sizeof(arr)/sizeof(int)))<< endl;

	return 0;
}
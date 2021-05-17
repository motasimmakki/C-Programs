#include<iostream>
using namespace std;

int getFirstOccurrence(int data, int *arr, int len){
	int low = 0, upper = len-1;

	while(low <= upper){
		int mid = (low + upper)/2;

		if(((mid == 0) || (arr[mid-1] < data)) && arr[mid] == data)
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

int getLastOccurrence(int data, int *arr, int len){
	int low = 0, upper = len-1;

	while(low <= upper){
		int mid = (low + upper)/2;

		if(((mid == len-1) || (arr[mid+1] > data)) && arr[mid] == data)
			return mid;
		else{
			if(arr[mid] <= data)
				low = mid+1;
			else
				upper = mid-1;
		}
	}

	return -1;
}

int main(){

	int arr[] = {10, 20, 20, 20, 50, 50, 70, 70, 90, 90, 110, 110, 110, 140, 150};

	// int data = 20				;
	// int data = 110;
	int data = 90;

	cout<< "\nFirst Occurrence Of Data Is At Index : "<< getFirstOccurrence(data, arr, (sizeof(arr)/sizeof(int)))<< endl;
	
	cout<< "\nLast Occurrence Of Data Is At Index : "<< getLastOccurrence(data, arr, (sizeof(arr)/sizeof(int)))<< endl;

	return 0;
}
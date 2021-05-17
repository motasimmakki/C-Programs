#include<iostream>
#include<algorithm>
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

void printFrequency(int *queries, int queriesLen, int *arr, int len){

	sort(arr, (arr + len));

	for(int i = 0; i < queriesLen; i++){
		int high = getLastOccurrence(queries[i], arr, len);
		int low = getFirstOccurrence(queries[i], arr, len);
		
		cout<<  queries[i]<< " --- > "<< (high - low) + 1<< endl;
	}

}

int main(){

	int arr[] = {4, 2, 1, 9, 7, 2, 9, 3, 5, 4, 1, 4};
	int queries[] = {1, 4, 9};

	// int arr[] = {10, 20, 20, 20, 50, 50, 70, 70, 90, 90, 110, 110, 110, 140, 150};
	// int queries[] = {20, 110, 90};

	printFrequency(queries, (sizeof(queries)/sizeof(int)), arr, (sizeof(arr)/sizeof(int)));

	return 0;
}
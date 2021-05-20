#include<iostream>
using namespace std;

int getFaultPoint(int *bulbStatus, int len){
	int low = 0, high = len-1;

	while(low <= high){
		int mid = (low+high)/2;
		if(((mid == 0) || (bulbStatus[mid-1] == 1)) && (bulbStatus[mid] == 0))
			return mid-1;
		else if(bulbStatus[mid] == 1)
			low = mid+1;
		else
			high = mid-1;
	}
	return -1;
}

int main(){

	int bulbStatus[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0};
	int len = (sizeof(bulbStatus)/sizeof(int));

	cout<< "\nFailt Point Is : "<< getFaultPoint(bulbStatus, len);

	return 0;
}
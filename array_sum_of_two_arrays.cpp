#include<iostream>
using namespace std;

int main() {
	int size1;
	cin>> size1;
	int arr1[size1];
	for(int i = 0; i < size1; i++)
		cin>> arr1[i];
	int size2;
	cin>> size2;
	int arr2[size2];
	for(int i = 0; i < size2; i++)
		cin>> arr2[i];

	int result[max(size1, size2)] = {0};
	int carry = 0, resultIndex = max(size1, size2);
	int i, j;

	for(i = size1-1, j = size2-1; (i >= 0) && (j >= 0); i--, j--){
		int digit = arr1[i] + arr2[j] + carry;

		if(digit/10){
			result[resultIndex] = (digit % 10);
			carry = (digit / 10);
		}
		else{
			result[resultIndex] = digit;
			carry = 0;
		}
		resultIndex -= 1;
	}

	while(i >= 0){
		int digit = arr1[i] + carry;

		if(digit/10){
			result[resultIndex] = (digit % 10);
			carry = (digit / 10);
		}
		else{
			result[resultIndex] = digit;
			carry = 0;
		}
		resultIndex -= 1;
		i -= 1;
	}

	while(j >= 0){
		int digit = arr2[j] + carry;

		if(digit/10){
			result[resultIndex] = (digit % 10);
			carry = (digit / 10);
		}
		else{
			result[resultIndex] = digit;
			carry = 0;
		}
		resultIndex -= 1;
		j -= 1;
	}
	if(carry)
		result[resultIndex] = carry;

	for(int i = 0; i < max(size1, size2)+1; i++){
		if((result[i] == 0) && (i == 0))
			i += 1;
		cout<< result[i]<< ", ";
	}
	cout<< "END";
	
	return 0;
}
// Test Case: 01
// 4
// 1 0 2 9
// 5
// 3 4 5 6 7
// Output: 
// 3, 5, 5, 9, 6, END

// Test Case: 02
// 1
// 9
// 2
// 9 9
// Output: 
// 1, 0, 8, END
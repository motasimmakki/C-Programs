#include<iostream>
using namespace std;

#define n 6
#define nQ 3


struct queries{
	int l, r, x;
};
struct queries typedef Queries;

void solve(int arr[], Queries Query[], bool arrForm){

	// When Non-Zero Array.
	if(arrForm){
		int extraArray[n] = {0};

		for(int i = 0; i < nQ; i++){
			int l = Query[i].l;
			int r = Query[i].r;
			int x = Query[i].x;

			extraArray[l] += x;
			if(r+1 < n)
				extraArray[r+1] = extraArray[r+1] - x;
			
		}

		for(int i = 1; i < n; i++)
			extraArray[i] += extraArray[i-1];
		
		// Adding elements of Both the Array.
		for(int i = 0; i < n; i++)
			arr[i] += extraArray[i];
	}
	else{
		for(int i = 0; i < nQ; i++){
			int l = Query[i].l;
			int r = Query[i].r;
			int x = Query[i].x;

			arr[l] += x;
			if(r+1 < n)
				arr[r+1] = arr[r+1] - x;
			
		}

		for(int i = 1; i < n; i++)
			arr[i] += arr[i-1];
	}

	cout<< "\nArray After Queries Is :"<< endl;
	for(int i = 0; i < n; i++)
		cout<< arr[i]<< " ";	
}

int main(){
	// int arr[n] = {0, 0, 0, 0, 0, 0};
	// bool arrForm = false;//false->Zero-Array, true-> Non-Zero Array.
	int arr[n] = {1, 2, 1, 5, 6, 3};
	bool arrForm = true;
	Queries Query[3] = {{0, 3, 2}, {1, 4, 5}, {5, 5, 6}};

	cout<< "\nArray Is :"<< endl;
	for(int i = 0; i < n; i++)
		cout<< arr[i]<< " ";

	solve(arr, Query, arrForm);

	return 0;
}
#include<iostream>
using namespace std;

#define n 6
#define nQ 3


struct queries{
	int l, r;
};
struct queries typedef Queries;

void solve(int arr[], Queries Query[], int prefixSum[]){
	for(int i = 0; i < nQ; i++){
		int l = Query[i].l;
		int r = Query[i].r;

		cout<< "\nSum From " <<l << " to "<<r << " Is : "<< prefixSum[r]-prefixSum[l-1]<< endl;
	}
}

int main(){
	int arr[n] = {1, 2, 1, 5, 6, 3};
	int prefixSum[n];
	Queries Query[3] = {{0, 3}, {1, 2}, {1, 4}};

	prefixSum[0] = arr[0];
	for(int i = 1; i < n; i++)
		prefixSum[i] = arr[i]+prefixSum[i-1];

	// cout<< "\nArray Is :"<< endl;
	// for(int i = 0; i < n; i++)
	// 	cout<< arr[i]<< " ";

	// cout<< "\nPrefix Sum Array Is :"<< endl;
	// for(int i = 0; i < n; i++)
	// 	cout<< prefixSum[i]<< " ";

	solve(arr, Query, prefixSum);

	return 0;
}
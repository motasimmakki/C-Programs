// Sample Input:
// 1
// 11
// 1 3 5 8 9 2 6 7 6 8 9
// Sample Output:
// 3

#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;

int getMinJump(int arr[], int n){
	int dp[n];
	memset(dp, -1, sizeof(dp));
	dp[n-1] = 0;
	for(int i = n-2; i >= 0; i--){
		int steps = arr[i];
		int min = INT_MAX;
		for(int j = 1; j <= steps and i+j < n; j++){
			if(dp[i+j] != -1 and dp[i+j] < min)
				min = dp[i+j];
		}
		if(min != INT_MAX)
			dp[i] = min+1;
	}

	return dp[0];
}

int main() {
	int t;
	cin>> t;
	vector<int> result;
	while(t--){
		int n;
		cin>> n;
		if(n == 0){
			result.push_back(INT_MAX);
			continue;
		}
		int arr[n];
		for(int i = 0; i < n; i++)
			cin>> arr[i];
		result.push_back(getMinJump(arr, n));
	}
	for(auto x: result)
		cout<< x<< endl;

	return 0;
}
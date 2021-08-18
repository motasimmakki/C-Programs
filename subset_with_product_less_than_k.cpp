#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numOfSubsets(int arr[], int N, int K) {
        vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
        
        for(int i = 1; i <= N ; i++){
            for(int j = 1; j <= K; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = 1 + dp[i-1][j] + dp[i-1][j/arr[i-1]];
                }    
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][K];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends
// Sample Input 01:
// 6
// 3 2 1 5 6 4
// 2
// Sample Output:
// Yes

// Sample Input 02:
// 7
// 13 8 10 7 15 14 12
// 1
// Sample Output:
// No

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    struct Compare{
        bool operator()(const pair<int, int>& pair1, const pair<int, int>& pair2){
            return pair1.first < pair2.first;
        }
    };
    
    string isKSortedArray(int arr[], int n, int k)
    {
        vector<pair<int, int>> myArr;
        for(int i = 0; i < n; i++)
            myArr.push_back({arr[i], i});
        sort(myArr.begin(), myArr.end(), Compare());
        
        for(int i = 0; i < n; i++){
            if(abs(myArr[i].second-i) > k)
                return "No";
        }
        return "Yes";
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>k;
	    Solution ob;
	cout <<ob.isKSortedArray(arr, n, k)<<endl;
	}
	return 0;	 
}  // } Driver Code Ends
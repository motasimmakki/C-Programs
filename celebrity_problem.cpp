//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    bool isKnown(vector<vector<int> >& M, int n, int index){
        for(int i = 0; i < n; i++){
            if(i == index)
                continue;
            if(!M[i][index])
                return false;
        }
        return true;
    }
    bool isDontKnowAny(vector<vector<int> >& M, int n, int index){
        for(int i = 0; i < n; i++){
            if(i == index)
                continue;
            if(M[index][i])
                return false;
        }
        return true;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {   
        int celebrity = -1;
        for(int i = 0; i < n; i++){
            if(isKnown(M, n, i) and isDontKnowAny(M, n, i)){
                celebrity = i;
                break;
            }
        }
        return celebrity;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends

// Sample Input:
// 3
// 0 1 0 0 0 0 0 1 0
// Ouput: 
// 1
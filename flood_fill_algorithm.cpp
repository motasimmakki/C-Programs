#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isVisited[101][101];
    vector<vector<int>> result;
    int ROW, COL, COLOR;
    
    bool isValid(vector<vector<int>>& grid, int i, int j){
        if((i>=0 and i<ROW) and (j>=0 and j<COL) and (grid[i][j] == COLOR) and (!isVisited[i][j]))
            return true;
        return false;
    }
    
    void DFS(vector<vector<int>>& grid, int i, int j, int newColor){
        isVisited[i][j] = true;
        result[i][j] = newColor;
        if(isValid(grid, i, j+1)){
            DFS(grid, i, j+1, newColor);
        }
        if(isValid(grid, i, j-1)){
            DFS(grid, i, j-1, newColor);
        }
        if(isValid(grid, i+1, j)){
            DFS(grid, i+1, j, newColor);
        }
        if(isValid(grid, i-1, j)){
            DFS(grid, i-1, j, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int r0, int c0, int newColor) {
        memset(isVisited, false, sizeof isVisited);
        ROW = grid.size(); COL = grid[0].size(); COLOR = grid[r0][c0];
        result.resize(ROW, vector<int>(COL));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++)
                result[i][j] = grid[i][j];
        }
        DFS(grid, r0, c0, newColor);
        return result;    
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        cout<< "\nAfter Running Flood Fill Algorithm: "<< endl;
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends

// Input Method:
// - Give Number of Test Cases you want to run.
// - Input should contain n+2 lines. 
// - First line should contain n and m. 
// - Each of next n lines should contain m elements. 
// - Next lines should contain sr, sc and newColor.

// Sample Input:
// 1
// 3 3
// 1 1 1
// 1 1 0
// 1 0 1
// 1 1 2
// Sample Output:
// 2 2 2 
// 2 2 0 
// 2 0 1 
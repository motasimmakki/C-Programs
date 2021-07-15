#include<iostream>
#include<vector>
using namespace std;

vector<int> result;
    
pair<int, int> getUpside(vector<vector<int>>& mat, int row, int col, int m, int n){
	pair<int, int> indices;
	
	while(row >= 0 && col < n){
		result.push_back(mat[row][col]);
		row--; col++;
	}
	indices.first = row+1;
	indices.second = col-1;
	return indices;
}

pair<int, int> getDownside(vector<vector<int>>& mat, int row, int col, int m, int n){
	pair<int, int> indices;
	
	while(row < m && col >= 0){
		result.push_back(mat[row][col]);
		row++; col--;
	}
	indices.first = row-1;
	indices.second = col+1;
	return indices;
}

void findDiagonalOrder(vector<vector<int>>& mat) {
	int m = mat.size(), n = mat[0].size();
	int row = 0, col = 0;
	int boundary = 0;
	
	while(row < m && col < n){
		// cout<< row<< " - "<< col<< endl;
		pair<int, int> indices{-1, -1};
		if(boundary%2){
			indices = getDownside(mat, row, col, m, n);
			if(indices.first+1 == m){
				row = indices.first;
				col = indices.second+1;
			}
			else{
				row = indices.first+1;
				col = indices.second;
			}
		}
		else{
			indices = getUpside(mat, row, col, m, n);
			if(indices.second+1 == n){
				row = indices.first+1;
				col = indices.second;
			}
			else{
				row = indices.first;
				col = indices.second+1;
			}
		}
		boundary++;
	}
}

int main() {
	int m, n;
	cin>> m >> n;
	vector<vector<int>> mat(n , vector<int> (m, 0));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
		cin>> mat[i][j];
	}

	findDiagonalOrder(mat);

	for(int i = 0; i < result.size(); i++)
		cout<< result[i]<< " ";
}

// Sample Input:
// 3 3
// 1 2 3 4 5 6 7 8 9

// Sample Output:
// 1 2 4 7 5 3 6 8 9 

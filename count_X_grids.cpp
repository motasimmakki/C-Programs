#include<iostream>
#include<vector>
using namespace std;

bool isVisited[100][100] = {{false}};
    
bool isValidMove(int i, int j, vector<vector<char>> &grid){
    if((i >= 0 && i < grid.size()) && (j < grid[i].size() && j >= 0)){
        if(!isVisited[i][j] && grid[i][j] == 'X')
            return true;
    }
    return false;
}

void getDFS(vector<vector<char>> &grid, int i, int j){
    isVisited[i][j] = true;
    
    if(isValidMove(i-1, j, grid))
        getDFS(grid, i-1, j);
    if(isValidMove(i+1, j, grid))
        getDFS(grid, i+1, j);
    if(isValidMove(i, j-1, grid))
        getDFS(grid, i, j-1);
    if(isValidMove(i, j+1, grid))
        getDFS(grid, i, j+1);
}

//Function to find the number of 'X' total shapes.
int xShape(vector<vector<char>> &grid) 
{
    int countX = 0;
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 'X' && !isVisited[i][j]){
                countX += 1;
                getDFS(grid, i, j);
            }
        }
    }
    
    return countX;
}

int main(){
    // vector<vector<char>> grid{
    //     {'X', '0', 'X'},
    //     {'0', 'X', '0'},
    //     {'X', 'X', 'X'},
    // };

    vector<vector<char>> grid{
        {'X', 'X'},
        {'X', 'X'}
    };

    cout<<"\nNumber of X Islands in grid are: "<< xShape(grid)<< endl;
}

// Test Case: 01
// 3 3
// XOX
// OXO
// XXX
// Output:
// 3

// Test Case: 02
// 1 1
// XX
// XX
// Output:
// 1
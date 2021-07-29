#include<iostream>
#include<vector>
using namespace std;

#define N 9
    
bool isValid(vector<vector<char>>& board, int i, int j, char num){
    for(int x = 0; x < N; x++){
        if(board[i][x] == num)
            return false;
    }
    for(int x = 0; x < N; x++){
        if(board[x][j] == num)
            return false;
    }
    int start_i = i/3*3, start_j = j/3*3;
    for(int m = 0; m < 3; m++){
        for(int n = 0; n < 3; n++){
            if(board[m+start_i][n+start_j] == num)
                return false;
        }
    }
    return true;
}

bool Solve(vector<vector<char>>& board, int i, int j){
    if(i == 9)
        return true;
    if(j == 9)
        return Solve(board, i+1, 0);
    if(board[i][j] != '.')
        return Solve(board, i, j+1);
    for(char c = '1'; c <= '9'; c++){
        if(isValid(board, i, j, c)){
            board[i][j] = c;
            if(Solve(board, i, j+1)) 
                return true;
            board[i][j] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    Solve(board, 0, 0);
}

void printSudoku(vector<vector<char>>& board){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout<< board[i][j]<< " ";
		}
		cout<< endl;
	}
}

int main(){
	// vector<vector<char>> board
	// {
	// 	{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
	//  	{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	//  	{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	//  	{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	//  	{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	//  	{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	//  	{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	//  	{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	//  	{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	// };
	vector<vector<char>> board
	{
		{'8', '3', '.', '.', '7', '.', '.', '.', '.'}, 
 		{'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
 		{'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
 		{'8', '.', '.', '.', '6', '.', '.', '.', '3'}, 
 		{'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
 		{'7', '.', '.', '.', '2', '.', '.', '.', '6'}, 
 		{'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
 		{'.', '.', '.', '4', '1', '9', '.', '.', '5'}, 
 		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};

	cout<< "\nInitial Sudoku:"<<endl;
	printSudoku(board);
	solveSudoku(board);
	cout<< "\nSolved Sudoku:"<<endl;
	printSudoku(board);

	return 0;
}
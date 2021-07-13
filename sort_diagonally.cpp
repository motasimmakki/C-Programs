#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortUpperRight(vector<vector<int> >& matrix, int row, int col, int n, int m){
    int r = row, c = col;
    vector<int> elements;
    while(r < n && c < m){
        elements.push_back(matrix[r][c]);
        r++; c++;
    }
    sort(elements.begin(), elements.end(), greater<int>());
    
    r = row; c = col;
    while(r < n && c < m){
        matrix[r][c] = elements.front();
        elements.erase(elements.begin());
        r++; c++;
    }
}

void sortLowerLeft(vector<vector<int> >& matrix, int row, int col, int n, int m){
    int r = row, c = col;
    vector<int> elements;
    while(r < n && c < m){
        elements.push_back(matrix[r][c]);
        r++; c++;
    }
    sort(elements.begin(), elements.end());
    
    r = row; c = col;
    while(r < n && c < m){
        matrix[r][c] = elements.front();
        elements.erase(elements.begin());
        r++; c++;
    }
}

void diagonalSort(vector<vector<int> >& matrix, int n, int m) {
    // for col
    for(int i = 1; i < m; i++){
        sortUpperRight(matrix, 0, i, n, m);
    }
    
    // for row
    for(int i = 1; i < n; i++){
        sortLowerLeft(matrix, i, 0, n, m);   
    }
}

void printMatrix(vector<vector<int> >& matrix, int n, int m) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<< matrix[i][j]<< " ";
        }
        cout<< endl;
    }
}

int main(){
    // vector<vector<int>> matrix
    // {
    //     {3, 6, 3, 8, 2},
    //     {4, 1, 9, 5, 9},
    //     {5, 7, 2, 4, 8},
    //     {8 ,3, 1, 7, 6}
    // };
    vector<vector<int>> matrix
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18},
        {19, 20, 21},
        {22, 23, 24}
    };
    int n = matrix.size();
    int m = matrix[0].size();

    cout<< "\nMatrix before Sorting Diagonally:"<< endl;
    printMatrix(matrix, n, m);
    diagonalSort(matrix, n, m);
    cout<< "\nMatrix after Sorting Diagonally:"<< endl;
    printMatrix(matrix, n, m);

    return 0;
}
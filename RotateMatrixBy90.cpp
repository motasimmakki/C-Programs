#include<iostream>
using namespace std;

#define N 3

void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void printMatrix(int matrix[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<< "["<< matrix[i][j]<< "]\t";
        }
        cout<< endl;
    }
}

int main(){

    int matrix[N][N] = {
                        {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}
                    };
    cout<< "\nInitial Matrix Is: "<< endl;
    printMatrix(matrix);

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    cout<< "\nTranspose Of Matrix Is: "<< endl;
    printMatrix(matrix);

    for(int i = 0; i < N; i++){
        int start = 0, end = N-1;

        while(start < end){
            swap(matrix[start][i], matrix[end][i]);
            start += 1;
            end -= 1;
        }
    }
    cout<< "\n90` Rotation Of Matrix Is: "<< endl;
    printMatrix(matrix);

    return 0;
}
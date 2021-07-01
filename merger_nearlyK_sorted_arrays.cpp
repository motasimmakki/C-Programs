#include <iostream>
#include<vector>
#include<queue>
using namespace std;

void sortNearly(vector<int> Arr, int N, int K){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    int i;
    for(i = 0; i < K; i++){
        minHeap.push(Arr[i]);
    }
    for( ; i < N; i++){
        cout<< minHeap.top()<< " ";
        minHeap.pop();
        minHeap.push(Arr[i]);
    }
    while(!minHeap.empty()){
        cout<< minHeap.top()<< " ";
        minHeap.pop();
    }
    cout<< endl;
}

int main() {
    int T;
    cin>> T;
    int N[T], K[T];
    vector<vector<int>> Arr(T);
    for(int i = 0; i < T; i++){
        cin>> N[i];
        cin>> K[i];
        for(int j = 0; j < N[i]; j++){
            int item;
            cin>> item;
            Arr[i].push_back(item);
        }
    }
    
    // for(int i = 0; i < T; i++){
    //     for(int j = 0; j < N[i]; j++)
    //         cout<< Arr[i][j]<< " ";
    //     cout<< endl;
    // }
    
    for(int i = 0; i < T; i++){
        sortNearly(Arr[i], N[i], K[i]);
    }
	
	return 0;
}
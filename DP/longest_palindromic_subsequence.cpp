#include<iostream>
using namespace std;

string str;
int memo[1000][1000];

int lps(int i, int j){
    if(memo[i][j] != -1)
        return memo[i][j];
    if(i == j){
        memo[i][j] = 1;
        return memo[i][j];
    }
    if(i+1 == j){
        if(str[i] == str[j]){
            memo[i][j] = 2;
            return memo[i][j];
        }
    }
    if(str[i] == str[j])
        memo[i][j] = 2 + lps(i+1, j-1);
    else
        memo[i][j] = max(lps(i+1, j), lps(i, j-1));
    return memo[i][j];
}

int longestPalinSubseq(string S){
    str = S;
    int len = str.length();
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++)
            memo[i][j] = -1;
    }
    return lps(0, len-1);
}

int main(){
    str = "bbabcbcab"; // 7
    // str = "abcd"; // 1

    cout<< "\nLength of Longest Palindromic Subsequence is: "<< longestPalinSubseq(str);

    return 0;
}
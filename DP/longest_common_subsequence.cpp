#include<iostream>
using namespace std;

string str1, str2;
int tab[1000][1000];

int lcs_helper(int i, int j){
    if(i == -1 || j == -1)
        return 0;
    if(tab[i][j] != -1)
        return tab[i][j];
    if(str1[i] == str2[j])
        tab[i][j] = 1 + lcs_helper(i-1, j-1);
    else
        tab[i][j] = max(lcs_helper(i, j-1), lcs_helper(i-1, j));
    return tab[i][j];
}

//Function to find the length of longest common subsequence in two strings.
int lcs(int x, int y, string s1, string s2){
    str1 = s1; str2 = s2;
    int max_size = max(x, y);
    for(int i = 0; i < max_size; i++){
        for(int j = 0; j < max_size; j++)
            tab[i][j] = -1;
    }
    return lcs_helper(x-1, y-1);
}

int main(){
    str1 = "ABCDGH";
    str2 = "AEDFHR";
    int x = str1.length();
    int y = str2.length();
    // 3

    cout<< "\nLength of Longest Common Subsequence is: "<< lcs(x, y, str1, str2);

    return 0;
}
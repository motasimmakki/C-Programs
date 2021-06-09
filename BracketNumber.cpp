#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isBracket(char ch){
    if(ch =='(' || ch == ')')
        return true;
    return false;
}

vector<int> barcketNumbers(string x){   
    vector<int> bracketNumber;
    int openingCount = 1;
    
    stack<char> s;
    for (int i = 0; i < x.length(); i++)
    {   
        if (x[i] == '('){
            s.push(openingCount);
            bracketNumber.push_back(openingCount++);
        }
        else if(x[i] == ')'){
            if(!s.empty()){
                int closingCount = s.top();
                s.pop();
                bracketNumber.push_back(closingCount);
            }
        }
    }
    return bracketNumber;
}

int main(){
    // string str = "(aa(bdc))p(dee)";
    // string str = "(((()(";
    string str = "((()())()(";
    vector<int> bracketCount = barcketNumbers(str);

    for(int i = 0; i < bracketCount.size(); i++)
        cout<< bracketCount[i]<< " ";
    
    return 0;
}
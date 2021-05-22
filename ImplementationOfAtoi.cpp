#include<iostream>
using namespace std;

int atoi(string str)
{
    int num = 0;
    bool sign = false;
    
    for(int i = 0; i < str.length(); i++){
        if(isdigit(str[i])){
            int digit = (int)str[i] - '0';
            num = (num*10) + digit;
            // cout<< digit<< endl;
        }
        else if(str[i] == '-' && (i == 0))
            sign = true;
        else 
            return -1; 
    }
    
    return (sign)? -num: num;
}

int main(){

    cout<< stoi("123");
    // cout<< stoi("-12");
    // cout<< stoi("312");

    return 0;
}
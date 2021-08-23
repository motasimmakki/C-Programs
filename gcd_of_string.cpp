// Sample Input 01:
// str1 = "ABCABC", str2 = "ABC"
// Sample Output:
// "ABC"

// Sample Input 02:
// str1 = "ABABAB", str2 =  "ABAB"
// Sample Output:
// "AB"

// Sample Input 03:
// str1 = "LEET", str2 =  "CODE"
// Sample Output:
// ""

#include<iostream>
#include<algorithm>
using namespace std;

string gcdOfStrings(string str1, string str2) {
   return (str1+str2 == str2+str1)? str1.substr(0, __gcd(str1.length(), str2.length())): "";
}

int main(){
	string str1 = "ABCABC", str2 = "ABC";
	// string str1 = "ABABAB", str2 =  "ABAB";
	// string str1 = "LEET", str2 =  "CODE";

	cout<< gcdOfStrings(str1, str2);

	return 0;
}
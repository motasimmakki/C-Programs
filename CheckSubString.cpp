#include<iostream>
using namespace std;

bool isSubString(string str1, string str2){

	int i, j, a;
	for(i = 0, j = 0, a = 0; (i < str1.length()) && (j < str2.length()); i++){
		if(str1[i] == str2[j])
			j++;
		else{
			j = 0; i = a++;
		}
	}

	return (j == str2.length());
}

int main(){
	string str1 = "geeksforgeeks";
	string str2 = "eksforg";

	if(isSubString(str1, str2))
		cout<< "Yes!";
	else
		cout<< "No!";

	return 0;
}
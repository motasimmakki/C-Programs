#include<iostream>
using namespace std;

bool isSubSequence(string str1, string str2){

	int ptr1, ptr2;
	for(ptr1 = 0, ptr2 = 0; (ptr1 < str1.length()) && (ptr2 < str2.length()); ptr1++){
		if(str1[ptr1] == str2[ptr2])
			ptr2++;
	}

	return (ptr2 == str2.length());
}

int main(){
	string str1 = "geeksforgeeks";
	// string str2 = "gksgs";
	// string str2 = "gksregks";
	string str2 = "gksreks";

	if(isSubSequence(str1, str2))
		cout<< "Yes!";
	else
		cout<< "No!";

	return 0;
}
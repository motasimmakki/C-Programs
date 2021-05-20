#include<iostream>
using namespace std;

bool isperfectSquare(int num){
	for(int i = 2; i < (num/2); i++){
		if((i*i) == num){
			cout<< "Yes! Num: "<< i<< " * "<< i<< endl;
			return true;
		}
	}
	return false;
}

int main(){

	int num = 9;
	// int num = 7;
	// int num = 4;
	// int num = 25;

	if(!(isperfectSquare(num)))
		cout<<"No!";

	return 0;
}

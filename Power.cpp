#include<iostream>
using namespace std;

// Function for computing x^n.
int getPower(int x, int n){

	int pow = 1;

	while(n){
		if(n%2){
			x = x*pow;
			cout<< "\n"<< x<< "---"<< pow;
		}
		pow *= 2;
		// n /= 2;
		n >>= 1;
	}

	return x;
}

int main(){

	cout<< "\nAnswer Is : "<< getPower(3, 10)<< endl;

	return 0;
}
#include<iostream>

long long int getFloorSqrt(long long int x) {
    if(x <= 1)
        return x;
    long long int result = 0;
    long long int l = 1, h = x;
    
    while(l <= h){
        long long int mid = l + (h-l)/2;
        
        if(mid*mid == x)
            return mid;
        if(mid*mid < x){
            l = mid + 1;
            result = mid;
        }
        else
            h = mid - 1;
    }
    
    return result;
}

int main() {
	// int num = 0; /// 0
	// int num = 1; /// 1
	// int num = 6; /// 2
	// int num = 5; /// 2
	// int num = 25; /// 5
	int num = 36; /// 6

	std::cout<< "\nFloor sqrt("<< num<< "): "<< getFloorSqrt(num)<< std::endl;

	return 0;
}
// Sample Input 01:
// [2,5,6,9,10]
// Sample Output:
// 2

// Sample Input 02:
// [7,5,6,8,3]
// Sample Output:
// 1

// Sample Input 03:
// [3,3]
// Sample Output:
// 3

#include<iostream>
#include<vector>
using namespace std;

int getGCD(int a, int b){
    if(b == 0)
        return a;
    return getGCD(b, a%b);
}
int findGCD(vector<int>& nums) {
    int max = nums[0];
    int min = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] > max)
            max = nums[i];
        else if(nums[i] < min)
            min = nums[i];
    }
    return getGCD(min, max);
}

int main(){
	vector<int> nums{2, 5, 6, 9, 10};
	// vector<int> nums{7, 5, 6, 8, 3};
	// vector<int> nums{3, 3};
	cout<< findGCD(nums);
	return 0;
}


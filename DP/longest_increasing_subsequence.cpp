#include<iostream>
#include<vector>
#include<algorithm>

int lengthOfLIS(std::vector<int> &nums) {
    int lis[2500] = {0};
    for(int i = 0; i < nums.size(); i++){
        int maxPrev = 0;
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                if(lis[j] > maxPrev){
                    maxPrev = lis[j];
                }
            }
        }
        lis[i] = maxPrev + 1;
    }
    
    return *std::max_element(lis, lis + nums.size());
}

int main(){
    // std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18}; // 4
    // std::vector<int> nums{0,1,0,3,2,3}; // 4
    std::vector<int> nums{7,7,7,7,7,7,7}; // 1

    std::cout<< "\nLength of longest Increasing Subsequence Is: "<< lengthOfLIS(nums)<< std::endl;
    return 0;
}
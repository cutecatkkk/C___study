#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;


class Solution {
public:
    static vector<int> sortArray(vector<int>& nums) {
        quicksort(nums,0,nums.size()-1);
        return nums;
    }

    static void quicksort(vector<int>& nums, int l,int r){
        if(l>=r)    return;
        int i=l-1,j=r+1;

        int x=nums[l+(r-l)/2];
        while(l<r){
            while(nums[++i]<x);
            while(nums[--j]>x);
            if(i<j) swap(nums[i],nums[j]);
        }
        quicksort(nums,l,j);
        quicksort(nums,j+1,r);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {5,1,1,2,0,0};
    Solution::sortArray(nums);
    return 0;
}

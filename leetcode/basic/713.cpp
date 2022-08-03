#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    static int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        unordered_set<int> numsset;
        int ans=0,r=0,l=0;
        int p=1;
        for(;r<nums.size();++r){
            p*=nums[r];
            while(l<=r&&p>=k) p/=nums[l++];
            ans+=r-l+1;
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums={1,2,3};
    int k=0;
    Solution::numSubarrayProductLessThanK(nums,k);
    return 0;
}

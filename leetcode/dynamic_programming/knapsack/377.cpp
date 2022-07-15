#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    static int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();

        vector<int> dp(target+1);
        dp[0]=1;

        for(int i=1;i<=target;i++){
            for(int num:nums){
                if(i>=num&&dp[i-num]<INT_MAX-dp[i]){
                    dp[i]+=dp[i-num];
                }
            }
        }

        return dp[target];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums={1,2,3};
    int target = 4;
    Solution::combinationSum4(nums,target);
    return 0;
}

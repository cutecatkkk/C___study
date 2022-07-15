#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    static int findTargetSumWays(vector<int>& nums, int target) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s < target || (s - target) % 2 != 0) return 0;
        int m = nums.size(), n = (s - target) / 2;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                dp[i][j] += dp[i - 1][j];
                if (nums[i - 1] <= j) dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[m][n];
    }

    static int one_dimensional_findTargetSumWays(vector<int>& nums, int target) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s < target || (s - target) % 2 != 0) return 0;
        int m = nums.size(), n = (s - target) / 2;
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=m;i++){
            for(int j=n;j>=nums[i-1];j--)
                dp[j]+=dp[j-nums[i-1]];
        }

        return dp[n];
    }


    static int myfindTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int m=nums.size(),n=(sum-target)/2;

        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++)  dp[i][0]=i;
        for(int i=1;i<=m;i++){
            for(int j=n;j>=nums[i-1];j--){
                dp[i][j]+=dp[i-1][j-nums[i-1]];
            }
        }

        return dp[m][n];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums={1,1,1,1,1};
    int target=3;
    Solution::findTargetSumWays(nums,target);
    Solution::one_dimensional_findTargetSumWays(nums,target);
    Solution::myfindTargetSumWays(nums,target);
    return 0;
}

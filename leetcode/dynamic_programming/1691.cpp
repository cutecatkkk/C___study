#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    static int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& c : cuboids) sort(c.begin(), c.end());
        sort(cuboids.begin(), cuboids.end());
        int n=cuboids.size();
        vector<int> dp(n);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(cuboids[j][1]<=cuboids[i][1]&&cuboids[j][2]<=cuboids[i][2])
                    dp[i]=max(dp[i],dp[j]);
            }
            dp[i]+=cuboids[i][2];
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> cuboids={{7,11,17},{7,17,11},{11,7,17},{11,18,6},{20,7,8},{17,11,7}};
    Solution::maxHeight(cuboids);
    return 0;
}

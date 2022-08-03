#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    static int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> presum;
        for(auto& p:piles){
            int m=p.size();
            vector<int> s(m+1);
            for(int i=0;i<m;i++)    s[i+1]=s[i]+p[i];
            presum.push_back(s);
        }

        vector<int> dp(k+1);
        for(auto&s:presum){
            for(int j=k;j>=0;j--){
                for (int idx = 0; idx < s.size(); ++idx)
                {
                    if (j >= idx) dp[j] = max(dp[j], dp[j - idx] + s[idx]);
                }
            }
        }

        return dp[k];
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> piles = {{100},{100},{100},{100},{100},{100},{1,1,1,1,1,1,700}};
    int target = 7;
    Solution::maxValueOfCoins(piles,target);
    return 0;
}
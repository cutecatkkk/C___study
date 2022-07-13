#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    static int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) { return a[1] < b[1]; });
        int n=intervals.size();
        vector<int> dp(n,1);
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(intervals[j][1]<=intervals[i][0])    dp[i]=max(dp[i],dp[j]+1);
            }
            if(dp[i]>ans)   ans=dp[i];
        }

        return n-ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> intervals = {{1,2}};
    int n = Solution::eraseOverlapIntervals(intervals);
    std::cout<<n<<std::endl;
    return 0;
}

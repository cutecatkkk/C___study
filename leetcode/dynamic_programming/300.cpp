#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    static int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> d{nums[0]};
        for (int i = 1; i < n; ++i)
        {
             if (nums[i] > d[d.size() - 1]) d.push_back(nums[i]);
            else
            {
                int idx = lower_bound(d.begin(), d.end(), nums[i]) - d.begin();
                if (idx == d.size()) idx = 0;
                d[idx] = nums[i];
            }
        }
        return d.size();
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {10,9,2,5,3,7,7,18};
    Solution::lengthOfLIS(nums);
    return 0;
}

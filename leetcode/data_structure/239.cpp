#include<iostream>
#include<vector>
#include<deque>
#include<stack>

using namespace std;

class Solution {
public:
    static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!q.empty() && i - k + 1 > q.front()) q.pop_front();
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    Solution::maxSlidingWindow(nums,3);
    return 0;
}

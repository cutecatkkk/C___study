#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    static int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        int n = envelopes.size();
        vector<int> d{envelopes[0][1]};
        for (int i = 1; i < n; ++i)
        {
            int x = envelopes[i][1];
            if (x > d[d.size() - 1]) d.push_back(x);
            else
            {
                int idx = lower_bound(d.begin(), d.end(), x) - d.begin();
                if (idx == d.size()) idx = 0;
                d[idx] = x;
            }
        }
        return d.size();
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> envelopes={{2,10},{3,11},{3,1},{4,12},{4,3},{5,4},{6,7}};
    Solution::maxEnvelopes(envelopes);
    return 0;
}

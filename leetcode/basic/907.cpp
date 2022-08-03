#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>

using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

class Solution {
public:
    static int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i)
        {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!stk.empty() && arr[stk.top()] > arr[i]) stk.pop();
            if (!stk.empty()) right[i] = stk.top();
            stk.push(i);
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans += (ll) (i - left[i]) * (right[i] - i) * arr[i] % mod;
            ans %= mod;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr={11,81,94,43,3};
    Solution::sumSubarrayMins(arr);
    return 0;
}

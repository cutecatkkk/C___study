#include<iostream>
#include<vector>
#include<deque>
#include<stack>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

class Solution {
public:
    static string shortestPalindrome(string s) {
        int base = 131;
        ull mul = 1;
        ull prefix = 0;
        ull suffix = 0;
        int idx = 0, n = s.size();
        for (int i = 0; i < n; ++i)
        {
            int t = s[i] - 'a' + 1;
            prefix = prefix * base + t;
            suffix = suffix + mul * t;
            mul *= base;
            if (prefix == suffix) idx = i + 1;
        }
        if (idx == n) return s;
        string x = s.substr(idx, n - idx);
        reverse(x.begin(), x.end());
        return x + s;
    }

    static string kmp_shortestPalindrome(string s) {
        int n = s.size();
        vector<int> fail(n, -1);
        for (int i = 1; i < n; ++i) {
            int j = fail[i - 1];
            while (j != -1 && s[j + 1] != s[i]) {
                j = fail[j];
            }
            if (s[j + 1] == s[i]) {
                fail[i] = j + 1;
            }
        }
        int best = -1;
        for (int i = n - 1; i >= 0; --i) {
            while (best != -1 && s[best + 1] != s[i]) {
                best = fail[best];
            }
            if (s[best + 1] == s[i]) {
                ++best;
            }
        }
        string add = (best == n - 1 ? "" : s.substr(best + 1, n));
        reverse(add.begin(), add.end());
        return add + s;
    }
};

int main(int argc, char const *argv[])
{
    string s = "aacecaaa";
    Solution::shortestPalindrome(s);
    Solution::kmp_shortestPalindrome(s);
    return 0;
}

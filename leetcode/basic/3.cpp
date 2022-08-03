#include<iostream>
#include<vector>
#include <numeric>
#include<unordered_set>

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = 0;
        unordered_set<char> chars;
        for (char& c : s)
        {
            while (chars.count(c)) chars.erase(s[i++]);
            chars.insert(c);
            ans = max(ans, j - i + 1);
            ++j;
        }
        return ans;

    }
};

int main(int argc, char const *argv[])
{
    string s="abcabcbb";
    Solution::lengthOfLongestSubstring(s);
    return 0;
}

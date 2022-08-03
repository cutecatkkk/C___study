#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{

public:
    vector<int> p;

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; i < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    ++ans;
                }
            }
        }
        return ans;
        // int m = grid.size();
        // int n = grid[0].size();
        // int ans = 0;
        // for (int i = 0; i < m; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         if (grid[i][j] == '1')
        //         {
        //             dfs(i, j, grid);
        //             ++ans;
        //         }
        //     }
        // }
        // return ans;
    }

    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        grid[i][j] = '2';
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k)
        {
            int x = i + dirs[k];
            int y = j + dirs[k + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1')
                dfs(x, y, grid);
        }
    }

    int bingcha_numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        p.resize(m * n);
        vector<int> dirs = {1, 0, 1};
        for (int i = 0; i < p.size(); ++i) p[i] = i;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    for (int k = 0; k < 2; ++k)
                    {
                        int x = i + dirs[k];
                        int y = j + dirs[k + 1];
                        if (x < m && y < n && grid[x][y] == '1')
                            p[find(x * n + y)] = find(i * n + j);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans += grid[i][j] == '1' && i * n + j == find(i * n + j);
        return ans;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    Solution s;
    s.bingcha_numIslands(grid);
    return 0;
}

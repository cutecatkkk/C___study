#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {-1, 0}, {-1, -1}};

        int n=grid.size();
        int ans=1;
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n));
        if(grid[0][0]==1)   return -1;
        vis[0][0]=true;
        q.emplace(0,0);
        while(!q.empty()){
            for(int k=q.size()-1;k>=0;--k){
                auto p=q.front();
                q.pop();
                if(p.first==n-1&&p.second==n-1) return ans;
                for(int s=0;s<8;++s){
                    int x=p.first+dirs[s][0];
                    int y=p.second+dirs[s][1];
                    if(x>=0&&x<n&&y>=0&&y<n&&grid[x][y]==0&&!vis[x][y]){
                        vis[x][y]=true;
                        q.emplace(x,y);
                    }
                }
            }
            ++ans;
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid={{0,1,1,1,1,1,1,1},{0,1,1,0,0,0,0,0},{0,1,0,1,1,1,1,0},{0,1,0,1,1,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,1,1,0,1,0},{0,0,0,0,0,1,1,0},{1,1,1,1,1,1,1,0}};
    int n=grid.size();
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<grid[i][j]<<"\t";
        }
        cout<<endl;
    }
    Solution s;
    s.shortestPathBinaryMatrix(grid);
    return 0;
}

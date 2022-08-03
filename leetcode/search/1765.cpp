#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    static vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(),n=isWater[0].size();
        vector<vector<int>> height(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(isWater[i][j]==1){
                    height[i][j]=0;
                    q.emplace(i,j);
                }
            }
        }
        vector<int> dirs={-1,0,1,0,-1};
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(int k=0;k<4;++k){
                int x=p.first+dirs[k];
                int y=p.second+dirs[k+1];
                if(x>=0&&x<m&&y>=0&&y<n&&height[x][y]==-1){
                    height[x][y]=height[p.first][p.second]+1;
                    q.emplace(x,y);
                }
            }
        }

        return height;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> isWater = {{0,1},{0,0}};
    Solution::highestPeak(isWater);
    return 0;
}

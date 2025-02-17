#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int path[202][202];
    
    int dp(vector<vector<int>>& grid, int i, int j){
        if(path[i][j] >= 0) return path[i][j];
        if(i==0 && j==0) return path[0][0] = grid[0][0];
        if(i==0) return path[0][j] = dp(grid, 0, j-1) + grid[0][j];
        if(j==0) return path[i][0] = dp(grid, i-1, 0) + grid[i][0];
        return path[i][j] = min(dp(grid, i-1, j), dp(grid, i, j-1)) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                path[i][j] = -1;
            }
        }
        return dp(grid, m-1, n-1);
    }
};
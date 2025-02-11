#include<bits/stdc++.h>
using namespace std;

const int max_n = 305;
int visited[max_n][max_n];

void dfs(vector<vector<char>>& grid, int x, int y){
    if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()) return;
    if(visited[x][y] || grid[x][y] == '0') return;
    visited[x][y] = 1;
    dfs(grid, x+1, y);
    dfs(grid, x, y+1);
    dfs(grid, x-1, y);
    dfs(grid, x, y-1);
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        memset(visited, 0, sizeof(visited));

        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    ans ++ ;
                    dfs(grid, i, j);
                }
            }
        }
        
        return ans;
        
    }
};
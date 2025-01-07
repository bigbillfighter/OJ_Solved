#include <bits/stdc++.h>
using namespace std;

const int max_N = 52;

class Solution {
public:
    int visited[max_N][max_N] = {0};
    int dfs(vector<vector<int>>& grid, int row, int col){
        // out of range 
        if (row < 0  || col < 0){
            return 0;
        }else if (row>=grid.size() || col >= grid[0].size()){
            return 0;
        }else if (visited[row][col]){
            return 0;
        }else if (!grid[row][col]){
            visited[row][col] = 1;
            return 0;
        }
        visited[row][col] = 1;
        return 1 + dfs(grid, row-1, col) + dfs(grid, row+1, col) + dfs(grid, row, col-1) + dfs(grid, row, col+1);

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();
        int max_area=0;

        for (int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                max_area = max(max_area, dfs(grid, i, j));
            }
        }
        return max_area;
    }
};


int main(){
    // improve is speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;
    int m, n;
    int island;
    cin >> m >> n;
    vector<vector<int> > grid;
    for(int i=0; i<m; i++){
        vector<int> line;
        for(int j=0; j<n; j++){
            cin >> island;
            line.push_back(island);
        }
        grid.push_back(line);
    }

    int rst = solu.maxAreaOfIsland(grid);
    cout << rst << endl;
    return 0;
}
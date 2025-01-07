#include <bits/stdc++.h>
using namespace std;

const int max_n = 7;

class Solution {
public:
    int visited[max_n][max_n] = {0};

    bool dfs(vector<vector<char> >& grid, string& target, int x, int y, int start, int end){
        if(start==end){return true;}

        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()){
            return false;
        }
            
        if(!visited[x][y] && grid[x][y]==target[start]){
            visited[x][y] = 1;
            bool down = dfs(grid, target, x+1, y, start+1, end);
            bool right = dfs(grid, target, x, y+1, start+1, end);
            bool up = dfs(grid, target, x-1, y, start+1, end);
            bool left = dfs(grid, target, x, y-1, start+1, end);

            bool rst = (down || right || up || left);
            if(!rst){
                visited[x][y] = 0;
            }                
            return rst;
        }else{
            return false;
        }
    }

    bool wordPuzzle(vector<vector<char>>& grid, string target) {
        int m = grid.size(), n=grid[0].size();
        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                fill_n(visited[0], max_n*max_n, 0);
                if(dfs(grid, target, i, j, 0, target.size())){
                    return true;
                }
            }
        }
        return false;
        
    }
}; 



int main(){
    // improve is speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;
    int m, n;
    char island;
    cin >> m >> n;
    vector<vector<char> > grid;
    for(int i=0; i<m; i++){
        vector<char> line;
        for(int j=0; j<n; j++){
            cin >> island;
            line.push_back(island);
        }
        grid.push_back(line);
    }
    string ss;
    cin >> ss;

    bool rst = solu.wordPuzzle(grid, ss);
    cout << rst << endl;
    return 0;
}
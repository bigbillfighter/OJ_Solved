#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

    }
};


int main(){
    // improve io speed
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
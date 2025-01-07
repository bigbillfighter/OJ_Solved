#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    
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
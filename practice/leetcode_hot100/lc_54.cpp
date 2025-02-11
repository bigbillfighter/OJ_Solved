#include <bits/stdc++.h>
using namespace std;

const int max_size = 12;
int visited[max_size][max_size];

int direc[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(vector<vector<int>>& matrix, vector<int>& rst, int x, int y, int direction){
    if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()) return;
    if(visited[x][y]) return;

    rst.push_back(matrix[x][y]);
    visited[x][y] = 1;
    dfs(matrix, rst, x+direc[direction][0], y+direc[direction][1], direction);
    dfs(matrix, rst, x+direc[(direction + 1) % 4][0], y+direc[(direction + 1) % 4][1], (direction + 1) % 4);
    dfs(matrix, rst, x+direc[(direction + 2) % 4][0], y+direc[(direction + 2) % 4][1], (direction + 2) % 4);
    dfs(matrix, rst, x+direc[(direction + 3) % 4][0], y+direc[(direction + 3) % 4][1], (direction + 3) % 4);
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        memset(visited, 0, sizeof(visited));
        vector<int> rst;
        int direction = 0;
        dfs(matrix, rst, 0, 0, 0);
        return rst;
    }
};
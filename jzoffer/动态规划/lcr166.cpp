#include <bits/stdc++.h>
using namespace std;

const int max_len = 205;

class Solution {
public:
    int dp[max_len][max_len] = {0};
    int jewelleryValue(vector<vector<int>>& frame) {
        return max_value(frame, 0, 0);
    }

    int max_value(vector<vector<int>>& frame, int row, int col){
        if(!(row>=0 && row<frame.size()) || !(col>=0 && col<frame[0].size())) return 0; 
        if(dp[row][col] == 0){
            dp[row][col] = frame[row][col];
            return dp[row][col] = max(max_value(frame, row+1, col), max_value(frame, row, col+1)) + dp[row][col];
        }else{
            return dp[row][col];
        }
    }
};

int main(){
    // improve is speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;
    int m, n;
    int value;
    cin >> m >> n;
    vector<vector<int> > frame;
    for(int i=0; i<m; i++){
        vector<int> line;
        for(int j=0; j<n; j++){
            cin >> value;
            line.push_back(value);
        }
        frame.push_back(line);
    }

    int rst = solu.jewelleryValue(frame);
    cout << rst << endl;
    return 0;
}
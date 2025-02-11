int dp_arr[102][102];
#include <bits/stdc++.h>
using namespace std;
    
int dp(int x, int y){
    if(x==0 && y==0) return dp_arr[0][0] = 1;
    if(dp_arr[x][y]!=0) return dp_arr[x][y];

    if(x==0) return dp_arr[0][y] = dp(0, y-1);
    if(y==0) return dp_arr[x][0] = dp(x-1, 0);
    return dp_arr[x][y] = dp(x-1, y) + dp(x, y-1);
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        memset(dp_arr, 0, sizeof(dp_arr));
        return dp(m-1, n-1);
    }
};
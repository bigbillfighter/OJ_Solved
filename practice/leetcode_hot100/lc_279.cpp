#include<bits/stdc++.h>
using namespace std;

const int max_n = 10005;
int dp[max_n];

class Solution {
public:
    int numSquares(int n) {
        int ans = 0;
        int max_nbr = (int)sqrt((float)n+0.5);
        fill(dp, dp+max_n, n);
        for(int i=1; i<=max_nbr; i++) dp[i*i] = 1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=max_nbr; j++){
                if(i - j*j < 1) break;
                else dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp[n];
    }
};
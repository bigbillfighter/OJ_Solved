#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e4+5;
int dp[max_n];
const int crt_max = 0x3f3f3f3f;

class Solution {
public:
    int dp_fun(vector<int>& coins, int clen, int amount){
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        if(dp[amount] != 0) return dp[amount];
        int res, crt = crt_max;
        for(int i=0; i<clen; i++){
            res = dp_fun(coins, clen, amount-coins[i]) + 1;
            if(res > 0) {
                crt = min(crt, res);
            }
        }
        dp[amount] = crt < crt_max ? crt : -1;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int clen = coins.size();
        fill(dp, dp+amount+5, 0);
        return dp_fun(coins, clen, amount);
    }
};
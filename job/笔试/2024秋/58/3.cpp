#include<bits/stdc++.h>
using namespace std;

const int mod_n = 1e9+7;
const int max_n = 1e3+5;
int dp[max_n][max_n];

int dp_func(int place, int res){
    if(place<0) return 0;

    if(res == place){
        if(res == 0) return dp[place][res] = 1;
        else return dp[place][res] = 2;
    }
    if(place > res){
        return dp[place][res] = 0;
    }
    
    int kk = res -place;
    for(int i=0; i<=kk; i+=2){
        dp[place][res] += dp_func(place-i, res-i);
        dp[place][res] %= mod_n;
        dp[place][res] += dp_func(place+i, res-i);
        dp[place][res] %= mod_n;
        dp[place][res] += dp_func(place, res-i) * 2;
        dp[place][res] %= mod_n;
    }
    return dp[place][res];
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param startPos int整型 
     * @param endPos int整型 
     * @param k int整型 
     * @return int整型
     */
    int numberOfWays(int startPos, int endPos, int k) {
        // write code here
        fill(dp[0], dp[0]+max_n*max_n, 0);

        if(endPos-startPos > k) return 0;
        if((k - (endPos-startPos)) % 2 !=0 ) return 0;

        int res = k - (endPos-startPos);

        int ans = 0;
        for(int i=0; i<=res; i+=2){
            ans += dp_func(i, res-i);
            ans %= mod_n;
            if(i!=0){
                ans += dp_func(i, res-i);
                ans %= mod_n;
            }
        }
        return ans;

    }
};
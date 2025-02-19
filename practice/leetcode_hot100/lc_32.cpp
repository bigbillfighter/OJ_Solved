#include <bits/stdc++.h>
using namespace std;

const int max_n = 3e4+5;
int dp[max_n];

class Solution {
public:
    int longestValidParentheses(string s) {
        fill(dp, dp+max_n, 0);
        for(int i=0; i<s.size(); i++){
            if(s[i] == ')'){
                if(i > 0 && s[i - 1] == '(') {
                    if(i >= 2) dp[i] = dp[i-2] + 1;
                    else dp[i] = 1;
                }else if(i > 0){
                    if(i - dp[i-1] * 2 - 1 >=0 && s[i - dp[i-1] * 2 - 1] == '('){
                        dp[i] = dp[i-1] + 1;
                        if(i - dp[i-1] * 2 - 2 >= 0) dp[i] += dp[i - dp[i-1] * 2 - 2];
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            ans = max(ans, dp[i]*2);
        }
        return ans;
    }
};
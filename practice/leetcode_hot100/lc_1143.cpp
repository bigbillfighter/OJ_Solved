#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1002][1002];

    int dp_fun(string& text1, string& text2, int i, int j){
        if(i <0 || j <0) return 0;
        if(dp[i][j] >= 0) return dp[i][j];

        if(text1[i] == text2[j]) return dp[i][j] = dp_fun(text1, text2, i-1, j-1) + 1;
        else{
            return dp[i][j] = max(dp_fun(text1, text2, i-1, j), dp_fun(text1, text2, i, j-1));
        }

    }

    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        for(int i=0; i<len1; i++) for(int j=0; j<len2; j++) dp[i][j] = -1;

        int ans = dp_fun(text1, text2, len1-1, len2-1);
        return ans;

    }
};
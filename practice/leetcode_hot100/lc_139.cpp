#include <bits/stdc++.h>
using namespace std;

int dp[1002];

class Solution {
public:
    int dp_fun(string s, vector<string>& wordDict){
        int slen = s.size(), wlen;
        if(dp[slen-1] >= 0) return dp[slen-1];

        string crt;
        for(int i=0; i<wordDict.size(); i++){
            crt = wordDict[i];
            wlen = crt.size();
            if(slen < wlen) continue;

            if(slen == wlen && s == crt){
                return dp[slen-1] = 1;
            }

            if(slen > wlen && s.substr(slen-wlen, wlen) == crt){
                dp[slen-1] = dp_fun(s.substr(0, slen-wlen), wordDict);
                if(dp[slen-1]) return dp[slen-1] = 1;
            }

        }

        return dp[slen-1] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        fill(dp, dp+1002, -1);
        bool ans = dp_fun(s, wordDict) == 1;
        return ans;
    }
};
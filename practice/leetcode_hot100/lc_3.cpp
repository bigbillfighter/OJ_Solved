#include <bits/stdc++.h>
using namespace std;

const int max_n = 150;
int last_place[max_n];

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        memset(last_place, -1, sizeof(last_place));
        if(s.size() == 0) return 0;

        int last = 0;
        int rst = 1;
        for(int i=0; i<s.size(); i++){
            if(last_place[s[i]] >= 0 && last_place[s[i]] - last >= 0){
                int crt = i - last;
                rst = rst < crt ? crt : rst;
                last = last_place[s[i]] + 1;
                last_place[s[i]] = i;
            }else{
                last_place[s[i]] = i;
            }
        }

        rst = rst < (s.size() - last) ? (s.size() - last) : rst;
        return rst;
    }
};
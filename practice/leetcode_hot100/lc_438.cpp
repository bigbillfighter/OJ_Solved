#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> rst;
        int s_len = s.size(), p_len = p.size();
        if(p_len > s_len) return rst;
        string subs = s.substr(0, p_len);
        sort(subs.begin(), subs.end());
        sort(p.begin(), p.end());
        if(subs == p) rst.push_back(0);

        for(int i=1; i<=s_len-p_len; i++){
            int last = i-1;
            int now = i+p_len-1;
            for(int j=0; j<p_len; j++){
                if(subs[j] == s[last]){
                    subs[j] = s[now];
                    while(j>=1 && subs[j]<subs[j-1]){
                        char c = subs[j];
                        subs[j] = subs[j-1];
                        subs[j-1] = c;
                        j--;
                    }
                    while(j<p_len-1 && subs[j]>subs[j+1]){
                        char c = subs[j];
                        subs[j] = subs[j+1];
                        subs[j+1] = c;
                        j++;
                    }

                    if(subs == p) rst.push_back(i);

                    break;
                }
            }
        }

        return rst;
    }
};
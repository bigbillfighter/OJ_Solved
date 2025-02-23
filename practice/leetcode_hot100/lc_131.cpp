#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_reverse(string ss){
        int slen = ss.size();
        for(int i=0; i<slen/2; i++){
            if(ss[i] != ss[slen-i-1]) return false;
        }
        return true;
    }

    void gen_ans(vector<vector<string> >& ans, vector<string>& crt, string s, int slen){
        if(s == ""){
            ans.push_back(crt);
            return;
        }

        for(int clen=1; clen<=slen; clen++){
            if(is_reverse(s.substr(0, clen))){
                crt.push_back(s.substr(0, clen));
                gen_ans(ans, crt, s.substr(clen, slen-clen), slen-clen);
                crt.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> crt;
        gen_ans(ans, crt, s, s.size());
        return ans;
    }
};
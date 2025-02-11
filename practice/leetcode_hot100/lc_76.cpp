#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> ss;
        int t_len = t.size(), s_len = s.size();
        int sum_key = 0;
        for(int i=0; i<t_len; i++){
            if(!ss.count(t[i])){
                ss[t[i]] = 1;
                sum_key ++;
            }else{
                ss[t[i]]++;
            }
        }
        map<char, int> s_crt;
        for(int i=0; i<s_len; i++){
            if(ss.count(s[i]) > 0){
                if(s_crt.count(s[i])){
                    s_crt[s[i]]++;
                }else{
                    s_crt[s[i]] = 1;
                }
            }
        }
        for(map<char, int>::iterator it=ss.begin(); it!=ss.end(); it++){
            if(!s_crt.count(it->first) || s_crt[it->first] < it->second) return "";
        }

        map<char, int> crt;
        int end_idx = 0;
        int match_sum = 0;

        for(int i=0; i<s_len; i++){
            if(!crt.count(s[i])){
                crt[s[i]] = 1;
            }else{
                crt[s[i]]++;
            }

            if(ss.count(s[i]) && crt[s[i]] ==ss[s[i]]){
                match_sum++;
            }

            if(match_sum == sum_key) {
                end_idx = i;
                break;
            }
        }

        int start = 0;
        int rst_start=0, rst_len = end_idx+1;

        while(!ss.count(s[start]) || crt[s[start]] > ss[s[start]]){
            crt[s[start]]--;
            start++;
        }

        rst_start = start;
        rst_len = end_idx+1-rst_start;

        for(int i=end_idx+1; i<s_len; i++){
            if(!crt.count(s[i])){
                crt[s[i]] = 1;
            }else{
                crt[s[i]] ++;
            }

            if(ss.count(s[i])){
                while(!ss.count(s[start]) || crt[s[start]] > ss[s[start]]){
                    crt[s[start]]--;
                    start++;
                }
                if(i+1 - start < rst_len){
                    rst_len = i+1-start;
                    rst_start = start;
                }
            }
        }

        return s.substr(rst_start, rst_len);
    }
};
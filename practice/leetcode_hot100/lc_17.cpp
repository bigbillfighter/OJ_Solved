#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void find_next(string& digits, unordered_map<char, string>& phoneMap, int crt_idx, const int & len, string crt, vector<string>& ans){
        if(crt_idx == len){
            ans.push_back(crt);
            return;
        }
        char crt_chart = digits[crt_idx];
        for(int i=0; i<phoneMap[crt_chart].size(); i++){
            crt.push_back(phoneMap[crt_chart][i]);
            find_next(digits, phoneMap, crt_idx+1, len, crt, ans);
            crt.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        int len = digits.size();
        vector<string> ans;
        if(!len) return ans;
        find_next(digits, phoneMap, 0, len, "", ans);
        return ans;

    }
};
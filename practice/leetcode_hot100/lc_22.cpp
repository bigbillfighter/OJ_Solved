#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generate(vector<string>& ans, string& crt, int n, int left, int right){
        if(left == n && right == n){
            ans.push_back(crt);
            return;
        }

        if(right > left || left > n || right > n) return;
        else if(right < left){
            crt.push_back('(');
            generate(ans, crt, n, left+1, right);
            crt.pop_back();
            crt.push_back(')');
            generate(ans, crt, n, left, right+1);
            crt.pop_back();
        }else{
            crt.push_back('(');
            generate(ans, crt, n, left+1, right);
            crt.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string crt = "";
        generate(ans, crt, n, 0, 0);
        return ans;
    }
};
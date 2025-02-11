#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> crt;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') crt.push(s[i]);
            else if(s[i]==')'){
                if(crt.empty() || crt.top() != '(') return false;
                else crt.pop();
            }
            else if(s[i]==']'){
                if(crt.empty() || crt.top() != '[') return false;
                else crt.pop();
            }
            else if(s[i]=='}'){
                if(crt.empty() || crt.top() != '{') return false;
                else crt.pop();
            }
        }

        if(!crt.empty()) return false;
        return true;
    }
};
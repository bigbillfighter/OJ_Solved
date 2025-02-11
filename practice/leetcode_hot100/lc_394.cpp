#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<string> hlf;
        int s_size = s.size();
        int idx = 0, crt_idx, crt_times;
        string crt, s_crt;
        
        while(idx < s_size){
            if(s[idx] >= '0' && s[idx] <= '9'){
                crt = "";
                crt += s[idx++];
                while(s[idx] >= '0' && s[idx] <= '9'){
                    crt += s[idx++];
                }
                hlf.push(crt);
            }else if(s[idx] == '['){
                hlf.push("[");
                idx ++;

            }else if(s[idx] == ']'){
                crt = "";
                while(hlf.top()!="["){
                    crt = hlf.top() + crt;
                    hlf.pop();
                }
                hlf.pop();
                crt_times = stoi(hlf.top());
                hlf.pop();
                s_crt = "";
                for(int i=0; i<crt_times; i++) s_crt += crt;
                hlf.push(s_crt);
                idx ++;
            }else{
                // character
                crt = "";
                while(s[idx] >= 'a' && s[idx] <= 'z'){
                    crt += s[idx++];
                }
                hlf.push(crt);
            }
        }
        crt = "";
        while(!hlf.empty()){
            crt = hlf.top() + crt;
            hlf.pop();
        }
        return crt;
    }
};
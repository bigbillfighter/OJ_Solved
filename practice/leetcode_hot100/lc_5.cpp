#include<bits/stdc++.h>
using namespace std;

bool is_palindrome[1002][1002];

class Solution {
public:
    string longestPalindrome(string s) {
        int slen = s.size();
        for(int i=0; i<=slen; i++){
            for(int j=0; j<=slen; j++){
                is_palindrome[i][j] = false;
            }
        }
        int max_len = 1;
        string ans = s.substr(0, 1);
        for(int i=0; i<slen; i++) is_palindrome[i][1] = is_palindrome[i][0] = true;

        for(int i=1; i<slen; i++){
            for(int j=2; j<=i+1; j++){
                if(i-j+1 >=0 && is_palindrome[i-1][j-2] && s[i] == s[i-j+1]){
                    is_palindrome[i][j] = true;
                    if(j > max_len){
                        max_len = j;
                        ans = s.substr(i-j+1, j);
                    }
                }
            } 
        }
        return ans;

    }
};
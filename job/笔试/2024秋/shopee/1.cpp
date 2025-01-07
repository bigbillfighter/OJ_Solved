#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * 
     * @param s string字符串  
     * @return bool布尔型
     */
    bool valid_palindrome(string s) {
        // write code here
        int flag = true;
        int s_size = s.size();
        for(int i=0; i<(s_size / 2); i++){
            if(s[i]!=s[s_size-i-1]){
                flag = false;
                break;
            }
        }
        if(flag){
            return true;
        }

        string left_str;
        int left_size = s_size-1;

        for(int i=0; i<s_size; i++){
            if(i==0){
                left_str = s.substr(1, s_size-1);
            }else if(i==(s_size-1)){
                left_str = s.substr(0, s_size-1);
            }else{
                left_str = s.substr(0, i) + s.substr(i+1, s_size-1-i);
            }

            flag = true;
            for(int j=0; j<(left_size/ 2); j++){
                if(left_str[j]!=left_str[left_size-j-1]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return true;
            }
        }
        return false;

    }
};


int main(){
    Solution solu;
    string ss;
    cin >> ss;
    solu.valid_palindrome(ss);
    return 0;
}
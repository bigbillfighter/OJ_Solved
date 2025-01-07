#include<bits/stdc++.h>
using namespace std;


const int max_n = 505;
int a[max_n], b[max_n];

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return int整型
     */
    int StringSplit(string str) {
        // write code here
        int str_len = str.size();
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        if(str[0]=='a') a[0]++;
        for(int i=1; i<str_len; i++){
            if(str[i]=='a') a[i] = a[i-1] + 1;
            else a[i] = a[i-1];
        }

        if(str[str_len-1]=='b') b[str_len-1] = 1;
        for(int i=str_len-2; i>=0; i--){
            if(str[i]=='b') b[i] = b[i+1] + 1;
            else b[i] = b[i+1];
        }

        int ans = 0;
        for(int i=1; i<str_len; i++){
            ans = max(ans, a[i-1] + b[i]);
        }
        return ans;

    }
};
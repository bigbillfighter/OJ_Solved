#include <bits/stdc++.h>
using namespace std;


const int max_n = 40;

class Solution {
public:

    // dp[i] = dp[i-1] + dp[i-2]    
    int dp[max_n] = {0};
    
    int max_solu(int i){
        if(i==0) return dp[0]=0;
        if(i==1) return dp[1]=1;
        if(i==2) return dp[2]=2;
        if(dp[i]) return dp[i];
        return dp[i] = max_solu(i-1) + max_solu(i-2);    
    }

    int rectCover(int number) {
        return max_solu(number);
    }
};


int main(){
    // improve is speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;

    int number;
    cin>>number;
    int rst = solu.rectCover(number);
    cout << rst << endl;
    return 0;
}
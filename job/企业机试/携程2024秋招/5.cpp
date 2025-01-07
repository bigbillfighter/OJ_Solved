#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int max_n = 1e5+5;
ll dp[max_n] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    ll ans = 0;
    for(int i=0; i<str.size(); i++){
        if(i==0){
            if(str[i]=='0'){
                dp[i] = 1;
            }else{
                dp[i] = 0;
            }
        }else{
            if(str[i]=='0'){
                dp[i] = dp[i-1] + 1;
            }else{
                dp[i] = max(dp[i-1] - 1 , (ll)0);
            }
        }
        ans += dp[i];
    }

    cout << ans << endl;

    return 0;
}
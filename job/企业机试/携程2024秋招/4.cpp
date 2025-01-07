#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int n, l, r;
    ll rst_left, rst_right;
    
    ll sum;
    ll tdata, ans;
    for(int i=0; i<t; i++){
        cin>>n>>l>>r;
        rst_left = rst_right = 0;
        sum = 0;
        ans = 0;

        for(int j=0; j<n; j++){
            cin >> tdata;
            sum += tdata;
            if(tdata < l){
                rst_left += l-tdata;
            }else if(tdata > r){
                rst_right += tdata-r;
            }
        }

        if(sum / n < l || (sum+n-1)/n > r){
            ans = -1;
        }else{
            ans = max(rst_left, rst_right);
        }
        cout << ans<<endl;
    }

    return 0;
}
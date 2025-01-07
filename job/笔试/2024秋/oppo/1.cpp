#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    if(k == 1){
        cout << n - m << endl;
    }else{
        int ans = 0;
        while(n > m){
            if(n < k * m){
                ans += n - m;
                n = m;
            }else{
                if(n%k!=0){
                    ans += n%k;
                    n -= n%k;
                }else{
                    n /= k;
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
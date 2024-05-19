#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n, ans;
    while(true){
        ans = 0;
        cin >> n;
        if (n < 1) break;
        while(n >= 3){
            ans += n/3;
            n = n/3 + n - (n/3)*3;
        }

        if (n == 2){
            ans ++ ;
        }
        cout << ans << endl;
    }

    return 0;
}
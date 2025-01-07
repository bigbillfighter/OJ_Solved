#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e5+5;
int a[max_n];

int crt_gcd(int a, int b){
    if(a%b == 0) {
        return b;
    }
    else return crt_gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int ans = 1;
    int start = 0;
    for(int i=1; i<n; i++){
        bool flag = true;
        for(int j=i-1; j>=start; j--){
            // cout << crt_gcd(a[i], a[j]) << endl;
            if(crt_gcd(a[i], a[j]) > 1){
                flag = false;
                ans = max(ans, i-j);
                start = j+1;
                break;
            }
        }
        if(flag) ans = max(ans, i-start+1);
    }

    cout << ans << endl;

    // int start_idx = 0, end_idx = 1;
    // while(end_idx < n){
    //     int flag = true;
    //     for(int i=start_idx; i<end_idx; i++){
    //         if(crt_gcd(a[i], a[end_idx]) != 1){
    //             flag = false;
    //             start_idx = i;
    //             break;
    //         }
    //     }
    //     if(flag){
    //         end_idx ++;
    //     }else{
    //         ans = end_idx;
    //         break;
    //     }
    // }

    // if(end_idx == 0){
    //     ans = n;
    //     cout << ans << endl;
    // }else{
    //     while(end_idx < n){
    //         int len = end_idx - start_idx;
    //         end_idx += max(1, ans - len);
    //         end_idx = min(end_idx, n-1);
    //         int flag = true;

    //         for(int i=end_idx-1; i>=start_idx; i++){
    //             if(crt_gcd(a[i], a[end_idx]) != 1){
    //                 flag = false;
    //                 ans = max(ans, end_idx-i);
    //                 start_idx = i;
    //                 break;
    //             }
    //         }
    //         if(flag){
    //             ans = max(ans, end_idx-start_idx+1);
    //         }
    //     }

    //     cout << ans << endl;
    // }

    return 0;
}
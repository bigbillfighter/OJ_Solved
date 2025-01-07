#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e5+5;
int a[max_n];
int a_start[max_n];
int a_end[max_n];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    int n, K;
    
    int ans;

    int left_ans, right_ans;
    while(T--){
        cin >> n >> K;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        a_start[0] = a[0];
        a_end[n-1] = a[n-1];
        for(int i=1; i<n; i++){
            a_start[i] = max(a[i], a_start[i-1] + a[i]);
        }
        for(int i=1; i<n; i++){
            a_start[i] = max(a_start[i], a_start[i-1]);
        }
        
        // for(int i=0; i<n; i++){
        //     cout << a_start[i] << " ";
        // }
        // cout << endl;

        for(int i=n-2; i>=0; i--){
            a_end[i] = max(a[i], a_end[i+1] + a[i]);
        }
        for(int i=n-2; i>=0; i--){
            a_end[i] = max(a_end[i+1], a_end[i]);
        }

        // for(int i=0; i<n; i++){
        //     cout << a_end[i] << " ";
        // }
        // cout << endl;


        for(int i=0; i<(n-K-1); i++){
            left_ans = a_start[i];
            right_ans = a_end[i+K+1];
            if(i==0) ans = left_ans + right_ans;
            else ans = max(ans, left_ans + right_ans);
        }
        cout << ans << endl;
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int max_n = 102;
int a[max_n];
int rst[max_n];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(rst, rst+max_n, 1);
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    int ans = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[i] > a[j]){
                rst[i] = max(rst[i], rst[j] + 1);
            }
        }
        ans = max(ans, rst[i]);
    }
    cout << ans << endl;

    return 0;
}
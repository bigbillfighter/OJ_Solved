#include<bits/stdc++.h>
using namespace std;

const int max_n = 2e5+5;
typedef long long ll;
ll a[max_n];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    ll n, k, x;
    ll min_cost = 0;
    ll min_right = 0;
    
    while(T--){
        cin >> n >> k >> x;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        map<ll, bool> rst;
        min_cost = n * x;
        min_right = 0;
        for(int i=n-1; i>=0; i--){
            rst[a[i]] = true;
            if(a[i] == min_right){
                min_right++;
                while(rst.count(min_right) > 0){
                    min_right++;
                }
            }
            min_cost = min(min_cost, min_right*k + x * i);
        }
        cout << min_cost << endl;

    }

    return 0;
}
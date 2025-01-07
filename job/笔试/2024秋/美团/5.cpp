#include<bits/stdc++.h>
using namespace std;

const int max_n = 2e5+5;
int nxt[max_n];
int wet[max_n];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q, x, y;
    cin >> n >> q >> x >> y;
    for(int i=1; i<=n; i++){
        cin >> nxt[i];
    }
    for(int i=1; i<=n; i++){
        cin >> wet[i];
    }

    int u, k;
    while(q--){
        cin >> u >> k;
        int ans = 0;

        int pre_sum = 0;
        while(k--){
            if(wet[u] > wet[nxt[u]]){
                pre_sum += x;
            }else{
                pre_sum += y;
            }
            u = nxt[u];
            ans = max(ans, pre_sum);
        }

        cout << ans << endl;
    }

    return 0;
}
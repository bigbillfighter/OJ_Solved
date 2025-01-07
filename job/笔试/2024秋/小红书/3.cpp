#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e4+5;
typedef long long LL;
map<int, LL> dis[max_n];

vector<int> connected[max_n];

void dfs(int idx, int middle, int n){
    if(dis[idx].size() == n) return;

    for(int i=0; i<connected[middle].size(); i++){
        if(!dis[idx].count(connected[middle][i])){
            dis[idx][connected[middle][i]] = dis[idx][middle] ^ dis[middle][connected[middle][i]];
            dfs(idx, connected[middle][i], n);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q; cin >> n >> q;
    
    int left, right;
    LL w;
    for(int i=0; i<n-1; i++){
        cin >> left >> right >> w;
        connected[left].push_back(right);
        connected[right].push_back(left);
        dis[left][right] = w;
        dis[right][left] = w;
    }
    for(int i=1; i<=n; i++){
        dis[i][i] = 0;
    }

    int u; LL k;
    int ans = 0;
    while(q--){
        cin >> u >> k;
        for(int i=0; i<connected[u].size(); i++){
            dfs(u, connected[u][i], n);
        }
        
        ans = 0;
        for(int i=1; i<=n; i++){
            if(dis[u][i] == k) ans ++;
        }
        cout << ans << endl;
    }


    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int max_n = 505;
typedef long long LL;

LL cost[max_n][max_n];
LL val_map[26][26];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            cin >> val_map[i][j];
        }
    }

    string ss; cin >> ss;

    fill(cost[0], cost[0] + max_n*max_n, 0);

    for(int j=2; j<=n; j+=2){
        for(int i=0; i<n; i++){
            if(i+j > n) break;// start from i, len=j
            LL val = val_map[ss[i] - 'a'][ss[i+1] - 'a'] + cost[i+2][j-2];

            for(int idx=i+3; idx<i+j; idx+=2){

                val = max(cost[i+1][idx-i-1] + cost[idx+1][i+j-idx-1] + val_map[ss[i] - 'a'][ss[idx] - 'a'], val);

            }
            cost[i][j] = val;
        }
    }
    
    cout << cost[0][n] << endl;

    return 0;
}
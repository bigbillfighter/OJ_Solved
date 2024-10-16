#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e3+5;
int ps[max_n];
int calcu[max_n];
int ans = 0x3f3f3f3f;

void dfs(int cur, int n, int ticket, int pre_sum){
    if(cur == n){
        ans = min(ans, pre_sum);
        return;
    }

    if(calcu[cur]){
        ticket += ps[cur];
        pre_sum += ps[cur]; 
    }

    
    if(ticket >= 100){
        ticket -= 100;
        for(int i=cur+1; i<min(n, cur+4); i++){
            if(calcu[i]){
                calcu[i] = 0;
                dfs(cur+1, n, ticket, pre_sum);
                calcu[i] = 1;
            }
        }
    }else{
        dfs(cur+1, n, ticket, pre_sum);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    int n;

    while(T--){
        cin >> n;
        ans = 0x3f3f3f3f;
        for(int i=0; i<n; i++){
            cin >> ps[i];
            calcu[i] = 1;
        }

        dfs(0, n, 0, 0);
        cout << ans << endl;

    }

    return 0;
}
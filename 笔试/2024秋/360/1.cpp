#include<bits/stdc++.h>
using namespace std;

bool visited[42];
int customers[22][2];

int ans = 0;

void trace(int cur, int n){
    if(cur == n){
        int times = 0;
        for(int i=0; i<42; i++){
            if(visited[i]) times ++;
        }
        ans = max(ans, times / 2);
        return;
    }

    if((!visited[customers[cur][0]]) && (!visited[customers[cur][1]])){
        visited[customers[cur][0]] = 1;
        visited[customers[cur][1]] = 1;
        trace(cur+1, n);
        visited[customers[cur][0]] = 0;
        visited[customers[cur][1]] = 0;
        trace(cur+1, n);

    }else{
        trace(cur+1, n);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int m; cin >> m;
    fill(visited, visited+42, 0);

    int x, y;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        customers[i][0] = x-1; customers[i][1] = y-1;
    }

    trace(0, n);
    cout << ans << endl;
    return 0;
}
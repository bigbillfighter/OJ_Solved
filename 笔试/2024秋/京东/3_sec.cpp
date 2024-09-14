#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e3+5;
typedef long long LL;
int coord[max_n][2];
LL dis[max_n][max_n];
int visited[max_n];

float eps = 1e-6;


void find_min(int n, LL min_nbr, int last){
    int flag = true;
    for(int i=0; i<n; i++){
        if(visited[i]){
            flag = false;
            break;
        }
    }

    if(flag) return ;


    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = 1;
            min_nbr = max(min_nbr, dis[i][last]);
            find_min(n, min_nbr, i);
            visited[i] = 0;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(visited, 0, sizeof(visited));
    fill(dis[0], dis[0] + max_n*max_n, 0);

    int n; cin >> n;
    int x, y;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        coord[i][0] = x; coord[i][1] = y;
    }

    if(n==1) {
        cout << 0 << endl;
        return 0;
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            dis[i][j] = dis[j][i] = (LL)(sqrt((coord[i][0] - coord[j][0]) * (coord[i][0] - coord[j][0]) + (coord[i][1] - coord[j][1]) * (coord[i][1] - coord[j][1])) - eps) + 1;
        }
    }
    LL ans = 0x3f3f3f3f3f3f3f3f;
    // for(int i=0; i<n; i++){
    //     ans = min(ans, find_min())
    // }

    cout << (ans+1) / 2 << endl;

    return 0;
}
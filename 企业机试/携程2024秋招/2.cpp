#include<bits/stdc++.h>
using namespace std;

const int max_n = 1005;
int crt_map[max_n][max_n] = {-1};

typedef long long ll;

// y o u
// o y u
// u y o

ll cal_tri(int crt, int m, int n, int x, int y){
    int fir[4] = {0, 0, 0, 0}; // left, up, right, down
    int sec[4] = {0, 0, 0, 0}; // left, up, right, down
    
    if(crt == 'y'-'a'){
        for(int j=y-1; j>=0; j--){
            if(crt_map[x][j] == 'o'-'a') fir[0]++;
            if(crt_map[x][j] == 'u'-'a') sec[0]++;
        }

        for(int i=x-1; i>=0; i--){
            if(crt_map[i][y] == 'o'-'a') fir[1]++;
            if(crt_map[i][y] == 'u'-'a') sec[1]++;
        }

        for(int j=y+1; j<n; j++){
            if(crt_map[x][j] == 'o'-'a') fir[2]++;
            if(crt_map[x][j] == 'u'-'a') sec[2]++;

        }

        for(int i=x+1; i<m; i++){
            if(crt_map[i][y] == 'o'-'a') fir[3]++;
            if(crt_map[i][y] == 'u'-'a') sec[3]++;
        }

    }else if(crt == 'o'-'a'){
        for(int j=y-1; j>=0; j--){
            if(crt_map[x][j] == 'y'-'a') fir[0]++;
            if(crt_map[x][j] == 'u'-'a') sec[0]++;
        }

        for(int i=x-1; i>=0; i--){
            if(crt_map[i][y] == 'y'-'a') fir[1]++;
            if(crt_map[i][y] == 'u'-'a') sec[1]++;
        }

        for(int j=y+1; j<n; j++){
            if(crt_map[x][j] == 'y'-'a') fir[2]++;  
            if(crt_map[x][j] == 'u'-'a') sec[2]++;

        }

        for(int i=x+1; i<m; i++){
            if(crt_map[i][y] == 'y'-'a') fir[3]++;
            if(crt_map[i][y] == 'u'-'a') sec[3]++;
        }

    }else{
        for(int j=y-1; j>=0; j--){
            if(crt_map[x][j] == 'y'-'a') fir[0]++;
            if(crt_map[x][j] == 'o'-'a') sec[0]++;
        }

        for(int i=x-1; i>=0; i--){
            if(crt_map[i][y] == 'y'-'a') fir[1]++;
            if(crt_map[i][y] == 'o'-'a') sec[1]++;
        }

        for(int j=y+1; j<n; j++){
            if(crt_map[x][j] == 'y'-'a') fir[2]++;
            if(crt_map[x][j] == 'o'-'a') sec[2]++;

        }

        for(int i=x+1; i<m; i++){
            if(crt_map[i][y] == 'y'-'a') fir[3]++;
            if(crt_map[i][y] == 'o'-'a') sec[3]++;
        }
    }

    ll rst = 0;

    for(int i=0; i<4; i++){
        rst += fir[i]*sec[(i+1)%4];
        rst += sec[i]*fir[(i+1)%4];
    }
    return rst;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    char ccr;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> ccr;
            crt_map[i][j] = ccr - 'a';
        }
    }

    ll ans = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(crt_map[i][j] == 'y'-'a' || crt_map[i][j] == 'o'-'a' || crt_map[i][j] == 'u'-'a'){
                ans += cal_tri(crt_map[i][j], m, n, i, j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
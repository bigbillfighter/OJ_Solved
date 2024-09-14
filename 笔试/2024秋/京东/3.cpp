#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e3+5;
typedef long long LL;
int coord[max_n][2];

float eps = 1e-6;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

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

    LL max_len = (LL)(sqrt((coord[0][0] - coord[1][0]) * (coord[0][0] - coord[1][0]) + (coord[0][1] - coord[1][1]) * (coord[0][1] - coord[1][1])) - eps);
    max_len += 1;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            max_len = max(max_len, (LL)(sqrt((coord[i][0] - coord[j][0]) * (coord[i][0] - coord[j][0]) + (coord[i][1] - coord[j][1]) * (coord[i][1] - coord[j][1])) - eps) + 1);
        }
    }
    
    if(max_len % 2 == 0){
        cout << max_len / 2 << endl;
    }else{
        cout << max_len / 2 + 1 << endl;
    }

    return 0;
}
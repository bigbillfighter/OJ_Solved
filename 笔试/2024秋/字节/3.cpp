#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int max_n = 1e3+5;
int a[max_n][max_n];
int visited[max_n][max_n];
int lens[max_n][max_n];

LL crt_gcd(LL a, LL b){
    if(a%b == 0) return b;
    else return crt_gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill(visited[0], visited[0] + max_n*max_n, 0);
    fill(lens[0], lens[0] + max_n*max_n, -1);

    int n, m, xe, ye;
    cin >> n >> m >> xe >> ye;
    string ss;
    for(int i=0; i<n; i++){
        cin >> ss;
        for(int j=0; j<m; j++){
            a[i][j] = ss[j] - '0';
        }
    }

    lens[xe-1][ye-1] = 0; 
    queue<pair<int, int> > points;
    points.push(make_pair(xe-1, ye-1));
    visited[xe-1][ye-1] = 1;


    int cx, cy;
    while(!points.empty()){
        pair<int, int> crt_point = points.front();
        cx = crt_point.first;
        cy = crt_point.second;
        points.pop();

        if(cx > 0 && a[cx-1][cy] == 0 && !visited[cx-1][cy]){
            points.push(make_pair(cx-1, cy));
            lens[cx-1][cy] = lens[cx][cy] + 1;
            visited[cx-1][cy] = 1;
        }
        if(cy > 0 && a[cx][cy-1] == 0 && !visited[cx][cy-1]){
            points.push(make_pair(cx, cy-1));
            lens[cx][cy-1] = lens[cx][cy] + 1;
            visited[cx][cy-1] = 1;
        }

        if(cx < n-1 && a[cx+1][cy] == 0 && !visited[cx+1][cy]){
            points.push(make_pair(cx+1, cy));
            lens[cx+1][cy] = lens[cx][cy] + 1;
            visited[cx+1][cy] = 1;

        }
        if(cy < m-1 && a[cx][cy+1] == 0 && !visited[cx][cy+1]){
            points.push(make_pair(cx, cy+1));
            lens[cx][cy+1] = lens[cx][cy] + 1;
            visited[cx][cy+1] = 1;

        }
    }

    LL p = 0, q = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(lens[i][j] >= 0){
                p += lens[i][j];
                q ++;
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << lens[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;


    LL gcd_rst = crt_gcd(p, q);
    if(gcd_rst == 0) gcd_rst = 1;
    // cout << p << " " << q << endl;
    cout << p / gcd_rst << " " << q / gcd_rst << endl;

    return 0;
}
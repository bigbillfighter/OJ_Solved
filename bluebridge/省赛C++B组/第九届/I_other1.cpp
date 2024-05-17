#include<bits/stdc++.h>
using namespace std;
char dt[1000][1000];
bool vis[1000][1000];
int n, ans;
struct point {
    int x, y;
    point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};
int dir[4][2] = {{-1, 0},
                 {1,  0},
                 {0,  -1},
                 {0,  1}};
bool check(int r, int c) {
    for (int i = 0; i < 4; ++i) {
        int rr = r + dir[i][0];
        int cc = c + dir[i][1];
        if (dt[rr][cc] == '.') {
            return true;
        }
    }
    return false;
}
bool bfs(int r, int c) {
    vis[r][c] = true;
    queue <point> q;
    q.push(point(r, c));
    int cnt1 = 0, cnt2 = 0;
    while (!q.empty()) {
        cnt1++;
        point p = q.front();
        q.pop();
        if (check(p.x, p.y)) {
            cnt2++;
        }
        for (int i = 0; i < 4; ++i) {
            int rr = p.x + dir[i][0];
            int cc = p.y + dir[i][1];
            if (dt[rr][cc] == '#' && !vis[rr][cc]) {
                q.push(point(rr, cc));
                vis[rr][cc] = true;
            }
        }
    }
    if (cnt1 == cnt2) {
        return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dt[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dt[i][j] == '#' && !vis[i][j]) {
                if (bfs(i, j)) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

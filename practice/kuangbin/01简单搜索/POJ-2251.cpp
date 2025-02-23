#include <iostream>
#include <queue>

using namespace std;

const int max_n = 40;
char chamber[max_n][max_n][max_n];

int nlayer, row, col;
int sl, sx, sy;
int ans;

int dl[6] = {0, 0, 0, 0, -1, 1};
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};

struct TriIdx{
    int ly, x, y;
    int step;
    TriIdx(int a, int  b, int c, int s): ly(a), x(b), y(c), step(s){}
};

bool is_valid(int ly, int x, int y){
    if(x < 0 || y < 0 || ly < 0 || x >= row || y >= col || ly >= nlayer) return false;
    if(chamber[ly][x][y] == '#') return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> nlayer >> row >> col && nlayer + row + col > 0){
        queue<TriIdx> trace;

        for(int i=0; i<nlayer; i++){
            for(int j=0; j<row; j++){
                for(int k=0; k<col; k++){
                    cin >> chamber[i][j][k];
                    if(chamber[i][j][k] == 'S'){
                        trace.push(TriIdx(i, j, k, 0));
                        chamber[i][j][k] = '#';
                    }
                }
            }
        }

        ans = -1;
        while(!trace.empty()){
            TriIdx crt = trace.front();

            trace.pop();
            for(int i=0; i<6; i++){
                if(is_valid(crt.ly+dl[i], crt.x+dx[i], crt.y+dy[i])){
                    if(chamber[crt.ly+dl[i]][crt.x+dx[i]][crt.y+dy[i]] == 'E'){
                        ans = crt.step + 1;  break;
                    }

                    chamber[crt.ly+dl[i]][crt.x+dx[i]][crt.y+dy[i]] = '#';
                    trace.push(TriIdx(crt.ly+dl[i], crt.x+dx[i], crt.y+dy[i], crt.step+1));
                }
            }

        }

        if(ans >= 0){
            cout << "Escaped in " << ans << " minute(s)." << endl;
        }else{
            cout << "Trapped!" << endl;
        }

    }
    return 0;
}


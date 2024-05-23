# include<vector>
# include<queue>
# include<iostream>
# include<stack>
using namespace std;

const int max_n = 5+2;
int cmap[max_n][max_n];
int visited[max_n][max_n];
int last[max_n][max_n][2];

int xs[4] = {0, 1, 0, -1};
int ys[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill(visited[0], visited[0]+max_n*max_n, 0);

    int cdata;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> cdata;
            cmap[i][j] = cdata;
        }
    }

    queue<pair<int, int> > rst;
    rst.push({0, 0});
    visited[0][0] = 1;
    cmap[0][0] = 0;
    last[0][0][0] = 0;
    last[0][0][1] = 0;

    while(!rst.empty()){
        pair<int, int> crt_pair = rst.front();
        rst.pop();
        for(int i=0; i<4; i++){
            int crt_x=crt_pair.first+xs[i], crt_y = crt_pair.second+ys[i];
            if(crt_x >= 0 && crt_x < 5 && crt_y >=0 && crt_y < 5 && !visited[crt_x][crt_y] && cmap[crt_x][crt_y]!=1){
                cmap[crt_x][crt_y] = cmap[crt_pair.first][crt_pair.second] + 1;
                rst.push({crt_x, crt_y});
                visited[crt_x][crt_y] = 1;
                last[crt_x][crt_y][0] = crt_pair.first;
                last[crt_x][crt_y][1] = crt_pair.second;
            }
        }
    }
    
    stack<int> pt[2];
    int rst_x=4, rst_y=4;
    while(rst_x || rst_y){
        pt[0].push(rst_x);
        pt[1].push(rst_y);

        int ts_x=rst_x, ts_y=rst_y;
        rst_x = last[ts_x][ts_y][0];
        rst_y = last[ts_x][ts_y][1];
    }

    cout << "(0, 0)" <<endl;

    while(!pt[0].empty()){
        cout << "(" << pt[0].top() << ", " << pt[1].top() << ")" << endl;
        pt[0].pop(); pt[1].pop();
    }

    return 0;
}
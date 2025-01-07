//超时 
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_X = 300+5;
const int MAX_N = 5e4+5;

struct node{
    int x, y, t;
    node(int x, int y, int t){
    	this->x = x;
    	this->y = y;
    	this->t = t;
	}
	node(){}
};

int maze[MAX_X][MAX_X]; //每一个坐标的时间
int act[5][2] = {{0,0},{1,0},{0,1},{0,-1},{-1,0}};


int bfs(){
    queue<node> q;
    
    if(maze[0][0] > 0)
        q.push(node(0, 0, 0));
    
	int x, y, t;
	int cx, cy;
	int i;
	while(!q.empty()){
        node cur = q.front();
        q.pop();
        x = cur.x, y = cur.y, t = cur.t;
        if(maze[x][y] == INF)
            return t;
            
        for(i = 1; i < 5; ++i){
            cx = x+act[i][0], cy = y+act[i][1];
            if(cx>=0&&cy>=0 && t+1 < maze[cx][cy]){
                if(maze[cx][cy]!=INF)
                    maze[cx][cy] = t+2; //最优化剪枝
                q.push(node(cx, cy, t+1));
            }
        }
    }
    
    return -1;
}

void solve(){
    int M;
	int x, y, t;
    int cx, cy;
    int i, j;
    fill(maze[0], maze[0]+MAX_X*MAX_X, INF);
	scanf("%d", &M);
    for(i=0; i<M; ++i){
        scanf("%d%d%d", &x, &y, &t);
        for(j = 0; j < 5; ++j){
            cx = x+act[j][0], cy = y+act[j][1];
            if(cx>=0&&cx<=300&&cy>=0&&cy<=300)
                maze[cx][cy] = min(maze[cx][cy], t);
        }
    }
    cout << bfs() << endl;
}

int main() {
	solve();
    return 0;
}

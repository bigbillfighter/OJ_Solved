//bfs, 再往回找路径，从后往前就只有一条路径
//再按照最小序列的顺序寻找输出即可 

#include<iostream>
#include<cstdio> 
#include<string>
#include<queue> 
#include<stack>
#include<cstdlib>
using namespace std;

const int INF=0x3f3f3f3f;
const int M=30, N=50;
char map[M][N];
int X[4]={1, 0, 0, -1};
int Y[4]={0, -1, 1, 0};
char Dir[4]={'D', 'L', 'R', 'U'};
typedef pair<int, int> P;
queue<P> qe;
int dis[M][N];
stack<char> sk;

void bfs(){
	qe.push(P(0, 0));
	int i, j;
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			dis[i][j] = INF;
		}
	}
	dis[0][0] = 0;
	while(qe.size()){
		P p = qe.front(); qe.pop();
		if(p.first==M-1&&p.second==N-1) break;
		
		for(i=0; i<4; i++){
			int nx = p.first+X[i], ny = p.second+Y[i];
			
			if(0<=nx && nx<M && 0<=ny && ny<N && map[nx][ny]!='1' && dis[nx][ny]==INF){
				qe.push(P(nx, ny));
				dis[nx][ny] = dis[p.first][p.second]+1;
			}
		}
	}
}

void solve(){
	int i, j;
	for(i=0; i<30; i++){
		for(j=0; j<50; j++){
			scanf(" %c", &map[i][j]);
		}
	}
	bfs();
	
	int k = dis[M-1][N-1];
	int tx=M-1, ty=N-1;
	
	while(!(tx==0&&ty==0)){
		
		for(int i=3; i>=0; i--){ //倒序往回找即为最小方案的正序往后找所经过的路径 
			int nx = tx+X[i], ny = ty+Y[i];
			
			if(0<=nx && nx<M && 0<=ny && ny<N){
				if ((k-dis[nx][ny])==1){
					tx = nx, ty=ny;
					k--;
					sk.push(Dir[3-i]);
				}
			}
		}
	}
	string c;
	while(!sk.empty()){
		c += sk.top();
		sk.pop();
	}
	cout<<c<<endl;
}

int main(){
	solve();
	return 0;
} 

#include<cstdio>
#include<cstdlib> 
#include<iostream>
using namespace std;

int W, H;
const int MAX_H = 22;
char room[MAX_H][MAX_H];
bool visit[MAX_H][MAX_H];
int X[4] = {0, -1, 0, 1};
int Y[4] = {1, 0, -1, 0};
int ans;

void dfs(int x, int y){
	visit[x][y] = true;
	for(int k=0; k<4; k++){
		int nx = x+X[k], ny = y+Y[k];
		if(nx>=0&&nx<H&&ny>=0&&ny<W&&!visit[nx][ny]&&room[nx][ny]=='.')
			dfs(nx, ny);
	}
	ans++;
}

void solve(){
	int i, j;
	int px, py;
	scanf("%d %d", &W, &H); // W is columns, H is rows
	while(!(W==0&&H==0)){
		ans = 0;
		for(i=0; i<H; i++){
			for(j=0; j<W; j++){
				scanf(" %c", &room[i][j]);
				if(room[i][j]=='@') px=i, py=j;
				visit[i][j] = false; 
			}
		}
		dfs(px, py);
		printf("%d\n", ans);
		scanf("%d %d", &W, &H); // W is columns, H is rows
	} 
}

int main(){
	solve();
	return 0;
} 

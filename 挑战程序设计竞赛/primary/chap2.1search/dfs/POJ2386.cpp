#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int N, M;
const int MAX_N=105;
char mp[MAX_N][MAX_N];
bool vst[MAX_N][MAX_N];
int xd[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int yd[8] = {0, -1, 0, 1, -1, 1, -1, 1};

void dfs(int x, int y){
	vst[x][y] = true;
	int cx, cy;
	for(int i=0; i<8; i++){
		cx = x+xd[i], cy = y+yd[i];
		if(cx>=0&&cx<N&&cy>=0&&cy<M&&!vst[cx][cy]&&mp[cx][cy]=='W')
			dfs(cx, cy);		 
	}
}

void solve(){
	scanf("%d%d", &N, &M);
	int i, j;
	for(i=0; i<N; i++){
		scanf(" %s", mp[i]);
	}
	
	int ans=0;
	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			if(mp[i][j]=='W'&&!vst[i][j]){
				dfs(i, j);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}

int main() {
	solve();
    return 0;
}

#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

const int MAX_N=1005;
char map[MAX_N][MAX_N];
char map2[MAX_N][MAX_N];
bool is_edge[MAX_N][MAX_N];
int N;
int ans;
int island;
int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, 1, 0, -1};


void dfs(int i, int j, char mp[][MAX_N]){
	mp[i][j] = '.';
	for(int k=0; k<4; k++){
		int nx = X[k]+i, ny=Y[k]+j;
		if(nx>=0 && nx<N && ny>=0 && ny<N && mp[nx][ny]=='#')
			dfs(nx, ny, mp);
	}
}

void solve() {
	scanf("%d", &N);
	int i, j, k;
	char cc;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			scanf(" %c", &cc);
			map2[i][j] = map[i][j]=cc;
		}
	}
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(map2[i][j] == '#'){
				dfs(i, j, map2);
				island++;
			}
		}
	}
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(map[i][j] == '#'){
				for(k=0; k<4; k++){
					int nx = X[k]+i, ny=Y[k]+j;
					if(nx>=0 && nx<N && ny>=0 && ny<N && map[nx][ny]=='.'){
						is_edge[i][j] = true;
						break;
					}
				}
			}
		}
	}
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(is_edge[i][j]) map[i][j] = '.';
		}
	} 
	
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(map[i][j] == '#'){
				dfs(i, j, map);
				ans++;
			}
		}
	}
	printf("%d\n", island-ans);
}

int main() {
	solve();
	return 0;
}

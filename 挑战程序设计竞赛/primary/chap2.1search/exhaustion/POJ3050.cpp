#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>

using namespace std;
int mp[5][5];
map<int, bool> p;
int tx[4] = {0, 1, 0, -1};
int ty[4] = {-1, 0, 1, 0};
int sum;

void dfs(int x, int y, int t){
	int i, j;
	int cx, cy;
	if(t==0){
		p[sum] = true; 
		return;
	}
	if(t==5) sum=mp[x][y];
	for(i=0; i<4; i++){
		cx = x+tx[i];
		cy = y+ty[i];
		if(cx>=0&&cx<5&&cy>=0&&cy<5){
			int last = sum;
			sum = sum*10+mp[cx][cy];
			dfs(cx, cy, t-1);
			sum = last;
		} 
	}
}

void solve(){
	p.clear();
	int i, j;
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			scanf("%d",&mp[i][j]);
		}
	}
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			dfs(i, j, 5);
		}
	}
	printf("%d\n", p.size());
}

int main() {
    solve();
    return 0;
}

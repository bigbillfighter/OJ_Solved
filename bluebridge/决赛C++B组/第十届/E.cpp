//206
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

bool mp[6][6];
int xd[4] = {0, 1, 0, -1};
int yd[4] = {-1, 0, 1, 0};
int ans=0;

void dfs(int x, int y, int stp){
	mp[x][y] = true;
	if(stp<0) return;
	for(int i=0; i<4; i++){
		int cx = x+xd[i], cy = y+yd[i];
		if(cx>=0&&cx<6&&cy>=0&&cy<6){
			if(cx==0&&cy==0&&stp!=11){
				ans++;
				return ;
			}
			else if(!mp[cx][cy]){
				dfs(cx, cy, stp-1);
				mp[cx][cy] = false; 			
			}
		}
	}
}

void solve(){
	dfs(0, 0, 12);
	cout<<ans<<endl;
}

int main(){
	solve();
	return 0;
}

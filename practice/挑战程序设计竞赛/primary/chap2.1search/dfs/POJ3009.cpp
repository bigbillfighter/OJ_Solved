#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int W, H;  
const int MAX_N = 21;
const int INF = 0x3f3f3f3f;
int mp[MAX_N][MAX_N];
int pathlen[MAX_N][MAX_N]; 

void dfs(int stx, int sty){
	if(pathlen[stx][sty] > 10) return; 
	int i, j;
	int tmp;
	
	i = stx, j = sty;
	
	if(sty-1>=0 && mp[stx][sty-1]!=1){
		for(j=sty-1; j>=0; j--){
			if(mp[i][j]==3 && pathlen[i][j]>pathlen[stx][sty]){
				pathlen[i][j] = pathlen[stx][sty]+1;
				break;	
			}
			if(mp[i][j]==1){
				mp[i][j] = 0;
				tmp = pathlen[i][j+1];
				pathlen[i][j+1] = pathlen[stx][sty]+1;
				dfs(i, j+1);
				mp[i][j] = 1;
				pathlen[i][j+1] = tmp;
				break;
			}
  
		}
	} 
	
	
	i = stx, j = sty;
	if(sty+1<W && mp[stx][sty+1]!=1){
		for(j=sty+1; j<W; j++){
			if(mp[i][j]==3 && pathlen[i][j]>pathlen[stx][sty]){
				pathlen[i][j] = pathlen[stx][sty]+1;	
				break;
			}
			if(mp[i][j]==1){
				mp[i][j] = 0;
				tmp = pathlen[i][j-1];
				pathlen[i][j-1] = pathlen[stx][sty]+1;
				dfs(i, j-1);
				mp[i][j] = 1;
				pathlen[i][j-1] = tmp;
				break;
			}
	 
		} 
	}
	
	i = stx, j = sty;
	if(stx-1>=0 && mp[stx-1][sty]!=1){
		for(i=stx-1; i>=0; i--){
			if(mp[i][j]==3 && pathlen[i][j]>pathlen[stx][sty]){
				pathlen[i][j] = pathlen[stx][sty]+1;
				break;	
			}
			if(mp[i][j]==1){
				mp[i][j] = 0;
				tmp = pathlen[i+1][j];
				pathlen[i+1][j] = pathlen[stx][sty]+1;
				dfs(i+1, j);
				mp[i][j] = 1;
				pathlen[i+1][j] = tmp;
				break;
			}
	 
		} 
	}
	 
	i = stx, j = sty;
	if(stx+1<H && mp[stx+1][sty]!=1){
		for(i=stx+1; i<H; i++){
			if(mp[i][j]==3 && pathlen[i][j]>pathlen[stx][sty]){
				pathlen[i][j] = pathlen[stx][sty]+1;
				break;	
			}
			if(mp[i][j]==1){
				mp[i][j] = 0;
				tmp = pathlen[i-1][j];
				pathlen[i-1][j] = pathlen[stx][sty]+1;
				dfs(i-1, j);
				mp[i][j] = 1;
				pathlen[i-1][j] = tmp;
				break;
			}
	 
		}
	} 
}

void solve(){
	scanf("%d %d", &W, &H);
	int i, j;
	int stx, sty;
	int endx, endy;
	while(!(W==0 && H==0)){
		for(i=0; i<H; i++){
			for(j=0; j<W; j++){
				scanf("%d", &mp[i][j]);
				if(mp[i][j]==2){
					pathlen[i][j] = 0;
					stx = i, sty = j;	
				}else pathlen[i][j] = INF;
				
				if(mp[i][j]==3){
					endx=i, endy=j;
				}
			}
		}
		dfs(stx, sty);
		if(pathlen[endx][endy] > 10){
			printf("%d\n", -1);
		}else{
			printf("%d\n", pathlen[endx][endy]);	
		}
		scanf("%d %d", &W, &H);
	}
}

int main(){
	solve();
	return 0;
} 

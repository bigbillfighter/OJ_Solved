#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int t, w;
const int maxt = 1e3+5;
const int maxn = 35;
int dp[3][maxn];
int trees[maxt];

void solve(){
	scanf("%d%d", &t, &w);
	int x;
	int i, j;
	for(i=1; i<=t; i++){
		scanf("%d", &trees[i]);
	}
	int cnt1=0, cnt2=0;
	for(i=1; i<=t; i++){
		for(j=0; j<=min(w, i); j++){
			if(trees[i]==1){

				dp[2][j] = max(dp[1][j-1], dp[2][j]);
				dp[1][j] = max(dp[2][j-1], dp[1][j])+1;				
			}else{
				dp[2][j] = max(dp[2][j], dp[1][j-1])+1;
				dp[1][j] = max(dp[2][j-1], dp[1][j]);	
			}
		}
	}

	int mam = max(dp[1][w], dp[2][w]);
	cout<<mam<<endl;
}
	

int main(){
	solve();
	return 0;
}

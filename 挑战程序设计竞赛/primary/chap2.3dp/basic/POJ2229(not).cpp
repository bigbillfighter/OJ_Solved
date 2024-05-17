#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n;
const int maxm = 21;
const int maxn = 1e6+5;
typedef long long LL;
LL dp[maxn][maxm];
const int mod= 1e9;

void solve(){
	scanf("%d", &n);

	int cpy = n;
	int order = 0;
	
	while(cpy = cpy>>1) order++;	
	int i, j;
	
	fill(dp[0], dp[0]+maxn*maxm, 1);

	LL x;
	int xd;
	LL xcp;
	LL p;
	for(i=1; i<=n; i++){
		p = 1;
		for(j=1; j<=order; j++){
			p = p<<1;
			x = i-p;
			if(x<0) break;
			if(x>=p)
				dp[i][j] = (dp[x][j] + dp[i][j-1])%mod;
			else{			
				xd = 0;
				xcp = x;
				while(xcp = xcp>>1) xd++;
				dp[i][j] = (dp[x][xd] + dp[i][j-1])%mod;
			}
		}
	}
	printf("%lld\n", dp[n][order]%mod);	
}

int main(){
	solve();
	return 0;
}

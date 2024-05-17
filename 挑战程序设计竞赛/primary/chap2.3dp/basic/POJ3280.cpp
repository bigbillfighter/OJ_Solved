#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;

int n, m;
const int maxm = 2005;
const int maxn = 28;

map<char, int> mp;

char str[maxm];
int dp[maxm][maxm];

void solve(){
	scanf("%d%d", &n, &m);
	scanf(" %s", str);
	int i, j;
	char cr;
	int x, y;
	for(i=0; i<n; i++){
		scanf(" %c%d%d", &cr, &x, &y);
		mp[cr] = min(x, y);
	}
	for(i=1; i<m; i++){
		for(j=i-1; j>=0; j--){
			if(str[i]==str[j]) dp[i][j] = dp[i-1][j+1];
			else dp[i][j] = min(dp[i-1][j]+mp[str[i]], dp[i][j+1]+mp[str[j]]);
		}
	}
	cout<<dp[m-1][0]<<endl;
}
	

int main(){
	solve();
	return 0;
}

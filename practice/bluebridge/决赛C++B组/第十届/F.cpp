#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

const int MAX_N = 1005;
string S, T;
int dp[MAX_N][MAX_N];
int sum=0;
const int INF = 0x3f3f3f3f;

void solve(){
	cin>>S>>T;
	fill(dp[0], dp[0]+MAX_N*MAX_N, INF);
	dp[0][0] = 0;
	for(int i=1; i<=S.length(); i++){
		dp[i][0] = 0;
		for(int j=1; j<=T.length(); j++){
			if(S[i-1]==T[j-1]) dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]);
			else dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]+1);
		}
	}
	cout<<dp[S.length()][T.length()]<<endl;
}

int main(){
	solve();
	return 0;
}

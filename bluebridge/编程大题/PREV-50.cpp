#include <cstdio>
#include <algorithm>
#include <cstdio>

using namespace std;
const int MAX_N = 100001;
int num[MAX_N+1];
int dp[MAX_N+1];
int prt[MAX_N+1];

int N, K;


int main(){
	scanf("%d %d", &N, &K);
	int i=0, score=0;
	for(i=0; i<N; i++){
		scanf("%d", &score);
		num[score]++;
	}


	int ans = 0;
	int m = 0;
	int j=0;
	if(K==0){
		for(i=0 ;i<MAX_N; i++){
			if(num[i]) ans++;
		}
	}else{
		for(i=0; i<K; i++){
			m=0;
			for(j=i; j<MAX_N; j+=K){
				prt[m++] = num[j];
			}
			dp[0]= prt[0];
			dp[1] = prt[1];
			for(j=2; j<m; j++){
				dp[j] = max(dp[j-1], dp[j-2]+prt[j]);
			}
			ans += dp[m-1];
		}
	}
	printf("%d\n", ans);
	return 0;
}
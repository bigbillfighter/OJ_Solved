#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

const int MAX_M = 3;
const int MAX_N = 1e5+5;
typedef long long LL;
LL Data[MAX_M][MAX_N];
LL S[MAX_M][MAX_N]; 
int N;
int nbr;
LL ans=0;

void solve() {
	scanf("%d", &N);
	int i, j, k;
	for(i=0; i<3; i++){
		for(j=0; j<N; j++){
			scanf("%d", &nbr);
			Data[i][nbr]++;
		}
	}
	S[0][0] = Data[0][0];
	S[1][0] = Data[1][0];
	S[2][0] = Data[2][0];
	for(i=0; i<3; i++){
		for(j=1; j<MAX_N; j++){
			S[i][j] = S[i][j-1] + Data[i][j];
		}
	}
	for(i=1; i<MAX_N-1; i++){
		ans+=Data[1][i]*S[0][i-1]*(S[2][MAX_N-1]-S[2][i]);
	}
	printf("%lld\n", ans);
	
}

int main() {
	solve();
	return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int N, S;
typedef pair<int, int> Pr;
Pr pce[10005];
typedef long long LL;

LL solve(){
	LL tl = pce[0].first*pce[0].second;
	int i, j;
	for(i=1; i<N; i++){
		pce[i].first = min(pce[i].first, pce[i-1].first+S);	
		tl += pce[i].first*pce[i].second;
	}
	return tl;
}

int main() {
	int i;
	while(scanf("%d%d", &N, &S)==2){
		for(i=0; i<N; i++){
			scanf("%d%d", &(pce[i].first), &(pce[i].second));
		}
		printf("%lld\n", solve());
	}
    return 0;
}

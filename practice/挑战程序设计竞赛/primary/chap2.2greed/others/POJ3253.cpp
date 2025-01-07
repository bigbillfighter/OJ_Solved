#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
 
typedef long long LL;
int N;
const int MAX_N = 2e4+5;
LL cost = 0;
int lth[MAX_N];

void solve(){
	scanf("%d", &N);
	int i, j;
	for(i=0; i<N; i++){
		scanf("%d", &lth[i]);
	}
	sort(lth, lth+N);
	int ft, sec, sm;
	if(N==1){
		printf("%d\n", lth[0]);
		return;	
	}
	for(i=0; i<N-1; i++){
		ft = lth[i], sec = lth[i+1];
		sm = ft+sec;
		cost += sm;
		for(j=i+2; j<N; j++){
			if(lth[j]<sm) lth[j-1] = lth[j];
			else {
				lth[j-1]=sm;
				break;	
			} 
		}
		if(lth[N-2]<sm) lth[N-1] = sm;
	}
	printf("%lld\n", cost);
}


int main() {
	solve();
    return 0;
}

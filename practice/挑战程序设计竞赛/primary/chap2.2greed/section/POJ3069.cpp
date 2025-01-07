#include <iostream> 
#include <cstdio>
#include <algorithm>
using namespace std;

int rg, N;
const int MAX_N = 1e3+5; 
int sds[MAX_N];


void solve(){
	scanf("%d%d", &rg, &N);
	int i, j;
	while(rg!=-1&&N!=-1){
		for(i=0; i<N; i++){
			scanf("%d", &sds[i]);
		}
		sort(sds, sds+N);
		int st = 0;
		int ans = 0;
		for(i=0; i<N;){
			while(i<N&&sds[i]-sds[st]<=rg) i++;
			st = i-1;
			while(i<N&&sds[i]-sds[st]<=rg) i++;
			ans++;
			st = i;
		}
		printf("%d\n", ans);
		scanf("%d%d",&rg, &N);
	}
}

int main(){
	solve();
	return 0;
}


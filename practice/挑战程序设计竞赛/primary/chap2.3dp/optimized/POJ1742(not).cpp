#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int N, M;
int A[105], C[105]; 
bool meet[100005];

void solve(){
	int i, j, k;
	int mam = 0;
	for(i=0; i<N; i++){
		for(j=1; j<=C[i]; j++){
			if(j*A[i]<=M){
				meet[j*A[i]] = true;
				for(k=1; k<=mam; k++){
					if(meet[k]){
						if(j*A[i]+k > M) break;
						meet[j*A[i]+k] = true; 
					} 
				}
			}else break;
		}
		mam += (j-1)*A[i];
		if(mam > M) mam = M;
	}
	int ans=0;
	for(i=0; i<=M; i++){
		if(meet[i]) ans++; 
	}
	printf("%d\n", ans);
}

int main() {
	int i;
	while(scanf("%d%d", &N, &M)==2){
		if(N+M==0) break;
		memset(meet, 0, sizeof(meet));
		for(i=0; i<N; i++) scanf("%d", &A[i]);
		for(i=0; i<N; i++) scanf("%d", &C[i]);
		solve();
	}
    return 0;
}

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

int N, K;
const int MAX_N = 1e5+5;
int A[MAX_N];
typedef long long LL;
const LL Did = 1000000009;
LL rlt=1;

void solve() {
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
	sort(A, A+N);
	int st=0, ed=N-1;
	LL st_rt = 0, ed_rt = 0;
	if(K==1){
		rlt = (LL)A[N-1]%Did;
		printf("%lld\n", rlt);
		return;
	}
	if(A[0]>=0){
		while(K>0){
			rlt = (rlt*A[--N])%Did;
			K--; 
		}
		printf("%lld\n", rlt);
		return;
	}
	if(N==K){
		int a = 1;
		while(K>0){
			rlt = (rlt*A[--N])%Did;
			K--;
		}
		printf("%lld\n", rlt);
		return;
	}
	
	if(K%2==0){
		while(K>=2){
			st_rt = (LL)A[st]*A[st+1];
			ed_rt = (LL)A[ed]*A[ed-1];
			if(st_rt>ed_rt){
				rlt = (rlt*A[st++])%Did;
				rlt = (rlt*A[st++])%Did;
			}
			else{
				rlt = (rlt*A[ed--])%Did;
				rlt = (rlt*A[ed--])%Did;
			}
			K-=2;
		}
	}else{
		if(A[N-1]<=0){
			while(K>0){
				rlt = (rlt*A[--N])%Did;
				K--; 
			}
		}else{
			//A[N-1]>0 
			while(K>=5){
				st_rt = (LL)A[st]*A[st+1];
				ed_rt = (LL)A[ed]*A[ed-1];
				if(st_rt>ed_rt){
					rlt = (rlt*A[st++])%Did;
					rlt = (rlt*A[st++])%Did;
				}
				else{
					rlt = (rlt*A[ed--])%Did;
					rlt = (rlt*A[ed--])%Did;
				}
				K-=2;
			}
			st_rt = (LL)A[st]*A[st+1];
			ed_rt = (LL)A[ed-1]*A[ed-2];
			if(st_rt>ed_rt){
				rlt = (rlt*A[st++])%Did;
				rlt = (rlt*A[st++])%Did;
				rlt = (rlt*A[ed])%Did; 
			}
			else{
				rlt = (rlt*A[ed--])%Did;
				rlt = (rlt*A[ed--])%Did;
				rlt = (rlt*A[ed])%Did;
			}

		}		
	}
	printf("%lld\n", rlt);
	return;
}

int main() {
	solve();
	return 0;
}

#include<bits/stdc++.h>
#include<iostream>
#include<cstdio> 
#include<cstdlib>
using namespace std;

int N;
const int MAX_N = 1e5+5;
typedef long long LL;
int A[MAX_N];

void solve(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);
	}
	LL ans=0, tmp=0;
	int k=1;
	int level=1;
	for(int i=1; i<=N; i++){
		if(i>=(LL)pow(2, k)){
			if(tmp>ans){
				ans=tmp;
				level = k;	
			}
			k++;
			tmp=0;
		}
		tmp+=A[i];
	}
	if(tmp>ans){
//		ans = tmp;
		level = k;
	}
	printf("%d\n", level);
}

int main(){
	solve();
	return 0;
} 

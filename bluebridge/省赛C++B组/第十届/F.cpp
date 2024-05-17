#include<bits/stdc++.h>
#include<iostream>
#include<cstdio> 
#include<cstdlib>
using namespace std;

typedef long long LL;

int N;
LL ans=0;

void solve(){
	scanf("%d", &N);
	int t, crt;
	for(int i=1; i<=N; i++){
		crt = i;
		while(crt){
			t = crt%10;
			crt /= 10;
			if(t==2||t==0||t==1||t==9){
				ans+=i;
				break;
			}
		}
	} 
	printf("%lld\n", ans);
}

int main(){
	solve();
	return 0;
} 

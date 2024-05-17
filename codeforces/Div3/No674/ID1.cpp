#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

void flor(){
	int n, x;
	scanf("%d %d", &n, &x);
	if(n==1||n==2){
		printf("%d\n", 1);
		return;
	}
	printf("%d\n", (n-3)/x + 2);
	return;
}

void solve(){
	int t;
	scanf("%d", &t);
	while(t--){
		flor();
	}
}

int main(){
	solve();
	return 0;
}

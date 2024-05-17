#include<bits/stdc++.h>
#include<iostream>
#include<cstdio> 
#include<cstdlib>
using namespace std;

int N;
const int MAX_N=1e5+5;
int A[MAX_N];
int diff[MAX_N];

int _gcd(int a, int b){
	if(b==0) return a;
	return _gcd(b, a%b);
}

void solve(){
	scanf("%d", &N);
	int i;
	for(i=0; i<N; i++){
		scanf("%d", &A[i]);
	} 
	sort(A, A+N);
	for(i=1; i<N; i++){
		diff[i-1] = A[i] - A[i-1];
	}
	if(N==2) {
		printf("%d\n", N);
		return;
	}
	int gd=_gcd(diff[0], diff[1]);
	for(i=2; i<N-1; i++){
		gd = _gcd(diff[i], gd);
	}
	if(gd==0){
		printf("%d\n", N);
		return;
	}
	printf("%d\n", ((A[N-1]-A[0])/gd+1));
}

int main(){
	solve();
	return 0;
} 

#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int t; 
const int mam = 63244;
const int mim = 0;

int max_itg(int ind){
	return ((ind+2)/2) * ((ind+3)/2);
}

int find_times(int tst){
	int ub = mam, lb = mim;
	int mid = (ub+lb)/2;
	while(ub-lb>=2){
		if(max_itg(mid)==tst) return mid;
		if(max_itg(mid)<tst){
			lb = mid;
			mid = (lb+ub)/2;
		}else{
			ub = mid;
			mid = (lb+ub)/2;
		}
	}
	if(max_itg(lb)>=tst) return lb;
	else return lb+1;
	 
}

void solve(){
	scanf("%d", &t);
	int tst;
	while(t--){
		scanf("%d", &tst);
		printf("%d\n", find_times(tst));	
	}
}

int main(){
	solve();

	return 0;
}

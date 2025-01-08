#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<bitset>
#include<sstream>
using namespace std;

const int N=100;
int nbr[N];
int tw, fv;

void solve() {
	for(int i=0; i<N; i++){
		scanf("%d", &nbr[i]);
	}
	for(int i=0; i<N; i++){
		int flag = true;
		while(flag&&nbr[i]){
			if(nbr[i]%2==0){
				tw++;
				nbr[i]/=2;
				continue;
			}
			if(nbr[i]%5==0){
				fv++;
				nbr[i]/=5;
				continue;
			}
			flag=false;
		}
		
		
	}
	printf("%d\n", min(tw, fv));
}

int main() {
	solve();
	return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, K;
const int MAX_N = 5e4+5;
int par[MAX_N*3], rk[MAX_N*3];

void init(int x) {
	for(int i=1; i<=x; i++) {
		par[i] =i;
		par[i+MAX_N]= i+MAX_N;
		par[i+MAX_N*2]= i+MAX_N*2;
		rk[i] = rk[i+MAX_N] = rk[i+MAX_N*2] = 0;
	}
}

int find(int x) {
	if(x==par[x]) return x;
	else return par[x] = find(par[x]);
}

bool same(int x, int y) {
	return find(x) == find(y);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x==y) return;
	if(rk[x]<rk[y]) {
		par[x] = y;
	} else {
		par[y] = x;
		if(rk[x]==rk[y]) rk[x]++;
	}
}

int main() {
	cin>>N>>K;
	int fs = 0;
	int tp, fst, snd;
	init(N);
	for(int i=1; i<=K; i++) {
//		cout<<fs<<endl;
		scanf("%d%d%d", &tp, &fst, &snd);
		if(fst>N || snd>N) {
			fs++;
			continue;
		}
		if(tp==1) {
			if(same(fst, snd+MAX_N) || same(fst, snd+MAX_N*2)) fs++;
			else{
				unite(fst, snd);
				unite(fst+MAX_N, snd+MAX_N);
				unite(fst+MAX_N*2, snd+MAX_N*2);
			}
		}else{
			if(same(fst, snd) || same(fst, snd+MAX_N*2)) fs++;
			else{
				unite(fst, snd+MAX_N);
				unite(fst+MAX_N, snd+MAX_N*2);
				unite(fst+MAX_N*2, snd);
			}
		}
	}
	cout<<fs<<endl;
	return 0;
}

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef pair<int, int> P; //first time, second id
const int MAX_N = 1e5+5;
P thum[MAX_N]; // 点赞数据 
bool ht[MAX_N]; //是否热 
int tms[MAX_N]; //点赞次数 

int N, D, K; 

bool cmp(P a1, P a2){
	return a1.first < a2.first;
}

void solve() {
	scanf("%d %d %d", &N, &D, &K);
	int i, j;
	for(i=0; i<N; i++){
		scanf("%d %d", &thum[i].first, &thum[i].second);
	}
	sort(thum, thum+N, cmp);
	j=0;
	for(i=0; i<N; i++){
		while(j<N && thum[j].first-thum[i].first<D){
			tms[thum[j].second]++;
			if(tms[thum[j].second] >= K) ht[thum[j].second] = true;	
			j++;
		}
		tms[thum[i].second]--;
	}
	for(i=0; i<MAX_N; i++){
		if(ht[i]) printf("%d\n", i);
	} 
}

int main() {
	solve();
	return 0;
}

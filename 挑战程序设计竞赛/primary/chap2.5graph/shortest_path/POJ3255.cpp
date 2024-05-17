#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

int N, R;
const int MAX_N = 5e3+5;
const int MAX_R = 1e5+5;
int cost[MAX_N][MAX_N];
const int INF = 0x3f3f3f3f;

int d[MAX_N], d_snd[MAX_N];
int update[MAX_N];

void dijkstra(int x){
	fill(d+1, d+1+N, INF);
	fill(d_snd+1, d_snd+N+1, INF);
	d[x] = 0;
	while(1){
		int v = -1, u=1;
		for(int i=1; i<=N; i++){
			if(!update[i] && (v==-1 || d[i]<d[v])){
				u = v; v = i; 
			}
		}
		if(v==-1) break;
		update[v]==1;
		for(int i=1; i<=N; i++){
			d[i] = min(d[i], d[v]+cost[v][i]);
			d_snd[i] = min(d[u]+cost[u][i], d_snd[i]); 
		}
	}
}

int main() {
	cin>>N>>R;
	int st, ed, ct;
	fill(cost[0], cost[0]+MAX_N*MAX_N, INF);
	for(int i=0; i<R; i++) {
		scanf("%d%d%d", &st, &ed, &ct);
		cost[st][ed] = cost[ed][st] = ct;
	}
	for(int i=1; i<=N; i++) cost[i][i] = 0;
	dijkstra(1);
	cout<<d_snd[N]<<endl;
	return 0;
}

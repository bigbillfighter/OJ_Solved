#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
7 10
0 1 2
0 2 5
2 1 4
1 3 6
2 3 2
1 4 10
3 5 1
4 5 3
4 6 5
5 6 9
*/

const int MAX_V = 10;

int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V, E;
const int INF=0x3f3f3f3f;

int prim() {
	fill(mincost, mincost+V, INF);
	fill(used, used+V, false);
	mincost[0] = 0;
	int res = 0;
	
	while(true) {
		int v = -1;
		for(int u=0; u<V; u++) {
			if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v = u;
		}
		
		if(v==-1) break;
		used[v] = true;
		res += mincost[v];
		for(int u=0; u<V; u++){
			mincost[u] = min(mincost[u], cost[v][u]);
		}
	}
	return res;
}

int main() {
	cin>>V>>E;
	int fm, to, cs;
	fill(cost[0], cost[0]+MAX_V*MAX_V, INF);
	for(int i=0; i<E; i++){
		cin>>fm>>to>>cs;
		cost[fm][to] = cs;
		cost[to][fm] = cs;
	}
//	for(int i=0; i<V; i++){
//		for(int j=0; j<V; j++){
//			cout<<cost[i][j]<<" ";
//		}
//		cout<<endl;
//	}

	int total = prim();
	for(int i=0; i<V; i++){
		cout<<mincost[i]<<endl;
	}
	cout<<total<<endl;
	return 0;
}

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

const int MAX_E = 20;
const int MAX_V = 10;
struct edge {
	int from, to, cost;
};

edge es[MAX_E];
int d[MAX_V];
int V, E;

const int INF=0x3f3f3f3f;

void shortest_path(int s) {
	fill(d, d+V, INF);
	d[s] = 0;
	while(1) {
		bool update = false;
		for(int i=0; i<E; i++) {
			edge e = es[i];
			if(d[e.from] != INF && d[e.to]>d[e.from]+e.cost) {
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if(!update) break;
	}
}

// 判断是否有负圈
bool find_negative() {
	memset(d, 0, siezof(d));
	for(int i=0; i<V; i++) {
		for(int j=0; j<E; j++){
			edge e = es[j];
			if(d[e.to] >d[e.from]+e.cost){
				d[e.to] = d[e.from]+e.cost;
				if(i==V-1) return true;//有负圈 
			}
		}
	}
	return false;
	
}

int main() {
	cin>>V>>E;
	for(int i=0; i<E; i++) {
		cin>>es[i].from>>es[i].to>>es[i].cost;
	}
	shortest_path(0);
	for(int i=0; i<V; i++) {
		cout<<d[i]<<endl;
	}
	return 0;
}

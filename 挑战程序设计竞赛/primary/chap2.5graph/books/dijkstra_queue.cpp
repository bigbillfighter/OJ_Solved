#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
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

struct edge {int to, cost;};
typedef pair<int, int> P; // first是最短路径，second是顶点的编号

int V, E;
const int MAX_V = 10;
const int MAX_E = 20;

vector<edge> G[MAX_V];
int d[MAX_V];
const int INF = 0x3f3f3f3f;

void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P> > qe; // 按照first从小到大排序
	fill(d, d+V, INF);
	d[s] = 0;
	qe.push(P(0, s));

	while(!qe.empty()) {
		P pr= qe.top();
		qe.pop();
		int v = pr.second;
		if(d[v]<pr.first) continue; // 不是当前最短路径
		for(int i=0; i<G[v].size(); i++) {
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v]+e.cost;
				qe.push(P(d[e.to], e.to));
			}
		}
	}
}

int main() {
	cin>>V>>E;
	int fr, to, ct;
	for(int i=0; i<E; i++) {
		cin>>fr>>to>>ct;
		edge e; 
		e.to = to; e.cost = ct;
		G[fr].push_back(e);
	}
	dijkstra(0);
	for(int i=0; i<V; i++){
		cout<<d[i]<<endl;
	} 
	return 0;
}

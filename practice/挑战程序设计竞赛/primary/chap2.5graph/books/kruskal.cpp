#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring> 
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

struct edge {
	int st, ed, ct;
};

bool comp(const edge& e1, const edge& e2) {
	return e1.ct < e2.ct;
}

const int MAX_V = 10;
const int MAX_E = 20;
edge es[MAX_E];
int V, E;

int par[MAX_V], rk[MAX_V];

void init(int tl) {
	for(int i=0; i<tl; i++) {
		par[i] = i;
	}
	memset(rk, 0, sizeof(rk));
}

int find(int i) {
	if(par[i]==i) return i;
	return par[i] = find(par[i]);
}

void unite(int i, int j) {
	i = find(i);
	j = find(j);
	if(i==j) return ;
	if(rk[i]>rk[j]) par[j] = i;
	else {
		par[i] = j;
		if(rk[i]==rk[j]) rk[j]++;
	}
}

bool same(int i, int j) {
	return find(i)==find(j);
}

int kruskal() {
	sort(es, es+E, comp);
	init(V);
	int res = 0;
	for(int i=0; i<E; i++) {
		edge e = es[i];
		if(!same(e.st, e.ed)) {
			unite(e.st, e.ed);
			res += e.ct;
			cout<<e.ct<<endl;
		}
	}
	return res;
}

int main() {
	cin>>V>>E;
	int from, to, cost;
	for(int i=0; i<E; i++) {
		cin>>es[i].st>>es[i].ed>>es[i].ct;
	}
	int total = kruskal();
	cout<<total<<endl;
	return 0;
}

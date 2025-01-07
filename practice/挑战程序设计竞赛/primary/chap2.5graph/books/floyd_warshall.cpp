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
int d[MAX_V][MAX_V];

int V, E;
const int INF = 0x3f3f3f3f;

void warshall_floyd() {
	for(int k=0; k<V; k++) {
		for(int i=0; i<V; i++) {
			for(int j=0; j<V; j++)
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
		}	
	}
}


int main() {
	fill(d[0], d[0]+MAX_V*MAX_V, INF);
	cin>>V>>E;
	int fm, to, ct;
	for(int i=0; i<E; i++){
		cin>>fm>>to>>ct;
		d[fm][to] = ct;
	}
	for(int i=0; i<V; i++){
		d[i][i] = 0;
	}
	warshall_floyd();
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			if(d[i][j]>1e3) cout<<"INF"<<" ";
			else cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

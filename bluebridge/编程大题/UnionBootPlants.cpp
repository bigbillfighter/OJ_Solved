#include <bits/stdc++.h>
using namespace std;

#define MAX 1000010
typedef long long ll;

int k, m, n, all;
int parent[MAX], rank[MAX];
bool uniRoot[MAX];

int getparent(int a){
	if(parent[a]== a)
		return a;

	else{
		parent[a] = getparent(parent[a]);
		return parent[a];
	}
}

void joRoot(int a, int b){
	int ap = getparent(a), bp = getparent(b);
	int c;
	if(rank[ap] < rank[bp]) {
		while(a!=ap){
			c = a;
			a = parent[a];
			parent[c] = bp;
		}
		parent[ap] = bp;
	}
	else{

		while(b!=bp){
			c = b;
			b = parent[b];
			parent[c] = ap;
		}
		parent[bp] = ap;
		if(rank[ap]==rank[bp]) rank[ap]+=1;
	}
}

void input(){
	scanf("%d %d", &m, &n);
	scanf("%d", &k);
	memset(parent, 0, sizeof(parent));
	memset(rank, 0, sizeof(rank));
	all=m*n;

	for(int i=0; i<all; i++) parent[i]=i;
	for(int i=1; i<=all; i++) cout<<i<<" ";
	cout<<endl;
	for(int i=0; i<all; i++) cout<<parent[i]+1<<" ";
	cout<<endl;
	for(int i=0; i<all; i++) cout<<rank[i]<<" ";
	cout<<endl;
	int a, b;
	while(k--){
		scanf("%d %d", &a, &b);
		a--, b--;
		int ap = getparent(a);
		int bp = getparent(b);
		if(ap!=bp){
			joRoot(a, b);
		}
		for(int i=1; i<=all; i++) cout<<i<<" ";
		cout<<endl;
		for(int i=0; i<all; i++) cout<<parent[i]+1<<" ";
		cout<<endl;
		for(int i=0; i<all; i++) cout<<rank[i]<<" ";
		cout<<endl;
	}

}

void solve(){
	for(int i=0; i<all; i++){
		uniRoot[parent[i]]=1;
	}
	int num=0;
	for(int i=0; i<all; i++){
		if(uniRoot[i]) num++;
	}
	cout<<num<<endl;
}


int main(){
	input();
	solve();
	return 0;
}
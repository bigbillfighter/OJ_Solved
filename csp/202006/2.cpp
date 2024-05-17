#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P; 
int n, a, b;
int index, value;
const int MAXA = 5e5+5;

P pa[MAXA], pb[MAXA]; 

typedef long long LL;
LL rst;

int main(){
	cin>>n>>a>>b;
	for(int i=1; i<=a; i++){
		cin>>pa[i].first>>pa[i].second;
	}
	for(int i=1; i<=b; i++){
		cin>>pb[i].first>>pb[i].second;
	}
	sort(pa+1, pa+1+a); sort(pb+1, pb+1+b);
	int idxa = 1;
	for(int i=1; i<=b; i++){
		while(pa[idxa].first<pb[i].first && idxa<a) idxa++;
		if(pb[i].first==pa[idxa].first) rst += (LL)pb[i].second*pa[idxa].second;
	}
	cout<<rst<<endl;
	return 0;
} 

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N;
typedef long long LL;
LL rst;

int main() {
	cin>>N;
	int nbr;
	priority_queue<int, vector<int>, greater<int> > gpq; 
	for(int i=1; i<=N; i++) {
		cin>>nbr;
		gpq.push(nbr);
	}
	int ea, eb;
	for(int i=1; i<N; i++){
		ea = gpq.top(); gpq.pop();
		eb = gpq.top(); gpq.pop();
		rst += ea+eb;
		gpq.push(ea+eb);
	}
	cout<<rst<<endl;
	return 0;
}

#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
typedef pair<int, int> Stop;
const int MAX_S = 1e4+5;
int L, P;
Stop St[MAX_S];

bool cmp(Stop x, Stop y){
	return x.first > y.first;
}

int main() {
	cin>>N;
	for(int i=1; i<=N; i++) {
		cin>>St[i].first>>St[i].second;
	}
	St[N+1].first = 0, St[N+1].second = 0;
	sort(St+1, St+N+2, cmp);
	cin>>L>>P;
	priority_queue<int> pq;
	int total = 0;

	for(int i=1; i<=N+1; i++){
		while((L-P)>St[i].first && !pq.empty()){
			P+=pq.top();
			pq.pop();
			total++;
		}
		if(pq.empty() && (L-P)>St[i].first){
			cout<<-1<<endl;
			return 0;
		}
		pq.push(St[i].second);
	}
	cout<<total<<endl;
	return 0;
}

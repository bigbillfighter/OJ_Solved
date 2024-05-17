#include <bits/stdc++.h>
using namespace std;

int N, M;
const int MAXN = 1e3+5;
int num[MAXN], prs[MAXN];

int main(){
	cin>>N>>M;
	int max = 0; int idx = 1;
	for(int i=1; i<=N; i++){
		cin>>num[i];
		int total = 0;
		for(int j=1; j<=M; j++){
			cin>>prs[j];
			total -= prs[j];
		}
		if(total>max){
			max = total, idx = i;
		} 
		num[i] -= total;
	}
	int total=0;
	for(int i=1; i<=N; i++){
		total += num[i];
	}
	cout<<total<<" "<<idx<<" "<<max<<endl;
	return 0;
} 

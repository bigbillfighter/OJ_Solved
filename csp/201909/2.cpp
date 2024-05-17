#include <bits/stdc++.h>
using namespace std;

int n;
int m;
const int MAXM = 1e3+5;
int a[MAXM]; 
int drop[MAXM];

int total;
int drop_trees;
int continuous_drop_trees;

int main(){
	cin>>n;
	int first, last, decrease;
	for(int i=1; i<=n; i++){
		cin>>m;
		decrease = 0;
		cin>>a[1];
		first=last=a[1];
		for(int j=2; j<=m; j++){
			cin>>a[j];
			if(a[j]<=0) decrease += a[j];
			else{
				first = last;
				last=a[j];
				if(first+decrease != last) drop[i] = 1;
				decrease=0;
			}
		}
		total += last+decrease;
		
	}
	for(int i=1; i<=n; i++){
		if(drop[i]) {
			drop_trees++;
			if(drop[((i)%n)+1] && drop[((i+1)%n)+1]) continuous_drop_trees++;

		}
		 
	}
	cout<<total<<" "<<drop_trees<<" "<<continuous_drop_trees<<endl;
	return 0;
} 

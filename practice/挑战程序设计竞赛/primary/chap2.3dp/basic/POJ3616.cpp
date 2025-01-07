#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

struct milknode{
	int st, ed, value;
	bool operator < (const milknode &a) const {
		return st < a.st;
	}
};

typedef long long LL;
const int maxm = 1e3+5;
const int maxn = 1e6+5;
int n, m, r;
milknode itl[maxm];

int dp[maxm];

void solve(){
	scanf("%d%d%d", &n, &m, &r);
	int i, j;
	for(i=0; i<m; i++){
		scanf("%d%d%d", &itl[i].st, &itl[i].ed, &itl[i].value);
		itl[i].ed+=r;
	}
	sort(itl, itl+m);
	dp[0] = itl[0].value;
	int maxvalue=dp[0];
//	cout<<maxvalue<<endl;
	for(i=1; i<m ;i++){
		dp[i] = itl[i].value;
		for(j=0; j<i; j++){
			if(itl[j].ed<=itl[i].st){
				dp[i] = max(dp[i], dp[j]+itl[i].value);
			}
		}
		maxvalue = max(maxvalue, dp[i]);
	}
	cout<<maxvalue<<endl;
}
	

int main(){
	solve();
	return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;

int n, k;

void solve(){
	scanf("%d%d", &n, &k);
	int tg = n-1;
	int ans = max(tg-(tg/k)*(k-1), (tg/k-1)*k);
	cout<<ans<<endl;
}

int main(){
	solve();
	return 0;
}

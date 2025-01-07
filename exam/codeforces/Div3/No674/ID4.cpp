#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>
using namespace std;

int n; 
const int MAX_N = 2e5+5;
int arry[MAX_N];
typedef long long LL;
int ans;
map<LL, int> mp;
 
void solve(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &arry[i]);
	}
	LL sum=0;
	for(int i=0; i<n; i++){
		sum+=arry[i];
		if(sum==0||mp[sum]){
			ans++;
			sum = arry[i];
			mp.clear();
			mp[sum]=1;
		}
		mp[sum] = 1;
	}
	printf("%d\n", ans);
}

int main(){
	solve();

	return 0;
}

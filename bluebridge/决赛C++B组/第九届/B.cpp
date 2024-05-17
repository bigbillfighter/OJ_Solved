// 2178309
#include<cstdio>
using namespace std;

int ans;

void dfs(int cur, int stp, int last){
	if(stp==0) {
		ans++;
		return;	
	}
	for(int i=0; i<2; i++){
		if(!(last==1&&i==1))
			dfs(last, stp-1, i);
	}
}

void solve(){
	dfs(0, 30, 0);
	cout<<ans<<endl;
}

int main(){
	solve();
	return 0;
}

#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int t;
int m, n;
int u1, u2, d1, d2;

void solve(){
	scanf("%d", &t);
	while(t--){
		bool flag = false;
		scanf("%d %d", &n ,&m);
		while(n--){
			scanf("%d%d%d%d", &u1, &u2, &d1, &d2);
			if(d1==u2) flag=true;
		}
		if(m%2!=0||!flag){
			printf("NO\n");
		}else printf("YES\n");
		
	}
}

int main(){
	solve();
	return 0;
}

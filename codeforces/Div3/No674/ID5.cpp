#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int n;
 
void solve(){
	scanf("%d", &n);
	int a1, a2, a3;
	int b1, b2, b3;
	scanf("%d %d %d", &a1, &a2, &a3);// r, s, p
	scanf("%d %d %d", &b1, &b2, &b3);
	int mam = min(a1, b2)+min(a2, b3)+min(a3, b1);
	
	int p1 = min(a2, b1);
	int p2 = min(a3, b2);
	int p3 = min(a1, b3);
	int u1 = b1-p1, u2 = b2-p2, u3 = b3-p3;
	int v1=0, v2=0, v3=0;
	if(u1>0) v1 = max(0, u1-a1);
	if(u2>0) v2 = max(0, u2-a2);
	if(u3>0) v3 = max(0, u3-a3);
	int mim = max(v1, v2);
	mim = max(mim, v3);
	printf("%d %d\n", mim, mam);
}

int main(){
	solve();

	return 0;
}

#include<cstdio>
#include<iostream>
using namespace std;

int N;
int tri[355][355];

void solve(){
	int i, j;
	for(i=N-2; i>=0; i--){
		for(j=0; j<=i; j++){
			tri[i][j] += max(tri[i+1][j], tri[i+1][j+1]);
		}
	}
	printf("%d\n", tri[0][0]);
}

int main() {
	int i, j;
	scanf("%d", &N);
	for(i=0; i<N; i++){
		for(j=0; j<=i; j++)
			scanf("%d", &tri[i][j]);
	}
	solve();
    return 0;
}

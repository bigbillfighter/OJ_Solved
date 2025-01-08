#include<cstdio>
#include<iostream>
using namespace std;

int N;
const int MAX_N = 102;
int candy[MAX_N]; 
int hlf[MAX_N];
int pvd;

void solve(){
	scanf("%d", &N);
	int i;
	for(i=0; i<N; i++){
		scanf("%d", &candy[i]);
		hlf[i] = candy[i]/2;
	}
	bool flag = false;
	while(!flag){
		for(i=0; i<N; i++){
			candy[i] = candy[i] - hlf[i] + hlf[(i+1)%N];
		}
		flag = true;
		int crt = 0;
		for(i=0; i<N; i++){
			if(!i) crt = candy[i];
			else{
				flag = flag && (crt==candy[i]);
				crt = candy[i];
			}  
			if(candy[i]%2){
				pvd++;
				candy[i]++;
			}
			hlf[i] = candy[i] / 2;
//			cout<<candy[i]<<" ";
		}
//		cout<<endl;
	}
	
	printf("%d\n", pvd);
}

int main(){
	solve();
	return 0;
} 

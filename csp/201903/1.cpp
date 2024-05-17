#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 1e5+5;
int lt[MAXN];

int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>lt[i];
	}
	sort(lt+1, lt+n+1);
	if(n%2!=0){
		cout<<lt[n]<<" "<<lt[(n+1)/2]<<" "<<lt[1]<<endl;
	}else{
		if((lt[n/2]+lt[n/2+1])%2==0)
			cout<<lt[n]<<" "<<(lt[n/2]+lt[n/2+1])/2<<" "<<lt[1]<<endl;
		else
			printf("%d %.1f %d\n", lt[n], ((float)lt[n/2]+lt[n/2+1])/2, lt[1]);
	}
	return 0;
} 

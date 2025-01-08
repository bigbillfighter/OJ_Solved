//55965365465060
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

bool prm[2020];
typedef long long LL;
LL dp[2020];

bool isprime(int a){
	int b = sqrt(a);
	if(a<=1) return false;
	if(a==2) return true;
	if(a%2==0) return false;
	for(int i=3; i<=b; i+=2){
		if(a%i==0) return false;
	}
	return true;
} 


void solve(){
	memset(prm, false, sizeof(prm));
	for(int i=1; i<=2019; i++){
		if(isprime(i)) prm[i] = true;
	}
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=0; i<=2019; i++){
		if(prm[i]){
			for(int j=2019; j>=i; j--){
				dp[j] += dp[j-i]; 
			}
		}
	}
	printf("%lld", dp[2019]);
}

int main(){
	solve();
	return 0;
}

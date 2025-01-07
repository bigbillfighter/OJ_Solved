//45360 
#include<iostream>
#include<cstdio>
using namespace std;

void solve(){
	int a=100;
	while(1){
		int sum=0;
		for(int i=1; i<=a; i++){
			if(a%i==0) sum++;
		}
		if(sum==100) break;
		else a++;
	}
	cout<<a<<endl;
}

int main(){
	solve();
	return 0;
}

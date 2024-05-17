//74
#include<iostream>
#include<cstdio>
using namespace std;

void solve(){
	int i;
	for(i=1; i<=200/21; i++){
		if((200-21*i)%5==0) break;
	}
	cout<<i*11+(200-21*i)/5<<endl;
}

int main(){
	solve();
	return 0;
}

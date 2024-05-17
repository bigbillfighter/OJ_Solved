#include <bits/stdc++.h>
using namespace std;

int n;
typedef long long LL;
int w, score;
LL rst = 0L;

int main(){
	cin>>n;
	while(n--){
		cin>>w>>score;
		rst += w*score;	
	}
	rst = rst>0?rst:0;
	cout<<rst<<endl;
	return 0;
} 

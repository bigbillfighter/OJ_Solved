#include <bits/stdc++.h>
using namespace std;

int r, y, g;
int total;
int n;

int cls, secs;

int main(){
	cin>>r>>y>>g>>n;
	for(int i=1; i<=n; i++){
		cin>>cls>>secs;
		if(cls<=1) total+= secs;
		else if(cls==2) total = total+r+secs;
	}
	cout<<total<<endl;
	return 0;
} 

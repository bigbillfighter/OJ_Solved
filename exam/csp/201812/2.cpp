#include <bits/stdc++.h>
using namespace std;

int r, y, g;
typedef long long LL;

int n;

int cls, secs;

LL total;

int main(){
	cin>>r>>y>>g>>n;
	
	LL all = r+y+g, mid = r+g;
	LL now;
	
	for(int i=1; i<=n; i++){
		cin>>cls>>secs;
		if(cls==0) total+=secs;
		else{
			if(cls==1)
				now = (r-secs+total)%all;
			else if(cls==3)
				now = (mid-secs+total)%all;
			else now=(all-secs+total)%all;
			
			if(now<=r) total+=r-now;
			else if(now>=mid) total += all-now+r;
		}
//		cout<<total<<endl;
	}
	
	cout<<total<<endl;
	return 0;
} 

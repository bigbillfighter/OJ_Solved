#include <bits/stdc++.h>
using namespace std;

int n; 
int a[4];

bool judge(int m){
	while(m){
		if(m%10==7) return true;
		m/=10;
	}
	return false;
}

int main(){
	cin>>n;
	int count=0, i=0;
	while(count<n){
		i++;
		if(judge(i) || i%7==0) {
			a[(i-1)%4]++;
			continue;
		}	
		count++;	
	}
	for(int i=0; i<4; i++){
		cout<<a[i]<<endl;
	}
	return 0;
} 

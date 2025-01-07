#include<iostream>
#include<cstdio> 
#include<string>
using namespace std;

void solve(){
	int MAX_A = 2019/3, MAX_B = 2019/2;
	int res, crt, t;
	int ans=0;
	bool flag;
	for(int i=1; i<=MAX_A; i++){
		crt = i;
		flag = false;
		while(crt){
			t = crt%10;
			crt/=10;
			if(t==2||t==4){
				flag=true;
				break;
			}
		}
		if(flag) continue;
		for(int j=i+1; j<=MAX_B; j++){
			res = 2019-i-j;
			if(res<=j) break;
			flag = false;
			crt = j;
			while(crt){
				t = crt%10;
				crt/=10;
				if(t==2||t==4){
					flag = true;
					break;
				}
			}
			if(flag) continue;
			crt = res;
			while(crt){
				t = crt%10;
				crt/=10;
				if(t==2||t==4){
					flag = true;
					break;
				}
			}
			if(!flag){
				ans++;
				cout<<i<<" "<<j<<" "<<res<<endl;
			} 
		}
		
	}
	printf("%d\n", ans);
}

int main(){
	solve();	
	return 0;
} 

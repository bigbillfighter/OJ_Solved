//7020
#include<iostream>
#include<cstdio> 
using namespace std;

void solve(){
	bool flag=false;
	int x, y = 2019;
	int m = 2019*2019;
	int judge = 1;
	while(!flag){
		y+=2;
		for(x=(2019+y)/2; x<y; x++){
			judge = m+y*y - 2*x*x;
			if(judge==0){
				flag = true;
				break;
			}else if(judge<0) break; 
		}
	}
	printf("%d\n", x+y);
}

int main(){
	solve();
	return 0;
}

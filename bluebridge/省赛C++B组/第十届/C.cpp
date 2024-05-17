#include<iostream>
#include<cstdio> 
#include<string>
using namespace std;

void solve(){
	int a=1, b=1, c=1, sum;
	for(int i=4; i<=20190324; i++){
		sum = (a+b+c)%10000;
		a = b;
		b = c;
		c = sum;
	}
	printf("%d", sum);
}

int main(){
	solve();	
	return 0;
} 

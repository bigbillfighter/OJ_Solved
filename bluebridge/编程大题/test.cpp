#include <iostream>
using namespace std;
int a[6000];
int c=0;
int s;
int flag=1;

void mul(int i, int m){
	s= m*a[i]+c;
	c = s/10;
	a[i] = s%10;
	if(c>0&&(i-flag>(-2))) flag=i+2; 
}

void fun(int n){
	int i=1;
	//int k=0;
	while(i<=n){
		for(int j=0; j<=flag; j++){
			mul(j,i);
		}
		i++;
	}
}

int main(){
	int n = 0;
	cin>>n;
	a[0]=1;
	fun(n);
	for(int i=flag-1;i>=0; i--){
		cout<<a[i];
	}
	return 0;
}

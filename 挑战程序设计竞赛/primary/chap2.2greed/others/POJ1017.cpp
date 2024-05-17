#include<cstdio>

using namespace std;

int main(){
	int n,a,b,c,d,e,f,x,y;
	int u[4]={0,5,3,1};
	while(1){
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
 		if(a||b||c||d||e||f){
 			n=d+e+f+(c+3)/4;//懂了
 			y=5*d+u[c%4];//在已有n个的情况下，能装下y个2*2的
	 		if(b>y)
	 			n+=(b-y+8)/9;//把多的2*2的弄进来
	 		x=36*n-36*f-25*e-16*d-9*c-4*b;
	 		if(a>x)
	 			n+=(a-x+35)/36;//把1*1的弄进来
	 		printf("%d\n",n);
		}else break;
 	}
 	return 0;
 }


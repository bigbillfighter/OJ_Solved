#include<cstdio>

using namespace std;

int main(){
	int n,a,b,c,d,e,f,x,y;
	int u[4]={0,5,3,1};
	while(1){
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
 		if(a||b||c||d||e||f){
 			n=d+e+f+(c+3)/4;//����
 			y=5*d+u[c%4];//������n��������£���װ��y��2*2��
	 		if(b>y)
	 			n+=(b-y+8)/9;//�Ѷ��2*2��Ū����
	 		x=36*n-36*f-25*e-16*d-9*c-4*b;
	 		if(a>x)
	 			n+=(a-x+35)/36;//��1*1��Ū����
	 		printf("%d\n",n);
		}else break;
 	}
 	return 0;
 }


/*
\    /
 \  / 
  \/
  /\
 /  \
/    \
�����������Ϊ���Ļ���Ϊ4�飬д��ÿ��ֱ�ߵı��ʽ���� 
*/ 
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

typedef long long LL;
LL dis;

void solve() {
	LL x, y;
	scanf("%lld %lld", &x, &y);
	if(y>0&&y>x&&y>=-x) dis = 4*y*y - y+ x;
	else if(x>0&&y<=x&&y>-x) dis = 4*x*x - y+x;
	else if(y<0&&y<=-x&&y<x) dis = (2*y-1)*(2*y-1) -x + y -1;
	else if(x<0&&y>=x&&y<-x) dis = (2*x+1)*(2*x+1) -x + y -1;
	printf("%lld\n", dis);
 
}

int main() {
	solve();
	return 0;
}

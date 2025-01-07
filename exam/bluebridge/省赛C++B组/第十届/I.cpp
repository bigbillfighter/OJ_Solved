/*
����Ŀ������ɽ���С�����������С��M����Ϊ�෴����
Ȼ����ӵõ����Ľ��������������û�п��ǵ���׺���ʽ
��Ȼ�������ŵ����ʡ�
�� 2 3 4 5�� N=1��M=2�����մ�����뷨������5+4-3-2=4��
���ǻ��и��������Ϊ5+4-(2-3)=10
���ߵĺ�׺���ʽΪ5423--+�ǿ�����ɵ�

���Խ��������Ǽ��ֲ�ͬ�������
1.���M=0����û�и��ţ�������������������
2.����M>=1,����֤��M>=2��M=1��Ч��һ������Ϊ���������� 
��ȫΪ������ʱ��ֻ����������С���� 
a)M=1ʱ ����С����Ϊ A0,A1,...,Am+n
sum = Am+n + Am+n-1 +... +A1-A0
b)M>=2ʱ �� sum=Am+n + Am+n-1 +...+ Am - (A0 - A1 - A2 - ... -Am-1)
				= Am+n + Am+n-1 +...+ Am -A0 + A1 + A2 +  ... + Am-1
3.���ȫ�Ǹ����� ֻ�������������
a)M=1ʱ�� A0��С�� Am+n�������A0�ľ���ֵ���
	sum = Am+n - (A0+A1+...+Am+n-1)
b)M>=2ʱ��sum = Am+n - A0 - A1-...-Am-2 -(Am-1 + Am + ... + An+m-1) 
4. ������и���������������Ϊ���о���ֵ�����
a) ���M=1 
	A0��С<0, Am+n���>0
	ѡ�����и�����A0, A1, ..., Ak
	��Ak+1, Ak+2, ..., Am+n��Ϊ����
	sum = Ak+1 + Ak+2 + ... + Am+n - (A0 + A1 +... + Ak)Ϊȫ������ֵ���
b) ���M>=2 
	��ǰ��˵��Ч����ͬ
	 A0, A1, ..., Am-1, Am, ..., Ak<0
	 Ak+1, Ak+2, ... , Am+n>=0
	 sum = Ak+1 + Ak+2 + ... + At - (A0+A1+...+As + At+1 + At+2+... +Am+n) - Ak - Ak-1 -... -As+1
 	����Ӧs��tʹ��sum�Ľ���ܿ�������Ϊ��������ֵ�ĺ� 
*/
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio> 
#include<cstdlib>
using namespace std;

const int MAX_N = 1e5+5;
typedef long long LL;
int A[2*MAX_N];
int M, N;
const int INF=0x3f3f3f3f; 


void solve(){
	int minm=INF, maxm=-1;
	LL sum=0;
	LL tmp=0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M+N+1; i++){
		scanf("%d", &A[i]);
		minm = min(minm, A[i]);
		maxm = max(maxm, A[i]);
		sum+=abs(A[i]);
		tmp+=A[i];
	}
	if(M==0){
		printf("%lld\n", tmp);
		return;
	}
	if(maxm<0){
		printf("%lld\n", sum+maxm+maxm);
		return;
	}
	if(minm>0){
		printf("%lld\n", sum-minm-minm);
		return;
	}
	printf("%lld\n", sum);
	return;
	
}

int main(){
	solve();
	return 0;
} 

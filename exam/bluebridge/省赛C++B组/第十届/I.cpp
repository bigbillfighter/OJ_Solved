/*
本题目容易想成将从小到大排序后将最小的M个变为相反数，
然后相加得到最后的结果。但是这样并没有考虑到后缀表达式
天然带有括号的性质。
如 2 3 4 5， N=1，M=2，按照错误的想法，就是5+4-3-2=4。
但是还有更大的数，为5+4-(2-3)=10
后者的后缀表达式为5423--+是可以完成的

所以接下来考虑几种不同的情况。
1.如果M=0，即没有负号，则将所有数加起来即可
2.但凡M>=1,可以证明M>=2和M=1的效果一样，因为负负得正。 
当全为正数的时候，只能牺牲掉最小正数 
a)M=1时 ，从小到大为 A0,A1,...,Am+n
sum = Am+n + Am+n-1 +... +A1-A0
b)M>=2时 ， sum=Am+n + Am+n-1 +...+ Am - (A0 - A1 - A2 - ... -Am-1)
				= Am+n + Am+n-1 +...+ Am -A0 + A1 + A2 +  ... + Am-1
3.如果全是负数， 只能牺牲到最大负数
a)M=1时， A0最小， Am+n最大，所以A0的绝对值最大
	sum = Am+n - (A0+A1+...+Am+n-1)
b)M>=2时，sum = Am+n - A0 - A1-...-Am-2 -(Am-1 + Am + ... + An+m-1) 
4. 如果既有负数又有正数，则为所有绝对值的相加
a) 如果M=1 
	A0最小<0, Am+n最大>0
	选出所有负数的A0, A1, ..., Ak
	则Ak+1, Ak+2, ..., Am+n都为正数
	sum = Ak+1 + Ak+2 + ... + Am+n - (A0 + A1 +... + Ak)为全部绝对值相加
b) 如果M>=2 
	如前所说，效果相同
	 A0, A1, ..., Am-1, Am, ..., Ak<0
	 Ak+1, Ak+2, ... , Am+n>=0
	 sum = Ak+1 + Ak+2 + ... + At - (A0+A1+...+As + At+1 + At+2+... +Am+n) - Ak - Ak-1 -... -As+1
 	自适应s和t使得sum的结果总可以满足为各数绝对值的和 
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

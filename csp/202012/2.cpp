#include <bits/stdc++.h>
using namespace std;

/*
前缀和
该题目的所有可能的答案的集合就是安全指数的集合， 
先将所有节点按照安全指数，是否会挂科排序，
假定第一个安全指数是阈值 
当来到某个点，这个点满足前面的安全指数和自己不同时，
判断阈值是否需要更新，即依据该点前面0的个数和包括该点后面1的个数。
使用前缀和统计前i个数得分，很容易就可以计算，
如果结果不小于前一个阈值算得的结果，则更新阈值。 
*/ 

int m;
const int MAXM = 1e5+5;
typedef pair<int, int> P;
P security[MAXM];

set<int> st; 
int sum[MAXM];

int main(){
	scanf("%d", &m);

	for(int i=1; i<=m; i++){
		scanf("%d%d", &security[i].first, &security[i].second); 
	}
	sort(security+1, security+m+1);

	for(int i=1; i<=m; i++){
		sum[i] = sum[i-1]+security[i].second; 
	}
	
	int threshold = security[1].first;
	int ticks = 0;
	int zeros, ones;
	 
	for(int i=1; i<=m; i++){
		if(st.count(security[i].first)) continue;
		st.insert(security[i].first);
		zeros = i-1-sum[i-1];	
		ones = sum[m]-sum[i-1];
		if(zeros+ones>=ticks){
			ticks = zeros+ones;
			threshold = security[i].first;
		}
		
	}
	cout<<threshold<<endl;
	return 0;
} 

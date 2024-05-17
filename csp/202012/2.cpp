#include <bits/stdc++.h>
using namespace std;

/*
ǰ׺��
����Ŀ�����п��ܵĴ𰸵ļ��Ͼ��ǰ�ȫָ���ļ��ϣ� 
�Ƚ����нڵ㰴�հ�ȫָ�����Ƿ��ҿ�����
�ٶ���һ����ȫָ������ֵ 
������ĳ���㣬���������ǰ��İ�ȫָ�����Լ���ͬʱ��
�ж���ֵ�Ƿ���Ҫ���£������ݸõ�ǰ��0�ĸ����Ͱ����õ����1�ĸ�����
ʹ��ǰ׺��ͳ��ǰi�����÷֣������׾Ϳ��Լ��㣬
��������С��ǰһ����ֵ��õĽ�����������ֵ�� 
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

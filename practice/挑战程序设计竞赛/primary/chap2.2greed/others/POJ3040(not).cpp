/*������С��C��Ӳ������û�취��Լ�����ͣ���ͳͳ������

Ȼ���Ӳ�����Ӵ�С�����յýӽ�C��������ڻ���C�����ǲ��ܳ���C��

���Ű�Ӳ������С�������C����������˼��������һ����С��ֵ��ps�˴�����С��ֵָ����Ӳ��ʣ������Ϊ0����ЩӲ���е���С��ֵ��������֮��ó������Ž⣬���������벽��2.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n, c; 
const int maxn=20+5;
struct coinnode{
	int value, number;
};

typedef long long LL;

coinnode coins[maxn];

bool coincmp(coinnode a, coinnode b){
	return a.value > b.value;
}


int main(){
	scanf("%d%d", &n, &c);
	int i, j;
	for(i=0; i<n; i++){
		scanf("%d%d", &coins[i].value, &coins[i].number);
	}
	sort(coins, coins+n, coincmp);
	LL ans = 0;
	for(i=0; i<n; i++){
		if(coins[i].value >= c) ans+=coins[i].number;
		else{
			for(j=n-1; j>i; j--){
				if(coins[i].value+coins[j].value>=c){
					int mim = min(coins[i].number, coins[j].number);
					ans += mim;
					coins[i].number -= mim;
					coins[j].number -= mim;
					
				}
			}
			if(coins[i].number){
				int per = (c+coins[i].value-1) / coins[i].value;
				ans += coins[i].number / per;
			} 
		}
	}	
	printf("%lld\n", ans);
	return 0;
}

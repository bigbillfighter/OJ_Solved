/*首先面额不小于C的硬币属于没办法节约的类型，先统统发掉。

然后对硬币面额从大到小尽量凑得接近C，允许等于或不足C，但是不能超出C。

接着按硬币面额从小到大凑满C（凑满的意思是允许超出一个最小面值，ps此处的最小面值指的是硬币剩余量不为0的那些硬币中的最小面值），凑满之后得出了最优解，发掉，进入步骤2.
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

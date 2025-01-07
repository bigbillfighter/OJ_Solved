#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int num, result;
vector<int> p;
const int INF = 0x3f3f3f3f;
int mp[12];
typedef long long LL;
char a[11];

int cal_yong(int num){
	int i, j;
	fill(mp, mp+12, 0);
	for(i=0; i<num; i++){
		mp[i] = p[i];
	}
	for(i=1; i<num; i++){
		for(j=0; j<num-i; j++){
			mp[j] = mp[j] + mp[j+1];
		}
	}
	return mp[0];
}

void solve(){
	int i, yong;
	LL mim, cur;
	while(~scanf("%d%d", &num, &result)){
		p.clear();
		mim = 1e11;
		for(i=1; i<=num; i++){
			p.push_back(i);
		}
		do{
			yong = cal_yong(num);
			if(yong==result){
				cur = 0;
				for(i=0; i<num; i++){
					cur=cur*10 + p[i];
				}
				if(cur < mim){
					for(i=0; i<num; i++){
						a[i] = 'a'+p[i];
					}
					mim = cur;
				}
				break;
			}
		}while(next_permutation(p.begin(), p.end()));
		for(i=0; i<num; i++){
			printf("%d ", a[i]-'a');
		}
		printf("\n");
	}
	
}

int main() {
    solve();
    return 0;
}

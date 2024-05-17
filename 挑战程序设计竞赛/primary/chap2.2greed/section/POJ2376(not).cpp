#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int N, T;
typedef pair<int, int> Pr;
Pr cows[25005];

bool prcmp(Pr a, Pr b){
	return a.first < b.first;
}

void solve(){
	int i, j;
	sort(cows, cows+N, prcmp);
	i=0;
	int mam = cows[0].second;
	int last = 0;
	while(cows[++i].first==1){
		if(cows[i].second>mam){
			mam = cows[i].second;
			last = i;
		}
	}
	if(mam==T){
		printf("%d\n", 1);
		return;
	}
	j=i;
	int num=1, id=last;
	mam = 0;
	for(i=j; i<N; i++){
		if(cows[i].first > cows[last].second+1){
			num++;
			if(cows[id].second < cows[i].first-1){
				printf("%d\n", -1);
				return;
			}
			last = id;
			mam = 0;
			i--;
		}else{
			if(cows[i].second > mam){
				mam = cows[i].second;
				id = i;
			} 
		}
	}
	printf("%d\n", ++num);
	
}

int main() {
	while(scanf("%d%d", &N, &T)==2){
		int i, j;
		int cx, cy;
		int flag1 = false, flag2 = false;
		for(i=0; i<N; i++){
			scanf("%d%d", &cx, &cy);
			if(cx==1) flag1 = true;
			if(cy==T) flag2 = true;
			cows[i].first = cx, cows[i].second = cy;
		}
		if(!(flag1&&flag2)) {
			printf("%d\n", -1);
			continue; 
		}
		solve();
	}
    
    return 0;
}

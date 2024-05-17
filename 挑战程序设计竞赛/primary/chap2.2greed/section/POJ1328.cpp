#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
 
int n, d;
const int maxn = 1e3+5; 
typedef pair<double, double> pr;
pr section[maxn];
const double eps = 1e-5;


bool seccmp(pr a, pr b){
	return a.second < b.second;
}

void solve(){
	scanf("%d%d", &n, &d);
	int i, j;
	int x, y;
	int ncase = 0;
	while(n||d){
		ncase++;
		bool flag = false;
		for(i=0; i<n; i++){
			scanf("%d%d", &x, &y);	
			if(y<0||y>d||d<0) flag = true;
			section[i].first = x - sqrt((double)d*d-y*y);
			section[i].second = x + sqrt((double)d*d-y*y); 
		}
		

		if(flag){
			printf("Case %d: -1\n", ncase);
		}else{
			sort(section, section+n, seccmp);
//			for(i=0; i<n ;i++){
//				cout<<section[i].first<<" "<<section[i].second<<endl;
//			}

			int rds = 0;
			int pos = 0;

			for(i=0; i<n;){
				pos = i;
				while(i<n && section[i].first < section[pos].second+eps) i++;
				rds++;	
			}
			printf("Case %d: %d\n", ncase, rds);
		}
		
		scanf("%d%d", &n, &d);
	}
	
}


int main() {
	solve();
    return 0;
}

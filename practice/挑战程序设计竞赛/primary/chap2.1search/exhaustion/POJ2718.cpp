#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int n;
const int INF = 1e6;
vector<int> p;

int sm_diff(int k){
    int mim = INF;
    int num1, num2;
    int hf = k/2;
    int i;
    do{
    	num1 = 0, num2 = 0;
    	for(i=0; i<hf; i++){
    		num1 = num1*10+p[i];
		}
		for(i=hf; i<k; i++){
			num2 = num2*10+p[i];
		}
		if((p[0]==0&&num1!=0) || p[hf]==0&&num2!=0) continue;
		mim = min(mim, abs(num2-num1));
	}while(next_permutation(p.begin(), p.end()));
	return mim;
}

void solve(){
    scanf("%d", &n);
    char cc;
    int k;
    cc = getchar();
    while(n--){
    	p.clear();
        k=0;
        do{
            cc = getchar();
            if(cc-'0'>=0&&cc-'0'<=9){
                p.push_back(cc-'0');
                k++;
            }
            else if(cc==' ') continue;
        }while(cc!='\n');
        printf("%d\n", sm_diff(k));
    }
}

int main() {
    solve();
    return 0;
}

#include <iostream> 
#include <cstdio>
using namespace std;

int N;
const int MAX_N = 2e3+5; 
char str[MAX_N];

void solve(){
	scanf("%d", &N);
	int i, j;
	char cr;
	for(i=0; i<N; i++){
		scanf(" %c", &cr);
		str[i] = cr;
	}
	int lt =0 , rt = N-1;
	j = 0;
	while(lt <= rt){
		bool flag = false;
		for(i=0; rt-lt>=2*i; i++){
			if(str[lt+i] < str[rt-i]){
				flag = true;
				break;
			}
			if(str[lt+i] > str[rt-i]){
				flag = false;
				break;
			}
		}
		if (flag){
			putchar(str[lt++]);
			j++;
			if(j%80==0) putchar('\n');	
		}
		else{
			putchar(str[rt--]);
			j++;
			if(j%80==0) putchar('\n');	
		} 
	} 
}

int main(){
	solve();
	return 0;
}

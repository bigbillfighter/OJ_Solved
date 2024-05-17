#include <bits/stdc++.h>
using namespace std;

int m, n;
const int MAXN = 55;
const int MAXM = 1e3+5;

char instr[10];
typedef pair<char, int> P;
P crpt[28][MAXN]; 

int main(){
	cin>>n>>m;
	for(int i=1; i<=26; i++){
		for(int j=1; j<=n; j++){
			cin>>instr;
			crpt[i][j].first = instr[0];
			int page = 0;
			for(int k=1; instr[k]!='\0'; k++){
				page = page*10+instr[k]-'0';
			}
			crpt[i][j].second = page;
		}
	}
	for(int i=1; i<=26; i++){
		for(int j=1; j<=n; j++){
			cout<<crpt[i][j].first<<" "<<crpt[i][j].second<<"\t";	
		}
		cout<<endl;
	}
	
	return 0;
} 

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<bitset>
#include<sstream>
using namespace std;

const int M = 10;
const int N = 32;
int nbr[M][N];

void solve() {
	for (int i = 0; i<M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &nbr[i][j]);
		}
	}

	for (int i = 0; i<M; i++) {
		for (int j = 0; j<N; j++) {
			string stra;
			stringstream stmb;
			bitset<8> bs(nbr[i][j]);
			stmb << bs;
			stra = stmb.str();
			int len_s = stra.length();
			for(int k = 0; k < len_s; k++){
				if(stra[k] == '0') printf(" ");
				else printf("*");
			}
			if((j + 1) % 2 == 0) printf("\n");
		}
		printf("\n");
	}
}

int main() {
	solve();
	return 0;
}

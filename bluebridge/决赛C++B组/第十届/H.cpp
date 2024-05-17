#include<iostream>
#include<cstdio>
using namespace std;

int T;
char A[15], B[15], C[15];
int CA[4][3];
int BA[8][3];

void solve(){
	scanf("%d", &T);
	int i, j, ans;
	for(i=0; i<4; i++){
		for(j=0; j<3; j++){
			CA[i][j] = (i+j*4) %12;
		}
	}
	for(i=0; i<8; i++){
		for(j=0; j<3; j++){
			BA[i][j] = (i+j*8) %12;
		}
	}

	while(T--){
		ans = 0;
		scanf("%s%s%s", A, B, C);
		for(i=0; i<8; i++){
			if(B[i]=='G'){
				for(j=0; j<3; j++){
					if(A[BA[i][j]]!='G'){
						A[BA[i][j]]='G';
						break;
					}
				}
			}
		}
		
		for(i=0; i<4; i++){
			if(C[i]=='G'){
				for(j=0; j<3; j++){
					if(A[CA[i][j]]!='G'){
						A[CA[i][j]]='G';;
						break;
					}		
				}
			}
		}
		
		for(i=0; i<12; i++){
			if(A[i]=='G') ans++;	
		} 
		if(ans==12) printf("YES\n");
		else printf("NO\n");			
	}
}

int main(){
	solve();
	return 0;
}

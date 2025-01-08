#include <bits/stdc++.h>
using namespace std;

int T;
const int MAX_N = 3e5+5;
int nbr;
int A[MAX_N];
typedef long long LL;
LL S[MAX_N];

bool cmp(LL a, LL b){
	return a>b;
}

LL max(LL a, LL b){
	if(a>b) return a;
	else return b;
}

void solve(){
	scanf("%d", &T);
	int i, k;
	int ind1=0, ind2=0;
	int sl, bg;
	while(T--){
		memset(S, 0, sizeof(S));
		scanf("%d", &nbr);
		for(i=1; i<=nbr; i++){
			scanf("%d", &A[i]);;
			S[i] = S[i-1] + A[i];
		}
		LL maxm = -1;
		if(S[0]<=S[nbr]){
			sort(S+1, S+nbr);
			if(S[1]>=S[nbr]&&S[1]>=S[0]){
				printf("%lld\n", max(S[nbr-1]-S[nbr], S[1]-S[0]));
				continue;
			}
			if(S[nbr-1]<=S[nbr]&&S[nbr-1]<=S[0]){
				printf("%lld\n", max(S[nbr]-S[nbr-1], S[0]-S[1]));
				continue;
			}
			
			
			for(i=1; i<nbr; i++){
				if(S[i]>0){
					ind1 = i;
					break;
				}
			} 
			for(i=nbr-1; i>0; i--){
				if(S[i]<S[nbr+1]){
					ind2 = i;
					break;
				}
			}
			
			if(ind1==1) maxm = max(maxm, S[ind1]-S[0]);
			else if(ind1==2){
				maxm = max(maxm, S[ind1]-S[1]);
				maxm = max(maxm, S[0]-S[1]);
			}else{
				for(k=ind1-1; k>=3; k--){
					maxm = max(maxm, S[k]-S[k-2]);
				}
				maxm = max(maxm, S[ind1]-S[ind1-1]);
				maxm = max(maxm, S[0]-S[ind1-2]);
			}
			
			if(ind2==nbr-1) maxm = max(maxm, S[nbr]-S[ind2]);
			else if(ind2 == nbr-2){
				maxm = max(maxm, S[ind2+1]-S[ind2]);
				maxm = max(maxm, S[ind2+1]-S[nbr]);
			}else{
				for(k=ind2+1; k<=nbr-3; k++){
					maxm = max(maxm, S[k+2] - S[k]);
				}
				maxm = max(maxm, S[ind2+1]-S[ind2]);
				maxm = max(maxm, S[ind2+2]-S[nbr]);
			}
			while(ind1<ind2){
				maxm = max(maxm, S[ind1+1]-S[ind1]);
				ind1++;
			}
			
		}else{
			sort(S+1, S+nbr, cmp);
			if(S[nbr-1]>=S[nbr]&&S[nbr-1]>=S[0]){
				printf("%lld\n", max(S[nbr-1]-S[nbr], S[1]-S[0]));
				continue;
			}
			if(S[1]<=S[nbr]&&S[1]<=S[0]){
				printf("%lld\n", max(S[nbr]-S[nbr-1], S[0]-S[1]));
				continue;
			}
			
			
			for(i=1; i<nbr; i++){
				if(S[i]<0){
					ind1 = i;
					break;
				}
			} 
			for(i=nbr-1; i>0; i--){
				if(S[i]>S[nbr+1]){
					ind2 = i;
					break;
				}
			}
			
			if(ind1==1) maxm = max(maxm, S[0]-S[ind1]);
			else if(ind1==2){
				maxm = max(maxm, S[1]-S[0]);
				maxm = max(maxm, S[1]-S[ind1]);
			}else{
				for(k=ind1-1; k>=3; k--){
					maxm = max(maxm, S[k-2]-S[k]);
				}
				maxm = max(maxm, -S[ind1]+S[ind1-1]);
				maxm = max(maxm, -S[0]+S[ind1-2]);
			}
			
			if(ind2==nbr-1) maxm = max(maxm, -S[nbr]+S[ind2]);
			else if(ind2 == nbr-2){
				maxm = max(maxm, -S[ind2+1]+S[ind2]);
				maxm = max(maxm, -S[ind2+1]+S[nbr]);
			}else{
				for(k=ind2+1; k<=nbr-3; k++){
					maxm = max(maxm, -S[k+2] + S[k]);
				}
				maxm = max(maxm, -S[ind2+1]+S[ind2]);
				maxm = max(maxm, -S[ind2+2]+S[nbr]);
			}
			while(ind1<ind2){
				maxm = max(maxm, -S[ind1+1]+S[ind1]);
				ind1++;
			}
			
			
		}
		
		printf("%lld\n", maxm); 
			
	}	
}

int main(){
	solve();
	return 0;
}

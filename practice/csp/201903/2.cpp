#include <bits/stdc++.h>
using namespace std;

string a;
int n;

int num[4];
char op[3];

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin>>a;

		for(int j=0; j<7; j++){
			if(j%2==0) num[j/2] = a[j]-'0';
			else op[j/2] = a[j];
		}

		int length=3;

		for(int j=0; j<length; j++){
			if(op[j]=='x' || op[j]=='/'){
				if(op[j]=='x'){
					num[j] = num[j]*num[j+1];
				}else if(op[j]=='/'){
					num[j] = num[j]/num[j+1];

				}
				for(int k=j+1; k<length; k++){
					num[k] = num[k+1];
					op[k-1] = op[k];
				}
				length--, j--;

			}

		}
		
		for(int j=0; j<length; j++){

			if(op[j]=='+'){
				num[j] = num[j]+num[j+1];
			}else if(op[j]=='-'){
				num[j] = num[j]-num[j+1];
			}
			for(int k=j+1; k<length; k++){
				num[k] = num[k+1];
				op[k-1] = op[k];
			}
			length--, j--;

		}
		
		
		if(num[0] == 24) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
	}
	return 0;
} 

#include<cstdio>
#include<iostream>
using namespace std;

const int MAX_N=104;
int m, n;
int a[MAX_N][MAX_N];
int x, y, step;
char dir;

void solve(){
	cin>>m>>n;
	for(int i=0; i<m ;i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	cin>>x>>y>>dir>>step;
	while(step--){
		if(a[x][y]==0){
			a[x][y]=1;
			if(dir=='L'){
				dir='D';
				x++;
			}
			else if(dir=='R'){
				dir='U';
				x--;
			}
			else if(dir=='U'){
				dir='L';
				y--;
			}
			else {
				dir='R';
				y++;
			}
		}else{
			a[x][y]=0; 
			if(dir=='L'){
				dir='U';
				x--;
			}
			else if(dir=='R'){
				dir='D';
				x++;
			}
			else if(dir=='U'){
				dir='R';
				y++;
			}
			else {
				dir='L';
				y--;
			}
		} 
	}
	cout<<x<<" "<<y<<endl;
}

int main(){
	solve();
	return 0;
} 

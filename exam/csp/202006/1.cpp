#include <bits/stdc++.h>
using namespace std;

int m, n;
int th1, th2, th3; 
const int MAXN=1e3+5;
struct node{
	int x, y, t;
}; 

node pts[MAXN];
char cls;

int cal(int p1, int p2, int p3, int x, int y){
	int rst = p1 + p2*x + p3*y;
	return rst; 
}

int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>pts[i].x>>pts[i].y;
		scanf(" %c", &cls);
		pts[i].t = cls-'A';
	}
	for(int i=1; i<=m; i++){
		bool ifyes = true;
		cin>>th1>>th2>>th3;
		int flag = (cal(th1, th2, th3, pts[1].x, pts[1].y) > 0) ^ pts[1].t;
		for(int j=2; j<=n; j++){
			int judge = (cal(th1, th2, th3, pts[j].x, pts[j].y) > 0) ^ pts[j].t;
			if(!(flag==judge)){
				cout<<"No"<<endl;
				ifyes = false;
				break;
			}	
		}
		if(ifyes)
			cout<<"Yes"<<endl;
	}
	return 0;
} 

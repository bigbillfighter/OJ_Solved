#include <bits/stdc++.h>
using namespace std;

struct node{
	int x, y;
	int cross, angle;
};

const int MAXN = 1e3+5;
node a[MAXN];

int n;
int num[5];

bool judgecross(int x1, int y1, int x2, int y2){
	if(y1==y2){
		if(x1==x2-1 || x1==x2+1) return true;
	}
	if(x1==x2){
		if(y1==y2-1 || y1==y2+1) return true;
	}
	return false;
}

bool judgeangle(int x1, int y1, int x2, int y2){
	if(abs(x1-x2)==1 && abs(y1-y2)==1) return true;
	return false;
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin>>a[i].x>>a[i].y;
		a[i].cross = a[i].angle = 0;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(judgecross(a[i].x, a[i].y, a[j].x, a[j].y)) a[i].cross++;
			if(judgeangle(a[i].x, a[i].y, a[j].x, a[j].y)) a[i].angle++;
		}
	}
	for(int i=1; i<=n; i++){
		if(a[i].cross==4) num[a[i].angle]++;
	}
	
	for(int i=0; i<5; i++){
		cout<<num[i]<<endl;
	}
	return 0;
} 

#include <iostream> 
#include <cstdio>
#include <queue>
using namespace std;

void solve(){
	queue<int> que;
	que.push(1);
	que.push(3);
	que.push(5);
	while(que.size()>0){
		printf("%d\n", que.front());
		que.pop();
	}
}

int main(){
	solve();
}

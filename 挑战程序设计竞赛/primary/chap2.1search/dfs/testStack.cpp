#include <iostream> 
#include <cstdio>
#include <stack>
using namespace std;

void solve(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	while(s.size()>0){
		printf("%d\n", s.top());
		s.pop();
	}
}

int main(){
	solve();
}

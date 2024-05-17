#include<iostream>
#include<cstdio>
#include<fstream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>

const int MAX=51000;
const int INF=10000000;
 
using namespace std;
 
int N;
int pos[MAX];
struct node{
	int b;
	int e;
	int p;
};
 
struct code{ 
	int po;
	int end;
};
 
bool cmp(node x, node y){
	return x.b < y.b;
}
 
struct comp{
	bool operator() (code c1, code c2){
		 // ">" ��ʾ end С�����ȼ���
        return c1.end > c2.end;
    }
};
 
node cow[MAX];
priority_queue <code, vector<code>, comp> que; 
 
//̰���㷨 
void Greedy(){
	//������� 
	int ans = 1;
	code a;
	a.po = ans;
	a.end = cow[0].e; 
	que.push(a);
	pos[cow[0].p] = ans;
	//Ϊţ����ţ�� 
	for(int i=1; i<N; i++){
		code a = que.top();
		//������в�������ʹ�� ����� ans++ 
		if(a.end >= cow[i].b){
			ans++;
			a.po = ans;
			a.end = cow[i].e; 
			que.push(a);
			pos[cow[i].p] = ans;
		}
		//����ʹ�ã����¶���  
		else{
			que.pop();
			pos[cow[i].p] = a.po;
			a.end = cow[i].e;
			que.push(a);
		}
	}	
	//���ans 
	cout << ans << endl;
	for(int i=0; i<N; i++)
		cout << pos[i] << endl;
}
 
//���Ժ��� 
int main(){

	cin >> N;
	for(int i=0; i<N; i++){
		cin >> cow[i].b >> cow[i].e;
		cow[i].p = i;
	}
		
	sort(cow, cow+N, cmp);
	Greedy();

	return 0;
}

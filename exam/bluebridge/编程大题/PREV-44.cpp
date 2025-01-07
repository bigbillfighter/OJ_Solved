#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <map>

using namespace std;
string st, ed;
int len;
struct node{
    string status;
    int step;
    node(string st, int sp){
        status = st;
        step = sp;
    }
};
map<string, bool> mp;
queue<node> qe;
int drt[6] = {-3, -2, -1, 1, 2, 3};

void bfs(){
    mp[st] = true;
    qe.push(node(st, 0));
    while(true){
        node nd = qe.front();
        for(int i=0; i<len; i++){
            if(nd.status[i]=='*'){
                for(int j=0; j<6; j++){
                    int direction = drt[j]+i;
                    if(direction>=0 && direction <len){
                        nd.status[i] = nd.status[direction];
                        nd.status[direction] = '*';
                        if(!mp[nd.status]){
                            if(nd.status==ed){
                                cout<<nd.step+1<<endl;
                                return;
                            }
                            mp[nd.status] = true;
                            qe.push(node(nd.status, nd.step+1));
                        }
                        nd.status[direction] = nd.status[i];
                        nd.status[i] = '*';
                    }
                }
            }
        }
        qe.pop();
    }

}

void solve(){
    cin>>st; cin>>ed;
    len = st.length();
    bfs();
}

int main(){
    solve();
    return 0;
}
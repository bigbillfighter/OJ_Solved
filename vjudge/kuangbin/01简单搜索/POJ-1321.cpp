#include <bits/stdc++.h>

using namespace std;

int n, k;
const int max_n = 9;
char cheer_box[max_n][max_n];
int visited[max_n][max_n];

void dfs(){
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    while(1){
        cin>>n>>k;
        if(n==-1 && k==-1){
            break;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cheer_box[i][j] = getchar();
            }
            getchar();
        }

        dfs();
    }

    return 0;
}
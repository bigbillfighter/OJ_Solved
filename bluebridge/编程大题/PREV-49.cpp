#include <cstdio>
#include <vector>
using namespace std;

const int MAX_N=100002;
int N;
int degrees[MAX_N];

vector<int> G[MAX_N];
int p;


int main(){
    scanf("%d", &N);
    int i;
    int v1, v2;
    for(i=1; i<=N ;i++) {
        scanf("%d %d", &v1, &v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
        degrees[v1]++; degrees[v2]++;
    }

//    for(i=1; i<=N; i++){
//        printf("%d ", degrees[i]);
//
//    }
    for(i=1; i<=N; i++){
        if(degrees[i]==1){
            p++;
        }
    }
    int j, k;

    while(p){
        for(i=1; i<=N; i++){
            if(degrees[i]==1){
                j=i;
                while(degrees[j]==1){
                    degrees[j]--;
                    p--;
                    degrees[G[j][0]]--;
                    if(degrees[G[j][0]]==1) {
                        j=G[j][k];
                        p++;
                    }
                }
            }
        }
    }

    for(i=1; i<=N ;i++){
        if(degrees[i]>0) printf("%d ", i);
    }

    return 0;
}
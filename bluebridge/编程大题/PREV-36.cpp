#include <cstdio>
#include <iostream>
using namespace std;

int N;
const int MAX_N=105;
int A[MAX_N]; //bz
const int MAX_NUM=1e4+5;
bool cb[MAX_NUM]; //if can combine
int mc = 0;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

void solve(){
    scanf("%d", &N);
    int i, j;
    cb[0] = true;
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
        if(i==0) mc=A[i];
        else mc = gcd(A[i], mc);
        for(j=1; j<MAX_NUM; j++){
            if(j-A[i]>=0){
                if(cb[j-A[i]]) {
                    cb[j] = true;
                }
            }
        }
    }
//    for(int i=0; i<N; i++){
//        printf("%d ", A[i]);
//    }

    if(mc!=1){
        cout<<"INF"<<endl;
        return;
    }
    int ans=0;
    for(int i=0; i<MAX_NUM; i++){
        if(!cb[i]) ans++;
    }
    cout<<ans<<endl;
}

int main(){
    solve();
    return 0;
}

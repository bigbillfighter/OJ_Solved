// sum of the first few numbers
#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N=1e5+5;
typedef long long LL;
int N, K;
LL ans=0;
int sum_from_first[MAX_N];
int times_mod[MAX_N];

void solve(){
    scanf("%d %d", &N, &K);
    int crt=0;
    int i;

    for(i=1; i<=N; i++){
        scanf("%d", &crt);
        sum_from_first[i] = (sum_from_first[i-1]+crt)%K;
        ans += times_mod[sum_from_first[i]]++;
    }

    ans += times_mod[sum_from_first[0]];
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}


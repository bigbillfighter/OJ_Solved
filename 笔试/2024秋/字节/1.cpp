#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    int n, k;
    while(T--){
        cin >> n >> k;
        LL times = (LL)n / k;
        cout << (LL)k * (1 + times) * times / 2 << endl;   
    }

    return 0;
}
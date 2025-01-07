#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;

    int a[4];
    
    int k;
    while(T--){
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        cin >> k;
        
        sort(a, a+4);
        while(k--){
            a[0] += 1;
            sort(a, a+4);
        }
        cout << a[0] * a[1] * a[2] * a[3] << endl;
    }

    return 0;
}
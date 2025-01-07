#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e5+5;
int a[max_n];

int crt_gcd(int a, int b){
    if(a%b == 0) return b;
    else return crt_gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    int n;
    int last, crt;
    int min_same;
    while(T--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        if(n == 2){
            cout << a[1] - a[0] << endl;
        }else{
            last = a[1] - a[0];
            crt = a[2] - a[1];
            min_same = crt_gcd(last, crt);
            for(int i=3; i<n; i++){
                min_same = crt_gcd(min_same, a[i]-a[i-1]);
            }
            cout << min_same << endl;
        }
    }
    
    return 0;
}
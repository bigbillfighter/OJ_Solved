#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans = 0;
    int crt = 0;
    int last = 0;
    int n, nbr;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> nbr;
        if(i==0){
            crt = 1;
            last = nbr;
            ans = max(ans, crt);
            continue;
        }

        if (abs(nbr-last) <= 1){
            crt ++;
        }else{
            crt = 1;
        }

        ans = max(ans, crt);
        last = nbr;
    }
    
    cout << ans << endl;
    return 0;
}
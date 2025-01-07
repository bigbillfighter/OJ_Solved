#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;

    LL a, b, c, x, y;
    while(T--){
        cin >> a >> b >> c >> x >> y;

        if(a >= b){
            if(b==c) cout << b << endl;
            else if(b>c){
                // a >= b, b > c
                LL tmp3 = ((a-c) + (b-c)*x) / (x*y+x+1);
                cout << c+tmp3 << endl;

            }else{
                // a >= b, b < c

                LL tmp4 = (a-b) / (1+x);
                if(tmp4 + b <= c){
                    cout << tmp4+b << endl;
                }else{
                    LL tmp5 = ((a-b) + (c-b)*x*y) / (x*y+x+1);
                    cout << b+tmp5 << endl;
                }

            }
        }else{
            if(c >= a){
                cout << a << endl;
            }else{
                // a < b, b > c, a > c
                LL tmp1 = (b-c) / (1+y);
                if(tmp1 + c >= a){
                    cout << a << endl;
                }else{
                    LL tmp2 = ((a-c) + (b-c)*x) / (x*y+x+1);
                    cout << c+tmp2 << endl;
                }
            }
        }
    
    }


    return 0;
}
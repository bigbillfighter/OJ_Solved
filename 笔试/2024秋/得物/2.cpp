#include<bits/stdc++.h>
using namespace std;

int my_gcd(int a, int b){
    if(a%b==0) return b;
    return my_gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d;
    int T; cin >> T;
    while(T--){
        cin >> a >> b >> c >> d;
        int ab = my_gcd(a, b), bc = my_gcd(b, c), cd = my_gcd(c, d), da = my_gcd(d, a);

        int temp1, temp2, temp3, temp4;
        do{
            temp1 = ab, temp2 = bc, temp3 = cd, temp4 = da;
            ab = my_gcd(ab, bc);
            bc = my_gcd(bc, cd);
            cd = my_gcd(cd, da);
            da = my_gcd(da, ab);
        }while(temp1!=ab || temp2!=bc || temp3!=cd || temp4!=da);

        int rst = min(temp1, temp2);
        rst = min(rst, temp3);
        rst = min(rst, temp4);

        if(rst == 1){
            cout << -1 << endl;
        }else{
            if(rst % 2==0){
                cout << 2 << endl;
            }else{
                for(int i=3; i<=rst; i+=2){
                    if(rst%i==0){
                        cout << i << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
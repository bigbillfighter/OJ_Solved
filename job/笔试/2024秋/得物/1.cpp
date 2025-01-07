#include<bits/stdc++.h>
using namespace std;

typedef long long LL;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string ss; cin >> ss;

    int rst = 1;

    int one=1, zero=0;
    int last_one=1, last_zero = stoi(ss.substr(2, 2));
    if(ss.size() == 5){
        cout << 1 << endl;
        return 0;
    }

    int times = ss.size() / 5;
    for(int i=1; i<times; i++){
        one = 1;
        zero = stoi(ss.substr(2+i*5, 2));

        last_one = (zero * last_one + one * last_zero) % 10007;
        last_zero = (zero * last_zero) % 10007;
    }

    return 0;
}
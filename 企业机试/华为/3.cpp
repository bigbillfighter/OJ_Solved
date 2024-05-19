#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 97 65 48
    // int s1='a', s2='A', s3='0';
    // cout << s1 << " " << s2 << " "<< s3 << endl;

    string ss;
    cin >> ss;
    int ans = 0;
    for(int i=2; i<ss.size(); i++){
        int base;
        if(ss[i]>'9'){
            base = 10 + ss[i] - 'A';
        }else{
            base = ss[i] - '0';
        }

        ans += base * pow(16, ss.size()-i-1);

    }
    cout << ans << endl;

    return 0;
}
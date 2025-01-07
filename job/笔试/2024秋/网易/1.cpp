#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    int n;

    string crt;
    string a, b;
    string rst;
    while(T--){
        cin >> n;
        vector<string> vss;

        for(int i=0; i<2*n-2; i++){
            cin >> crt;
            if(crt.size() == (n-1)) vss.push_back(crt);
        }

        a = vss[0], b = vss[1];

        if(a.size() == 1){
            if(a[0] == b[0]){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            int pre_flag = false;
            for(int i=1; i<=n-2; i++){
                if(a[i] != b[i-1]){
                    pre_flag = true;
                    break;
                }
            }

            if(pre_flag){
                rst = b + a[n-2];
            }else{
                rst = a + b[n-2];
            }

            int flag = true;
            for(int i=0; i<n/2; i++){
                if(rst[i] != rst[n-1-i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }

    }

    return 0;
}
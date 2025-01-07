#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e4+5;
int a[max_n], b[max_n];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    int n;

    bool flag = true;
    int pre, cur;
    while(T--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }

        flag = true;
        pre = min(a[0], b[0]);

        for(int i=1; i<n; i++){
            cur = min(a[i], b[i]);
            if(cur >= pre){
                pre = cur;
            }else{
                cur = max(a[i], b[i]);
                if(cur >= pre){
                    pre = cur;
                }else{
                    flag = false;
                    break;
                }
            }
        }

        if(flag){
            cout << "YES" << endl;
            continue;
        }

        flag = true;
        pre = max(a[0], b[0]);
        for(int i=1; i<n; i++){
            cur = max(a[i], b[i]);
            if(cur <= pre){
                pre = cur;
            }else{
                cur = min(a[i], b[i]);
                if(cur <= pre){
                    pre = cur;
                }else{
                    flag = false;
                    break;
                }
            }
        }


        if(flag){
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;

    }

    return 0;
}
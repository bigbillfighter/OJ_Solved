#include<bits/stdc++.h>
using namespace std;

const int max_n = 505;
int a[max_n];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    int ct, n, c;
    while(T--){
        cin >> ct >> n >> c;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a, a+n, greater<int>());

        int rst = ct - c;
        if(rst <= 0){
            cout << "YES" << endl;
            continue;
        }

        int accu = 0;
        int flag = false;
        for(int i=0; i<n; i++){
            accu = 0;
            flag = false;
            for(int j=i; j<n; j++){
                if(accu >=rst && accu <=ct){
                    flag = true;
                    break;
                }else if(accu + a[j]<= ct){
                    accu += a[j];
                }
                
            }

            if(flag){
                break;
            }
        }

        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
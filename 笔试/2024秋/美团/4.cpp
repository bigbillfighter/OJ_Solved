#include<bits/stdc++.h>
using namespace std;

const int max_n = 2e3+5;
int arr[max_n];

int my_gcd(int a, int b){
    if(a%b==0) return b;
    return my_gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    int n;
    while(T--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        if(n == 1){
            cout << 0 << endl;
            continue;
        }

        int flag = true;
        while(flag){
            int max_nbr = arr[0];
            for(int i=1; i<n; i++){
                max_nbr = max(max_nbr, arr[i]);
            }

            if(max_nbr < 0){
                cout << 0 << endl;
                break;
            }

            for(int i=0; i<n; i++){
                if(arr[i] > 0  && arr[i]!=max_nbr && my_gcd(max_nbr, arr[i]) != arr[i]){
                    flag = false;
                    break;
                }
            }

            if(!flag){
                int ans = 0;

                for(int i=0; i<n; i++){
                    if(arr[i] >0) ans ++;
                }
                cout << ans << endl;
                break;

            }else{
                for(int i=0; i<n; i++){
                    if(arr[i] == max_nbr) arr[i] = -1;
                }
            }
        }
    }


    return 0;
}
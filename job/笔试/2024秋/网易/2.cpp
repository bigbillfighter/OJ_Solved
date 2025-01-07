#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e4+5;
int piles[max_n];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    int n;

    int flag;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> piles[i];
        }
        flag = 1;
        int crt = 0;
        while(crt < n){
            if(piles[crt] == 1){
                if(flag) flag = 0;
                else flag = 1;
            }else{
                break;
            }
            crt ++;
        }

        if(crt == n){
            if(flag) flag = 0;
            else flag = 1;
        }


        if(flag){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; string str;
    cin >> n; cin >> str;
    int sum = 0;
    for(int i=0; i<n; i++){
        if(str[i] == '0'){
            sum += (n-i+1) / 2;
        }
    }

    cout << sum << endl;
    return 0;
}
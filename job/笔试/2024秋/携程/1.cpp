#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i=0; i<k-1; i++){
        cout << i+1 << " ";
    } 
    cout << n << " ";
    for(int i=n-1; i>=k; i--){
        cout << i << " ";
    
    }
    cout << endl;
    return 0;
}
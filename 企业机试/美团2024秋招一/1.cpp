#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int nbr;
    for(int i=0; i<n; i++){
        cin >> nbr; 
        if(nbr % 2 == 0) cout <<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
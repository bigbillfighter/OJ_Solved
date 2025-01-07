#include<bits/stdc++.h>
using namespace std;

typedef long long LL;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n; cin >> n;
    LL k; cin >> k;
    map<int, LL> nbr_times;
    
    int nbr;
    for(int i=0; i<n; i++){
        cin >> nbr; 
        if(nbr_times.count(nbr)){
            nbr_times[nbr] ++;
        }else{
            nbr_times[nbr] = 1;
        }
    }

    LL ans = 0;
    if(n==1){
        cout << 0 << endl;
        return 0;
    }

    int _key;
    for(map<int, LL>::iterator p = nbr_times.begin(); p!=nbr_times.end(); p++){
        _key = p->first;
        if((k^_key) == _key){
            if(nbr_times[_key] > 1) ans += nbr_times[_key] * (nbr_times[_key] - 1) / 2;
        }
        else if(nbr_times.count(k^_key)) ans += nbr_times[_key] * nbr_times[k^_key] / 2;
    }

    cout << ans << endl;

    return 0;
}
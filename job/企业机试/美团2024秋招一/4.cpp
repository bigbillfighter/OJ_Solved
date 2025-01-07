#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e5+5;
typedef long long ll;
ll a[max_n];

ll trace(ll ans, int* choices, int start, int end){
    ll tmp = -0x3f3f3f3f3f3f3f3f;
    
    do{
        int idx = start - 1;
        ll tp = ans;
        bool finished = false;

        for(int i = 0; i < 4; i++){
            if(idx+choices[i] <= end){
                tp += a[idx+choices[i]];
                if(tp < 0) break;
            }

            if(idx+choices[i] == end) {
                finished = true;
                tmp = max(tmp, tp);
                break;
            }
            idx += choices[i];
        }
    }while(next_permutation(choices, choices+4));

    return tmp;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    ll ans = 0;
    int times = (n-1) / 10 + 1;
    for(int i=0; i<times; i++){
        int choices[4] = {1, 2, 3, 4};

        ans = trace(ans, choices, i*10, min(i*10+10, n)-1);
        if(ans < 0){
            cout << -1 << endl;
            return 0;
        }

    }

    cout << ans << endl;

    return 0;
}
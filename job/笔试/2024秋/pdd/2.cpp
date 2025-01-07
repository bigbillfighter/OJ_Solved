#include<bits/stdc++.h>
using namespace std;


const int max_n = 2e5+5;
int a[max_n];
typedef long long LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    int n;
    LL sum;
    LL pair_sum;
    LL ans;
    while(t--){
        cin >> n;
        sum = 0;
        map<int, int> times;
        for(int i=0; i<n; i++){
            cin >> a[i];
            sum += a[i];
            if(times.count(a[i])){
                times[a[i]]++;
            }else{
                times[a[i]] = 1;
            }
        }
        if((2*sum) % n !=0){
            cout << 0 << endl;
        }else{
            pair_sum = (2*sum) / n;
            ans = 0;
            for(map<int, int>::iterator p = times.begin(); p!=times.end(); p++){
                if(times.count((int)(pair_sum - p->first))){
                    if(p->first == (int)(pair_sum - p->first)){
                        ans += p->second * (LL)(p->second - 1);
                    }else{
                        ans += p->second * (LL)times[(int)(pair_sum - p->first)];
                    }
                }
            }
            ans /= 2;
            cout << ans << endl;

        }
    }

    return 0;
}
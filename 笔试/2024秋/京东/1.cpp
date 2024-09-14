#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int max_n = 1e6+5;
LL pre_sum[max_n];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(pre_sum, 0, sizeof(pre_sum));
    int n; cin >> n;
    
    LL nbr; cin >> nbr; pre_sum[0]=nbr;
    for(int i=1; i<n; i++){
        cin >> nbr;
        pre_sum[i] = pre_sum[i-1] + nbr;
    }
    LL rst = pre_sum[0] * (pre_sum[n-1] - pre_sum[0]);

    for(int i=1; i<n-1; i++){
        rst = min(rst, pre_sum[i] * (pre_sum[n-1] - pre_sum[i]));
    }
    cout << rst << endl;


    return 0;
}
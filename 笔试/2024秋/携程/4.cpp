#include<bits/stdc++.h>
using namespace std;

const int max_n = 2e5+5;
int arr[max_n];
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    ll sum;
    cin >> n >> k; cin >> sum;

    memset(arr, 0, sizeof(arr));
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    ll pre_sum = 0;
    
    ll exc = 0;
    for(int i=0; i<k-1; i++){
        pre_sum += arr[i];
    }

    for(int i=k-1; i<n; i++){
        pre_sum += arr[i];
        if(pre_sum > sum){
            for(int j=i; j>=i-k+1; j--){
                if(arr[j] > 0){
                    if(arr[j] >= (pre_sum-sum)){
                        arr[j] -= (pre_sum-sum);
                        exc += pre_sum-sum;
                        pre_sum = sum;
                    }else{
                        exc += arr[j];
                        pre_sum -= arr[j];
                        arr[j] = 0;
                    }
                    if(pre_sum == sum) break;
                }
            }
        }
        pre_sum -= arr[i-k+1];
    }

    cout << exc << endl;
    return 0;
}
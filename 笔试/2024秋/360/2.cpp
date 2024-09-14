#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e5+5;
int height[max_n];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    int n;
    while(T--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> height[i];
        }
        if(n==1){
            cout << 1 << endl;
        }else{
            int idx = 1;
            while(idx < n && height[idx] > height[idx-1]){
                idx ++;
            }
            int ans = min(n, idx+1);
            int pre_len = ans-1;
            while(idx < n){
                int start_idx = idx;
                
                idx++;
                while(idx < n && height[idx] > height[idx-1]){
                    idx ++;
                }
                if(idx == start_idx+1){
                    ans = max(ans, 2);
                    pre_len = 1;
                    continue;
                }
                int cur_len = idx-start_idx;
                if(pre_len >=2 && height[start_idx] - height[start_idx-2]>=2){
                    ans = max(ans, pre_len+cur_len);
                }else if(cur_len>=2 && height[start_idx+1] - height[start_idx-1] >=2){
                    ans = max(ans, pre_len+cur_len);
                }else{
                    ans = max(ans, max(pre_len+1, cur_len+1));
                }
                pre_len = cur_len;
            }

            cout << ans << endl;
        }
    }
    
    return 0;
}
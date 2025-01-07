#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    vector<int> nums;
    cin >> n >> m >> k;
    map<int, bool> visited;

    for(int i=0; i<=n; i++){
        nums.push_back(i);
    }

    int sum = 0;

    // int k_level = 0;
    // int k_cp = k;
    // while(k_cp){
    //     k_level++;
    //     k_cp /= 10;
    // }

    // if(k == 0){
    //     cout << n << endl;
    //     return 0;
    // }

    do{
        int cur = 0;
        if(nums[0] == 0 && k!=1) continue;
        
        for(int i=0; i<m; i++){
            cur *=10;
            cur += nums[i];
        }
        if(!visited.count(cur)){
            visited[cur] = true;
            if(cur > k) sum++;
        }

    }while(next_permutation(nums.begin(), nums.end()));

    cout << sum << endl;

    return 0;
}
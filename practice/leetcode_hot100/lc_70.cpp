#include <bits/stdc++.h>
using namespace std;

int dp_arr[50];

int dp(int idx){
    if(dp_arr[idx] != 0) return dp_arr[idx];
    if(idx == 1) return dp_arr[1]=1;
    if(idx == 2) return dp_arr[2]=2;
    return dp_arr[idx] = dp(idx-2) + dp(idx-1);
}


class Solution {
public:
    int climbStairs(int n) {
        memset(dp_arr, 0, sizeof(dp_arr));
        return dp(n);
    }
};
#include <bits/stdc++.h>
using namespace std;

const int max_len = 205;
const int max_val = 10005;
int dp[max_len][max_val];

class Solution {
public:

    int dp_fun(int i, int j, vector<int>& nums){
        if(i < 0 || j < 0) return 0;

        dp[i][nums[i]] = 1;
        
        if(dp[i][j] > -1) return dp[i][j];

        int last_1 = dp_fun(i-1, j-nums[i], nums);
        if (last_1 == 1) return dp[i][j] = 1;
        return dp[i][j] = dp_fun(i-1, j, nums);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) sum += nums[i];
        if(nums.size() < 2 || sum % 2 !=0) return false;
        int target = sum / 2;

        for(int i=0; i<nums.size(); i++) for(int j=0; j<=target; j++) dp[i][j] = -1;
        for(int i=0; i <nums.size(); i++) dp[i][0] = 1;

        return dp_fun(nums.size()-1, target, nums) == 1;
    }
};
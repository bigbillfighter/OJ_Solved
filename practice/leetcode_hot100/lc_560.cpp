#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> cnt;
        int pre_sum = 0;
        cnt[0] = 1;
        for(int i=0; i<nums.size(); i++){
            if (cnt.count(pre_sum+nums[i] - k) > 0){
                ans += cnt[pre_sum+nums[i] - k];
            }
            pre_sum += nums[i];
            if(cnt.count(pre_sum) > 0){
                cnt[pre_sum] ++;
            }else{
                cnt[pre_sum] = 1;
            }
        }
        return ans;
    }
};
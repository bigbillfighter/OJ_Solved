#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        LL min_num = nums[0], max_num = nums[0], ans = nums[0];
        LL prev_min, prev_max;
        for(int i=1; i<nums.size(); i++){
            prev_min = min_num;
            prev_max = max_num;
            min_num = min(prev_min*nums[i], min(prev_max*nums[i], (LL)nums[i]));
            max_num = max(prev_min*nums[i], max(prev_max*nums[i], (LL)nums[i]));
            ans = max(ans, max_num);
        }
        return ans;
        
    }
};
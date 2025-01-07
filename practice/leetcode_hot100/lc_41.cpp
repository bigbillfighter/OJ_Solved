#include<bits/stdc++.h>
using namespace std;
 

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            while(nums[i] !=(i+1) && nums[i] > 0 && nums[i] <=n){
                int old_val = nums[nums[i]-1];
                if(old_val == nums[i]) break;
                nums[nums[i]-1] = nums[i];
                nums[i] = old_val;
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};
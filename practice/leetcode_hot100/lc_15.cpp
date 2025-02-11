#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int> > ans;
        int size = nums.size();
        for(int i=0; i<size-2; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int k = size - 1;
            for(int j=i+1; j<size-1; j++){
                if(nums[i] + nums[j] > 0) break;
                if(k <= j) break;
                if(j > (i+1) && nums[j] == nums[j-1]) continue;
                while(k > j && nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }
                if(k > j && nums[i] + nums[j] + nums[k] == 0){
                    if((k == size - 1) || nums[k] != nums[k+1]){
                        vector<int> part_ans = {nums[i], nums[j], nums[k]};
                        ans.push_back(part_ans);
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};
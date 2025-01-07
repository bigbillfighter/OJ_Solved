#include <bits/stdc++.h>
using namespace std;

void trace(vector<vector<int>>& rst, vector<int>& nums, int n, int crt){
    if(crt==n){
        rst.emplace_back(nums);
        return;
    }
    for(int j=crt; j<n; j++){
        swap(nums[j], nums[crt]);
        trace(rst, nums, n, crt+1);
        swap(nums[j], nums[crt]);
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n_num = nums.size();
        vector<vector<int>> rst;
        if(n_num==1){
            rst.emplace_back(nums);
            return rst;
        }
        trace(rst, nums, n_num, 0);
        return rst;
    }
};
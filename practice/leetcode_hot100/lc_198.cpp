#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int t1 = nums[0], t2 = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++){
            if(i%2 == 0){
                t1 = max(t2, t1+nums[i]);
            }else{
                t2 = max(t1, t2+nums[i]);
            }
        }
        return max(t1, t2);
    }
};
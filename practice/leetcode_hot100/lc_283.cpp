#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                nums[last++] = nums[i];
            }
        }

        for(; last<nums.size(); last++){
            nums[last] = 0;
        }
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last_idx = nums.size()-1;
        int farest = 0;
        for(int i=0; i<nums.size(); i++){
            if(i > farest) return false;
            farest = max(farest, i+nums[i]);
            if(farest >= last_idx) return true;
        }

        return false;

    }
};
#include <bits/stdc++.h>
using namespace std;

void swap_vec(vector<int>& nums, int start, int end){
    for(int i=start; i< (start + (end-start) / 2); i++){
        int swap = nums[end-(i-start)-1];
        nums[end-(i-start)-1] = nums[i];
        nums[i] = swap;
    } 
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int swap_size = k % nums.size();
        swap_vec(nums, 0, nums.size() - swap_size);
        swap_vec(nums, nums.size() - swap_size, nums.size());
        swap_vec(nums, 0, nums.size());
    }
};
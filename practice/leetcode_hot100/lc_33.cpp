#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search_with_bd(vector<int>& nums, int start_idx, int end_idx, int target){
        if(start_idx >= nums.size() || end_idx < 0) return -1;
        if(start_idx > end_idx) return -1;

        int middle_idx = (start_idx + end_idx) / 2;
        if(nums[middle_idx] == target) return middle_idx;
        if(nums[start_idx] == target) return start_idx;
        if(nums[end_idx] == target) return end_idx;

        if(nums[start_idx] < nums[middle_idx]){
            if(nums[middle_idx] > target){
                if(nums[start_idx] > target){
                    return search_with_bd(nums, middle_idx+1, end_idx, target);
                }else{
                    return search_with_bd(nums, start_idx, middle_idx-1, target);
                }
            }else{
                return search_with_bd(nums, middle_idx+1, end_idx, target);
            }
        }else{
            if(nums[middle_idx] > target){
                return search_with_bd(nums, start_idx, middle_idx-1, target);
            }else{
                if(nums[start_idx] > target){
                    return search_with_bd(nums, middle_idx+1, end_idx, target);
                }else{
                    return search_with_bd(nums, start_idx, middle_idx-1, target);
                }
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return search_with_bd(nums, 0, nums.size() -1, target);
    }
};
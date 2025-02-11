#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size() == 0){
            ans = {-1, -1};
            return ans;
        }

        int start = 0, end = nums.size()-1;
        int middle;
        bool flag = false;
        while(start <= end){
            middle = (start + end) / 2;
            if(nums[middle] == target) {
                flag = true; break;
            }else{
                if(nums[middle] < target) start = middle + 1;
                else end = middle-1;
            }
        }
        if(!flag){
            ans = {-1, -1};
            return ans;
        }

        int left_idx, right_idx;
        start = 0, end = nums.size()-1;
        while(true){
            middle = (start + end) / 2;
            if(nums[middle] < target){
                start = middle;
            }else {
                end = middle;
            }
            if(end - start <=1){
                if(nums[start] < target) left_idx = end;
                else left_idx = start;
                break;
            }
        }

        start = 0, end=nums.size()-1;
        while(true){
            middle = (start + end) / 2;
            if(nums[middle] > target){
                end = middle;
            }else {
                start = middle;
            }
            if(end - start <=1){
                if(nums[end] > target) right_idx = start;
                else right_idx = end;
                break;
            }
        }
        ans = {left_idx, right_idx};
        return ans;
    }
};
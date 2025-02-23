#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums, int start, int end, int ans){
        if(start >= nums.size() || end < 0 || start > end) return ans;

        int middle = (start + end ) / 2;
        ans = min(nums[start], ans);
        ans = min(nums[end], ans);
        ans = min(nums[middle], ans);
        
        if(nums[middle] > nums[start]){
            return findMin(nums, middle+1, end, ans);
        }else{
            return findMin(nums, start, middle-1, ans);
        }

    }

    int findMin(vector<int>& nums) {
        int ans = nums[0];
        return findMin(nums, 0, nums.size() - 1, ans);
    }
};
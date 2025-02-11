#include<bits/stdc++.h>
using namespace std;

int insert_place(vector<int>& nums, int& target, int start, int end){
    
    if(start >= end - 1){
        if(target <= nums[start]) return start;
        else return start+1;
    }

    if(nums[(start+end)/2] < target) return insert_place(nums, target, (start+end)/2, end);
    return insert_place(nums, target, start, (start+end)/2);
}


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return insert_place(nums, target, 0, nums.size());
    }
};
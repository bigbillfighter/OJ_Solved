#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int times = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==candidate) times++;
            else times --;
            if(times==0){
                candidate = nums[i];
                times = 1;
            }
        }
        return candidate;
    }
};
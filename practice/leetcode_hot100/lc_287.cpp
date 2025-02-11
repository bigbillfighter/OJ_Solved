#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int crt = i;
            int temp = nums[i];
            while(nums[crt] != crt+1){
                if(nums[nums[crt] - 1] == nums[crt]) return nums[crt];
                swap(nums[crt], nums[nums[crt]-1]);
            }
        }
        return nums.size() + 1;
    }
};
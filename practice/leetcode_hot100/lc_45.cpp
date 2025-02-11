#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int start=0, end=0;
        int cnt = 0;
        int new_start, new_end, target_idx;

        while(1){
            new_start = start;
            new_end = end;
            if(new_end >= nums.size()-1) return cnt;

            for(int i=start; i<=end; i++){
                if(i+nums[i] > new_end){
                    new_end = i+nums[i];
                    target_idx = i;
                }
            }
            
            start = end+1;
            end = new_end;
            cnt++;

        }

    }
};
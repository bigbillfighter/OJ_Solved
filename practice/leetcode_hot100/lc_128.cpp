#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int, bool> idxes;
        for(int i=0; i<nums.size(); i++) idxes[nums[i]] = true;
        
        int maxlen = 1;
        for(int i=0; i<nums.size(); i++){
            if(!idxes[nums[i]]) continue;
            int len = 1;
            idxes[nums[i]] = false;
            int start = nums[i];
            while(idxes.count(start-1) > 0 && idxes[start-1]){
                len++;
                start--;
                idxes[start] = false;
            }
            start = nums[i];
            while(idxes.count(start+1) > 0 && idxes[start+1]){
                len++;
                start++;
                idxes[start] = false;
            }
            maxlen = max(maxlen, len);
        }

        return maxlen;
    }
};
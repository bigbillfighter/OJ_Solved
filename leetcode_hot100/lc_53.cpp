#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first; 
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        priority_queue<pair<int, int>> right;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> left;

        int pre_sum = 0;
        for(int i=0; i<nums.size(); i++){
            pre_sum += nums[i];
            right.emplace(pre_sum, i);
        }

        left.emplace(0, -1);
        pre_sum = 0;
        int ans = nums[0];
        for(int i=0; i<nums.size(); i++){
            int left_sum=0, right_sum = 0;
            left_sum = left.top().first;
            while(right.top().second < i){
                right.pop();
            }
            right_sum = right.top().first;
            int cur_sum = right_sum - left_sum;
            ans = ans > cur_sum ? ans : cur_sum;
            pre_sum += nums[i];
            left.emplace(pre_sum, i);
        }
        return ans;
    }
};
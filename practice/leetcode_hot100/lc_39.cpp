#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void trace(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& crt, int sum, int crt_idx){  
        vector<int> to_add;  
        for(int i=crt_idx; i<candidates.size(); i++){
            sum += candidates[i];
            crt.push_back(candidates[i]);
            if(sum == target){
                to_add = crt;
                ans.push_back(to_add);
            }else if(sum < target){
                trace(candidates, target, ans, crt, sum, i);
            }
            sum -= candidates[i];
            crt.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> crt;
        trace(candidates, target, ans, crt, 0, 0);
        return ans;
    }
};
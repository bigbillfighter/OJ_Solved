#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt_map;
        for(int i=0; i<nums.size(); i++){
            if(!cnt_map.count(nums[i])){
                cnt_map[nums[i]] = 1;
            }else{
                cnt_map[nums[i]]++;
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(&cmp)> q(cmp);
        for(unordered_map<int, int>::iterator p=cnt_map.begin(); p!=cnt_map.end(); p++){
            if(q.size()==k){
                if(q.top().second < p->second){
                    q.pop();
                    q.emplace(p->first, p->second);
                }
            }else{
                q.emplace(p->first, p->second);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};
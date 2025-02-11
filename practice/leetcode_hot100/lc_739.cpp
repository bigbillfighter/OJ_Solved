#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int> > temp_index_array;
        temp_index_array.push(make_pair(temperatures[0], 0));
        
        vector<int> ans;
        for(int i=0; i<temperatures.size(); i++) ans.push_back(0);

        for(int i=1; i<temperatures.size(); i++){
            if(temperatures[i] > temp_index_array.top().first){
                while(!temp_index_array.empty() && temp_index_array.top().first< temperatures[i]){
                    ans[temp_index_array.top().second] = i - temp_index_array.top().second;
                    temp_index_array.pop();
                }
            }

            temp_index_array.push(make_pair(temperatures[i], i));
        }
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1) return heights[0];

        stack<int> idxes;
        int ans = 0;
        int _h, _w;
        
        for(int i=0; i<heights.size(); i++){

            while(!idxes.empty() && heights[i] < heights[idxes.top()]){
                _h = heights[idxes.top()];
                idxes.pop();

                if(idxes.empty()){
                    _w = i;
                }else{
                    _w = i - idxes.top() - 1;
                }
                ans = max(ans, _h * _w);
            }

            idxes.push(i);
        }

        int right = heights.size(), left;
        while(!idxes.empty()){
            if(idxes.size() == 1){
                _h = heights[idxes.top()];
                ans = max(ans, _h * right);
                idxes.pop();
            }else{
                _h = heights[idxes.top()];
                idxes.pop();
                left = idxes.top();
                _w = right - left - 1;
                ans = max(ans, _h * _w);
            }

        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

bool compareBySecond(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> rst;
        sort(intervals.begin(), intervals.end(), compareBySecond);
        if(intervals.size() == 1){
            rst.push_back(intervals[0]);
            return rst;
        }

        int pre_first = intervals[0][0], pre_second = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= pre_second){
                pre_second = max(pre_second, intervals[i][1]);
            }else{
                vector<int> temp = {pre_first, pre_second};
                rst.push_back(temp);
                pre_first = intervals[i][0],
                pre_second = intervals[i][1];
            }
        }
        vector<int> temp = {pre_first, pre_second};
        rst.push_back(temp);
        return rst;

    }
};
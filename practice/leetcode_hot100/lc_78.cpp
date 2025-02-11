#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<vector<int> > ans;

    void find_rst(vector<int>& nums, int crt, int size, vector<int> crt_arr){
        if(crt == size){
            ans.push_back(crt_arr);
            return;            
        }
        vector<int> first = crt_arr, second = crt_arr;
        first.push_back(nums[crt]);

        find_rst(nums, crt+1, size, first);
        find_rst(nums, crt+1, size, second);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int nbr = nums.size();
        vector<int> crt;
        find_rst(nums, 0, nbr, crt);
        return ans;
    }
};
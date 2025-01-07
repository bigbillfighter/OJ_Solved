#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e5+5;
int L[max_n], R[max_n];

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        fill(L, L+n, 1);
        fill(R, R+n, 1);

        for(int i=1; i<n; i++){
            L[i] = nums[i-1] * L[i-1];
        }
        for(int j=n-2; j>=0; j--){
            R[j] = R[j+1] * nums[j+1];
        }

        vector<int> rst;
        for(int i=0; i<n; i++){
            if(i==0) rst.push_back(R[i]);
            else if(i==(n-1)) rst.push_back(L[i]);
            else rst.push_back(L[i] * R[i]);
        }
        return rst;
    }
};
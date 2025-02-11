#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = prices[0];
        int ans = 0;
        for(int i=1; i<prices.size(); i++){
            ans = max(ans, prices[i] -min_val);
            min_val = min(min_val, prices[i]);
        }
        return ans;
    }
};
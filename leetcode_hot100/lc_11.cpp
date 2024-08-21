#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int rst = 0;

        while(i < j){
            int crt_area = (j-i)*min(height[i], height[j]);
            rst = rst < crt_area ? crt_area : rst;
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return rst;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param heights int整型vector 
     * @return int整型
     */
    int largestRectangleArea(vector<int>& heights) {
        // write code here
        
        int size = heights.size();
        if(size == 0) return 0;
        int left, right;
        int ans = 0;
        for(int i=0; i<size; i++){
            left = right = i;
            while(left >= 0 && heights[left] >= heights[i]) left--;
            while(right < size && heights[right] >= heights[i]) right ++;
            ans = max(ans, heights[i] * (right - left - 1));
        }
        return ans;
    }
};

int main(){
    Solution solu;
    int n; cin >> n;
    vector<int> heights;
    int nbr;
    for(int i=0; i<n; i++){
        cin >> nbr; heights.push_back(nbr);
    }
    cout << solu.largestRectangleArea(heights) << endl;

    return 0;
}
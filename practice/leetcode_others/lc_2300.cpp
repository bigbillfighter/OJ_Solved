#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

class Solution {
public:

    int bi_search(vector<int>& arr, int bs, long long success, int start, int end){
        if(end - start <= 2){
            if((LL)(arr[start]) * bs >= success) return start;
            else if((LL)(arr[end-1]) * bs >= success) return end-1;
            else return end;
        }

        int middle = (start + end ) / 2;
        
        if((LL)(arr[middle]) * bs < success){
            return bi_search(arr, bs, success, middle+1, end);
        }else{
            return bi_search(arr, bs, success, start, middle+1);
        }
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;

        int ssize = spells.size(), psize = potions.size();

        for(int i=0; i<ssize; i++){
            ans.push_back(psize - bi_search(potions, spells[i], success, 0, psize));
        }

        return ans;

    }
};
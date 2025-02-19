#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bsearch(int* arr, int start, int end, int target){
        if(start >= end-1) {
            if(arr[start] < target) return start+1;
            else return start;
        }
        
        int middle = (start + end) / 2;
        if(arr[middle] < target) return bsearch(arr, middle+1, end, target);
        else{
            if(arr[middle] == target) return middle;
            else{
                return bsearch(arr, start, middle, target);
            }
        }
    }

    int lengthOfLIS(vector<int>& nums) {
        int nlen = nums.size();
        
        int arr[nlen];
        int tsize = 0;
        arr[0] = nums[0];
        tsize++;

        int idx;
        for(int i=1; i<nlen; i++){
            if(nums[i] > arr[tsize-1]){
                arr[tsize] = nums[i];
                tsize++;
            }else{
                idx = bsearch(arr, 0, tsize, nums[i]);
                arr[idx] = nums[i];
            }
        }
        return tsize;
    }
};
#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:

//     void sortColors(vector<int>& nums) {
//         int zcount=0, ocount=0;
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i] == 0) zcount++;
//             else if(nums[i] == 1) ocount++;
//         }
//         for(int i=0; i<zcount; i++) nums[i] = 0;
//         for(int i=zcount; i<zcount+ocount; i++) nums[i] = 1;
//         for(int i=zcount+ocount; i<nums.size(); i++) nums[i] = 2;
//     }
// };

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0=0, p1=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                while(p0 <i && nums[p0] == 0) p0++;
                if(i!=p0){
                    if(p1 > p0){
                        nums[i] = nums[p1];
                        nums[p1] = nums[p0];
                        p1 ++ ;
                    }else{
                        nums[i] = nums[p0];
                    }
                    nums[p0] = 0; 
                }
                p0++;
            }else if(nums[i] == 1){
                while(p1 <i && nums[p1] <=1) p1++;
                if(i!=p1){
                    nums[i] = nums[p1];
                    nums[p1] = 1;
                }
                p1++;
            }
        }
        
    }
};
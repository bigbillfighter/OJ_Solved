#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         for(int i=0; i<nums.size(); i++){
//             int crt = i;
//             int temp = nums[i];
//             while(nums[crt] != crt+1){
//                 if(nums[nums[crt] - 1] == nums[crt]) return nums[crt];
//                 swap(nums[crt], nums[nums[crt]-1]);
//             }
//         }
//         return nums.size() + 1;
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

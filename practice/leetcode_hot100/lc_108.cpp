#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* find(vector<int>& nums, int left, int right){
        if(left == right){
            return nullptr;
        }else{
            TreeNode *p = new TreeNode(nums[(left+right)/2]);
            p->left = find(nums, left, (left+right)/2);
            p->right = find(nums, (left+right)/2+1, right);
            return p;
        }

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int num_nbr = nums.size();
        TreeNode *head = nullptr;
        if(num_nbr == 0) return head;
        head = new TreeNode(nums[num_nbr/2]);
        head->left = find(nums, 0, num_nbr/2);
        head->right = find(nums, num_nbr/2+1, num_nbr);  
        return head;      
    }
};
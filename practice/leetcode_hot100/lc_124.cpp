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

    int min_nbr = -0x3f3f3f3f;

    int find_max(TreeNode* root, int& max_num){
        if(root->left == nullptr && root->right == nullptr){
            max_num = max(root->val, max_num);
            return root->val;
        }

        int left_val=min_nbr, right_val=min_nbr;
        if(root->left != nullptr){
            left_val = find_max(root->left, max_num);
        }

        if(root->right != nullptr){
            right_val = find_max(root->right, max_num);
        }

        max_num = max(max_num, root->val);
        max_num = max(max_num, left_val + root->val);
        max_num = max(max_num, right_val + root->val);
        max_num = max(max_num, left_val + right_val + root->val);
        
        return max(root->val, max(left_val+root->val, right_val+root->val));
    }

    int maxPathSum(TreeNode* root) {
        int max_num = min_nbr;
        find_max(root, max_num);
        return max_num;
    }
};
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
    void trace_tree(TreeNode* part, vector<int> & ans){
        if(part == nullptr) return;
        trace_tree(part->left, ans);
        ans.push_back(part->val);
        trace_tree(part->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        trace_tree(root->left, ans);
        ans.push_back(root->val);
        trace_tree(root->right, ans);
        
        return ans;
    }
};
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
    void right_trace(TreeNode* root, vector<int>& ans, int& len, int& max_len){
        if(root == nullptr) return;
        if(len + 1 > max_len){
            ans.push_back(root->val);
        }
        len ++;
        max_len = max(len, max_len);
        right_trace(root->right, ans, len, max_len);
        right_trace(root->left, ans, len, max_len);
        len --;
    }

    vector<int> rightSideView(TreeNode* root) {
        int len = 0, max_len = 0;
        vector<int> ans;
        right_trace(root, ans, len, max_len);
        return ans;
    }
};
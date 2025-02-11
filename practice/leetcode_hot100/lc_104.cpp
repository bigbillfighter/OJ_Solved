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
    void find_ans(TreeNode* root, int ans, int& max_ans){
        if(root == nullptr) return;
        ans += 1;
        max_ans = max(ans, max_ans);
        find_ans(root->left, ans, max_ans);
        find_ans(root->right, ans, max_ans);
        // ans -- ;
    }

    int maxDepth(TreeNode* root) {
        int ans = 0, max_ans = 0;
        if(root == nullptr) return max_ans;
        find_ans(root, ans, max_ans);
        return max_ans;
    }
};
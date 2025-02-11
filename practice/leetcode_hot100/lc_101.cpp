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

bool is_sync(TreeNode* left, TreeNode* right){
    if(left==nullptr && right==nullptr) return true;
    if(left!=nullptr && right != nullptr){
        if (left->val != right->val){
            return false;
        }
        return is_sync(left->left, right->right) && is_sync(left->right, right->left);
    }
    return false;
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return is_sync(root->left, root->right);
    }
};
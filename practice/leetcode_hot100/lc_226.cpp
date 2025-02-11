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


void swap_tree(TreeNode* part){
    if(part == nullptr) return;
    TreeNode* temp = part->right;
    part->right = part->left;
    part->left = temp;
    swap_tree(part->left);
    swap_tree(part->right);
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        swap_tree(root);
        return root;
    }
};
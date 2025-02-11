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
    map<TreeNode*, pair<int, int> > val_map;

    bool find_valid(TreeNode* root){
        bool crt_left = true, crt_right = true;
        val_map[root] = make_pair(root->val, root->val);
        if(root->left == nullptr && root->right == nullptr){
            return true;
        }


        if(root->left !=nullptr) {
            crt_left = (root->left->val < root->val) && isValidBST(root->left);
            crt_left = crt_left && val_map[root->left].first < root->val;
            crt_left = crt_left && val_map[root->left].second < root->val;  
            if(crt_left){
                val_map[root].first = val_map[root->left].first;
            }          
        }
        if(root->right != nullptr) {
            crt_right = (root->right->val > root->val) && isValidBST(root->right);
            crt_right = crt_right && val_map[root->right].first > root->val;
            crt_right = crt_right && val_map[root->right].second > root->val;  
            if(crt_right){
                val_map[root].second = val_map[root->right].second;
            }   
        }
        return crt_left && crt_right;
    }

    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        return find_valid(root);
    }
};
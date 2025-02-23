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
    TreeNode* last_node(TreeNode* root){
        // if(root == nullptr) return nullptr;
        if(root->left == nullptr && root->right==nullptr) return root;
        if(root->right != nullptr) return last_node(root->right);
        return last_node(root->left);
    }

    void flatten(TreeNode* root) {
        TreeNode *last, *crt;
        crt = root;
        while(crt!=nullptr){
            if(crt->left != nullptr){
                last = last_node(crt->left);
                last -> right = crt->right;
                crt->right = crt->left;
                crt->left = nullptr;
            }
            crt = crt->right;
        }
    }
};
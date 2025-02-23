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
    vector<int> crt_state(TreeNode* root){
        if(root->left == nullptr && root -> right == nullptr){
            return {1, root->val, root->val};
        }

        int min_val=root->val, max_val=root->val;
        if(root->left != nullptr){
            vector<int> left_status = crt_state(root->left);
            if(!left_status[0]){
                return {0, -1, -1};
            }else{
                if(!(left_status[2] < root->val)){
                    return {0, -1, -1};
                }else{
                    min_val = left_status[1];
                }
            }
        }

        if(root->right != nullptr){
            vector<int> right_status = crt_state(root->right);
            if(!right_status[0]){
                return {0, -1, -1};
            }else{
                if(!(right_status[1] > root->val)){
                    return {0, -1, -1};
                }else{
                    max_val = right_status[2];
                }
            }
        }
        return {1, min_val, max_val};

    }

    bool isValidBST(TreeNode* root) {
        vector<int> rst = crt_state(root);
        return rst[0] == 1;
    }
};
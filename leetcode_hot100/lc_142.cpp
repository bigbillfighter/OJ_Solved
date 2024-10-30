#include<bits/stdc++.h>
using namespace std;


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
    int ans;

    int deepth(TreeNode *root){
        if(root == nullptr) return 0;
        int left_len = root->left == nullptr ? 0 : deepth(root->left) + 1;
        int right_len = root->right == nullptr ? 0 : deepth(root->right) + 1;
        ans = max(ans, left_len + right_len);
        return max(left_len, right_len);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        deepth(root);
        return ans;
    }
};
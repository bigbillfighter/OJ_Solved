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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rst;
        queue<TreeNode*> tq;
        tq.push(root);
        while(!tq.empty()){
            int layer_size = tq.size();
            vector<int> layer_rst;

            for(int i=0; i<layer_size; i++){
                TreeNode *node = tq.front();
                tq.pop();
                if(node!=nullptr){
                    layer_rst.push_back(node->val);
                    tq.push(node->left); tq.push(node->right);
                }
            }
            if(layer_rst.size() > 0) rst.push_back(layer_rst);
        }
        return rst;
    }
};
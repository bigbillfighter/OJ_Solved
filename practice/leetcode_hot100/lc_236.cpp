#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

const int min_nbr = -0x3f3f3f3f;
class Solution {
public:
    unordered_map<int, TreeNode*> node_map;
    unordered_map<int, int> father_nodes;

    void findChild(TreeNode* root){
        node_map[root->val] = root;
        if(root->left !=nullptr){
            father_nodes[root->left->val] = root->val;
            findChild(root->left);
        }
        if(root->right !=nullptr){
            father_nodes[root->right->val] = root->val;
            findChild(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findChild(root);
        unordered_map<int, int> fathers;
        fathers[p->val] = 1;

        int crt = p->val;
        while(father_nodes.count(crt)){
            crt = father_nodes[crt];
            fathers[crt] = 1;
        }

        crt = q->val;
        if(fathers.count(q->val)) return q;

        while(father_nodes.count(crt)){
            crt = father_nodes[crt];
            if(fathers.count(crt)) return node_map[crt];
        }

        return root;
    }
};
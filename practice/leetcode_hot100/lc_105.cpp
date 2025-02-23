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
    unordered_map<int, int> index;
    
    TreeNode* crt_build(vector<int>& preorder, vector<int>& inorder, int start_pre, int end_pre, int start_in, int end_in){
        if(end_pre-start_pre<=0) return nullptr;

        TreeNode* head = new TreeNode();
        head->val = preorder[start_pre];

        int idx = index[head->val];
        int left_len = idx - start_in;

        head->left = crt_build(preorder, inorder, start_pre+1, start_pre+1 + left_len, start_in, start_in + left_len);
        head->right = crt_build(preorder, inorder, start_pre+1 + left_len, end_pre, start_in + left_len+1, end_in);

        return head;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }

        return crt_build(preorder, inorder, 0, n, 0, n);
    }
};
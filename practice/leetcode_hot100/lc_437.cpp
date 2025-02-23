#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

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

    vector<LL> find_child(TreeNode* root, int targetSum){
        vector<LL> crt;
        if(root == nullptr) return crt;

        crt.push_back(root->val);
        if(root->val == (LL)targetSum) ans++;

        vector<LL> left_childs = find_child(root->left, targetSum);
        vector<LL> right_childs = find_child(root->right, targetSum);

        for(int i=0; i<left_childs.size(); i++){
            crt.push_back(left_childs[i] + root->val);
            if(left_childs[i] + root->val == (LL)targetSum) ans++;
        }
        for(int i=0; i<right_childs.size(); i++){
            crt.push_back(right_childs[i] + root->val);
            if(right_childs[i] + root->val == (LL)targetSum) ans++; 
        }

        // left_childs.clear(); right_childs.clear();
        return crt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        if(root == nullptr) return 0;

        if(root->val == (LL)targetSum) ans++;

        vector<LL> left_childs = find_child(root->left, targetSum);
        vector<LL> right_childs = find_child(root->right, targetSum);
        for(int i=0; i<left_childs.size(); i++){
            if(left_childs[i] + root->val == (LL)targetSum) ans++;
        }
        for(int i=0; i<right_childs.size(); i++){
            if(right_childs[i] + root->val == (LL)targetSum) ans++; 
        }

        return ans;
        
    }
};
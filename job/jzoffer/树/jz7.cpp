#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    TreeNode* build_tree(vector<int>& preOrder, vector<int>& vinOrder, int start, int end, int& prefix){
        if (start >= end){
            return nullptr;
        }
        
        int roo_val = preOrder[prefix++];
        TreeNode* root = new TreeNode(roo_val);

        int pre_index = start;
        while (vinOrder[pre_index] != roo_val && pre_index < end) {
            pre_index++;
        }
        root->left = build_tree(preOrder, vinOrder, start, pre_index, prefix);
        root->right = build_tree(preOrder, vinOrder, pre_index+1, end, prefix);

        return root;
        
    }

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param preOrder int整型vector 
     * @param vinOrder int整型vector 
     * @return TreeNode类
     */
    TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {
        int prefix = 0;
        return build_tree(preOrder, vinOrder, 0, preOrder.size(), prefix);
    }
};



int main(){
    // improve is speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;

    int length;
    cin >> length;
    vector<int> preOrder, vinOrder;
    
    int node_data;
    for(int i=0; i<length; i++){
        cin>>node_data;
        preOrder.push_back(node_data);
    }

    for(int i=0; i<length; i++){
        cin>>node_data;
        vinOrder.push_back(node_data);
    }


    TreeNode* rst = solu.reConstructBinaryTree(preOrder, vinOrder);
    cout << endl;

    return 0;
}